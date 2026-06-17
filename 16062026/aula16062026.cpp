#include <iostream>
#include <string.h>

using namespace std;

struct NoArv{
	int Chave;
	char Num_Op[50];
	NoArv *Esq;
	NoArv *Dir;
};

struct Arvore{
	int Qtde;
	NoArv *Raiz;
};

void Ini_Arvore(Arvore *A){
	A->Qtde = 0;	
	A->Raiz = NULL;
}

NoArv * Cria_No(int Chave, const char *Num_Op){
	NoArv *Ret;
	
	Ret = (NoArv *) malloc(sizeof(NoArv));
	if (Ret != NULL){
		Ret->Chave = Chave;
		strcpy(Ret->Num_Op, Num_Op);
		Ret->Esq = NULL;
		Ret->Dir = NULL;
	}
	
	return Ret;
}

//Tipo: "E" (lado esquerdo), "D" (lado direito)
NoArv * Insere_Manual(Arvore *A, NoArv *Pai, int Chave, const char *Num_Op, string Tipo){	
	NoArv *Ret;
	
	Ret = Cria_No(Chave, Num_Op);
	if (Ret != NULL){
		if (A->Raiz == NULL) //cria a raiz!!
		{
			A->Raiz = Ret;
			A->Qtde++;	
		}
		else{ //cria um nó descendente
			if (Pai != NULL){
				if (Tipo == "E"){
					Pai->Esq = Ret;
				}
				else{
					Pai->Dir = Ret;
				}		
				A->Qtde++;			
			}
			else{
				cout << endl << "Pai não informado!!!";
			}
		}			
	}
	
	return Ret;
}

NoArv * Insere_Ord(Arvore *A,NoArv* No /*no guia*/ ,int Chave, const char *Num_Op){	
	NoArv *Ret;
	
	if (No != NULL){ //prcura nó
		if(Chave == No->Chave){ //no já existe
			Ret = NULL; //forço o null
		}else{
			Ret = No;
			if(Chave < No->Chave){
				No->Esq = Insere_Ord(A, No->Esq, Chave, Num_Op);
			}else{
				No->Dir = Insere_Ord(A, No->Dir, Chave, Num_Op);
			}
		}
					
	}else{ //neste ponto eu crio o no
		Ret = Cria_No(Chave, Num_Op);
		if (A->Raiz == NULL) {
			A->Raiz = Ret;	
		}
		A->Qtde++;
	}
	
	return Ret;
}


void Imprime(NoArv *No, string Tipo){
	if (No != NULL){
		if (Tipo == "PRE"){
			cout << No->Chave <<", ";
			//cout << No->Num_Op <<", ";
		}
				
		Imprime(No->Esq, Tipo);
		
		if (Tipo == "CEN"){
			cout << No->Chave <<", ";
			//cout << No->Num_Op <<", ";
		}
		
		Imprime(No->Dir, Tipo);
		
		if (Tipo == "POS"){
			cout << No->Chave <<", ";
			//cout << No->Num_Op <<", ";
		}
		
	}
}

struct ItemSentenca{ 
	float Valor;
	ItemSentenca *Prox;
};

struct Pilha{ 
	ItemSentenca *Topo;
	int Total;
};

void Ini_Pilha(Pilha *P){
	P->Topo = NULL;
	P->Total = 0;
}

ItemSentenca *Criar_Item(float Valor){
	ItemSentenca *ItemSent;

	ItemSent = (ItemSentenca *) malloc(sizeof(ItemSentenca));
	if (ItemSent != NULL){
		ItemSent->Valor = Valor;
		ItemSent->Prox = NULL;		
	}
	
	return ItemSent;
}

void Empilhar(Pilha *P, float Valor){	
	ItemSentenca *ItemSent;
	
	ItemSent = Criar_Item(Valor);
	if (ItemSent != NULL)
	{
		ItemSent->Prox = P->Topo;
		P->Topo = ItemSent;				
		P->Total++;
	}	
}

ItemSentenca* Desempilhar(Pilha *P){
	ItemSentenca* Ret;
	
	if (P->Topo == NULL){
		Ret = NULL; //Lista vazia
	}
	else{		
		Ret = P->Topo;		
		P->Topo = P->Topo->Prox;
		P->Total--;
	}
	
	return Ret;
}

