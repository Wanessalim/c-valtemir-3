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

struct Pilha{ //Header/Cabe?alho
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

int Calc_Nivel(Arvore *A, NoArv *No, const char *Valor, int Nivel){
	int Ret=-1;
	if (No != NULL){
		if (No == A->Raiz){
			Nivel = 0;
		}
		
		if (strcmp(No->Num_Op, Valor) == 0){
			Ret = Nivel;
		}
		else{
			Ret = Calc_Nivel(A, No->Esq, Valor, Nivel + 1);
			if (Ret == -1){
				Ret = Calc_Nivel(A, No->Dir, Valor, Nivel + 1);
			}			
		}
	}
	
	return Ret;
}

int Altura(NoArv *No){
	int Ret, RetEsq, RetDir;
	
	if (No != NULL){		
		RetEsq = 1 + Altura(No->Esq);
		RetDir = 1 + Altura(No->Dir);
		if (RetEsq >= RetDir){
			Ret = RetEsq;
		}
		else{
			Ret = RetDir;
		}
	}
	else{
		Ret = -1;
	}
			
	return Ret;
}

NoArv * Insere_Ordenado(Arvore *A, NoArv *No, int Chave, const char *Num_Op){	
	NoArv *Ret;
		
	if (No != NULL){ //Procura o pai
		Ret = No; //Garante as ligações já existentes
		if (Chave < No->Chave){
			No->Esq = Insere_Ordenado(A, No->Esq, Chave, Num_Op);
		}
		else{
			if (Chave > No->Chave){
				No->Dir = Insere_Ordenado(A, No->Dir, Chave, Num_Op);			
			}
			else{
				//Erro!!!
			}
		}						
	}
	else{ //Cria o nó em uma nova ligação
		Ret = Cria_No(Chave, Num_Op);
		
		if (A->Raiz == NULL){ //cria a raiz!!
			A->Raiz = Ret;			
		}
		A->Qtde++;
	}
	
	return Ret;
}
/*
NoArv *Adiciona(NoArv *No,int Chave ){
	NoArv *Ret = NULL;
	if(No != NULL){
		if(Chave == No->Chave){
			Ret = No;
			cout<<"Achou";
		}else{
			if(Chave < No->Chave){
				Adiciona(No->Esq, Chave);
			}else{
				Adiciona(No->Dir, Chave);
			}
		}
	}
	return Ret;
}
*/

NoArv *Busca(NoArv *No,int Chave ){
	NoArv *Ret = NULL;
	if(No != NULL){
		if(Chave == No->Chave){
			Ret = No;
		}else{
			if(Chave < No->Chave){
				Ret = Busca(No->Esq, Chave); //guardar o ret
			}else{
				Ret = Busca(No->Dir, Chave);
			}
		}
	}
	return Ret;
}
//terminar de corrigir isso aqui.
NoArv *Adiciona(Arvore *A, NoArv *No, int Chave, const char *NumOp){ 
    NoArv *Ret = NULL; 
    
    if(No != NULL){ 
        if(Chave == No->Chave){ 
            Ret = No; 
            cout << "Item já existe: " << Chave; // Aspas adicionadas
        } else { 
            if(Chave < No->Chave){ 
                No->Esq = Adiciona(A, No->Esq, Chave, NumOp); 
                Ret = No; // Retorna o nó atual
            } else { 
                No->Dir = Adiciona(A, No->Dir, Chave, NumOp); 
                Ret = No; // Retorna o nó atual
            } 
        } 
    } else { 
        Ret = Cria_No(Chave, NumOp); 
        if(Ret != NULL){ 
            A->Qtde++; 
            if(A->Raiz == NULL){ 
                A->Raiz = Ret; 
            } 
        } 
    } 
    return Ret; 
}
/*
NoArv* Acha_Menor(NoArv* No){
	NoArv *Ret;
	if(No->Esq != NULL){
		Ret = Acha_Menor(No->Esq);
	}else{
		Ret = No;
	}
	return Ret;
}
*/


NoArv* Acha_Menor(NoArv* No) {
	NoArv *Ret;
    if (No == NULL) {
        Ret =  NULL; // Retorna NULL se a árvore ou subárvore estiver vazia
    }
    
    if (No->Esq != NULL) {
        Ret = Acha_Menor(No->Esq); // Continua descendo para a esquerda
    } else {
        Ret = No; // Chegou no menor nó (sem filho esquerdo)
    }
    return Ret;
}

NoArv* Remove(Arvore *A, NoArv *No, int Chave) {
    NoArv *Ret = NULL;
    if (No != NULL) {
        if (Chave == No->Chave) {
            // 1. Nó folha (sem filhos)
            if (No->Esq == NULL && No->Dir == NULL) {
                free(No);
                Ret = NULL;
            } 
            // 2. Nó com 1 filho (esquerda)
            else if (No->Dir == NULL) {
                Ret = No->Esq;
                free(No);
            } 
            // 3. Nó com 1 filho (direita)
            else if (No->Esq == NULL) {
                Ret = No->Dir;
                free(No);
            } 
            // 4. Nó com DOIS filhos
            else {
                // Encontra o menor nó da subárvore direita (sucessor)
                NoArv *sucessor = Acha_Menor(No->Dir);
                
                // Copia o valor da chave do sucessor para o nó atual
                No->Chave = sucessor->Chave;
                
                // Remove o sucessor da subárvore direita
                No->Dir = Remove(A, No->Dir, sucessor->Chave);
                Ret = No;
            }
        } else {
            Ret = No;
            if (Chave < No->Chave) {
                No->Esq = Remove(A, No->Esq, Chave); // Guarda o retorno
            } else {
                No->Dir = Remove(A, No->Dir, Chave);
            }
        }
    } else {
        cout << endl << "Item não encontrado" << endl;
    }
    return Ret;
}

Arvore A;
Pilha P;
NoArv *Esq, *Esq2, *Dir, *Ret;
int main(){
	setlocale(LC_ALL, "Portuguese");
		
	Ini_Arvore(&A);

	Adiciona(&A, A.Raiz, 24, "");
	Adiciona(&A, A.Raiz, 30, "");
	Adiciona(&A, A.Raiz, 37, "");
	Adiciona(&A, A.Raiz, 40, "");
	Adiciona(&A, A.Raiz, 21, "");
	Adiciona(&A, A.Raiz, 9, "");
	Imprime(A.Raiz, "CEN");			
	Remove(&A, A.Raiz, 24);
	cout<<endl;
	Imprime(A.Raiz, "CEN");
	
	
	return 0;
}