int Operador(char* Valor){
	int Ret; 
	
	if ((strcmp(Valor, "*") == 0)  || (strcmp(Valor, "/") == 0) || (strcmp(Valor, "+") == 0) || (strcmp(Valor, "-") == 0)){
		Ret = 1;
	}
	else{		
		Ret = 0; //Não é operador!!
	}

	return Ret;
}

float Resolve_Expressao(float Num1, float Num2, char* Op){
	float Res;
	
	if (strcmp(Op, "*") == 0){
		Res = Num1 * Num2;
	}
	else{
		if (strcmp(Op, "/") == 0){
			Res = Num1 / Num2;
		}
		else{
			if (strcmp(Op, "+") == 0){
				Res = Num1 + Num2;
			}
			else{
				if (strcmp(Op, "-") == 0){
					Res = Num1 - Num2;
				}
				else{// <=
					Res = Num1 <= Num2;
				}
			}
		}
	}	
	
	return Res;
}

float CalcExpArvP(NoArv* NoArv, Pilha *P){
	float Res, Num1, Num2;
	ItemSentenca* Item;
	
	if (NoArv != NULL){	
		CalcExpArvP(NoArv->Esq, P);
		CalcExpArvP(NoArv->Dir, P);
		
		if (Operador(NoArv->Num_Op) == 0){ //Número
			Empilhar(P, stof(NoArv->Num_Op));
		}
		else{ //Operador
			Item = Desempilhar(P);
			Num2 = Item->Valor;
			Item = Desempilhar(P);
			Num1 = Item->Valor;
			
			Res = Resolve_Expressao(Num1, Num2, NoArv->Num_Op);
			Empilhar(P, Res);
		}
		
		Res = P->Topo->Valor;
	}
	return Res;
}


float CalcExpArv(NoArv* NoArv){
	float Res, Num1, Num2;
	ItemSentenca* Item;
	
	if (NoArv != NULL){	
		Num1 = CalcExpArv(NoArv->Esq);
		Num2 = CalcExpArv(NoArv->Dir);
		
		if (NoArv->Esq == NULL && NoArv->Dir == NULL){ //Nós folhas
			Res = stof(NoArv->Num_Op);
		}
		else{ //Operador
			Res = Resolve_Expressao(Num1, Num2, NoArv->Num_Op);
		}		
	}
	return Res;
}

int Altura(NoArv *No){
	int Ret, RetEsq, RetDir;
	
	if(No != NULL){
		
		RetEsq = 1 + Altura(No->Esq);
		RetDir = 1 + Altura(No->Dir);
		if(RetEsq >= RetDir){ //preferencia a esquerda
			Ret = RetEsq;
		}else{
			Ret = RetDir;
		}
		
	}else{
		Ret = -1; //inicialização correta
	}
	
	return Ret;
}


Arvore A;
Pilha P;
NoArv *Esq, *Esq2, *Dir;
int altura;
int main(){
	setlocale(LC_ALL, "Portuguese");
		
	Ini_Arvore(&A);
	
	Insere_Ord(&A, A.Raiz, 28, " ");
	Insere_Ord(&A, A.Raiz, 14, " ");
	Insere_Ord(&A, A.Raiz, 3, " "); //importancia do ret
	Insere_Ord(&A, A.Raiz, 33, " ");
	Insere_Ord(&A, A.Raiz, 17, " ");
	Insere_Ord(&A, A.Raiz, 19, " ");
	
	//Pré-Ordem: 1, 2, 4, 7, 10, 11, 3, 5, 6, 8, 12, 9
	Imprime(A.Raiz, "PRE");
	cout << endl;
	
	//In-Ordem ou Ordem Central: 
	//10, 7, 11, 4, 2, 1, 5, 3, 12, 8, 6, 9
	Imprime(A.Raiz, "CEN");
	cout << endl;
	
	//Pós-Ordem: 10, 11, 7, 4, 2, 5, 12, 8, 9, 6, 3, 1
	Imprime(A.Raiz, "POS");
	
	return 0;
}
