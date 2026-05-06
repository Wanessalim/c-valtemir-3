#include <iostream>
#include <string.h>

// Este é um exemplo de programa em C++

using namespace std;

struct Elemento{
	int Chave;
	char Desc[30];
	float Valor;
	Elemento *Prox;
};

struct Cab{
	Elemento *Ini_Topo;
	Elemento *Fim;
	int Qtde_Total;
	float Valor_Total;
};

int Lista_Vazia(Cab *C){
	
	return C->Ini_Topo == NULL;
}

void Ini_Lista(Cab *C){
	C->Ini_Topo = NULL;
	C->Fim = NULL;
	C->Qtde_Total = 0;
	C->Valor_Total = 0;
}

Elemento* Cria_Elemento(int Chave, const char* Desc, float Valor){
	Elemento *Pt;

	Pt = (Elemento *) malloc(sizeof(Elemento));
	if (Pt != NULL){
		Pt->Chave = Chave;
		strcpy(Pt->Desc,Desc);
		Pt->Valor = Valor;	
		Pt->Prox = NULL;
	}
	
	return Pt;
}

//Lista
void Insere(Cab *C, int Chave, const char* Desc, float Valor){
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);
	
	//Insere na cabeça da lista
	Pt->Prox = C->Ini_Topo;	
	C->Ini_Topo = Pt;
	
	//Atualiza totais
	C->Qtde_Total++;
	C->Valor_Total += Valor;
}

Elemento* Remove(Cab *C, Elemento *Pt, int Chave){
	Elemento *Ret;
	int Atualiza_Totais;
	
	if (Pt!=NULL){
		Atualiza_Totais = 0;
		//CORREÇÃO na lógica dos condicionais
		if (Pt == C->Ini_Topo && Pt->Chave == Chave){ //Atualiza o início
			Ret = Pt;
			//Elimina o elemento
			C->Ini_Topo = C->Ini_Topo->Prox;

			//Atualiza totais
			Atualiza_Totais = 1;
		}
		else{					
			if (Pt->Prox!= NULL && Pt->Prox->Chave == Chave){ 	
				//cout << endl << "Elem Chave: " << Pt->Prox->Chave << " Chave: " << Chave << endl;
				Ret = Pt->Prox; 
				
				//Elimina o elemento
				Pt->Prox = Pt->Prox->Prox;			
				
				//Atualiza totais
				Atualiza_Totais = 1;
			}
			else{
				Ret = Remove(C, Pt->Prox, Chave);
			}
		}
		
		if (Atualiza_Totais){
			C->Qtde_Total--;
			C->Valor_Total -= Ret->Valor;
		}
	}
	
	return Ret; 
}

//Pilha 
//Inserção na pilha
void Push(Cab *C, int Chave, const char* Desc, float Valor){
	Insere(C, Chave, Desc, Valor);
}

//Remoção da pilha
Elemento* Pop(Cab* C){
	Elemento *Pt;
	
	//Se a pilha não estiver vazia, atualiza início
	if (!Lista_Vazia(C)){
		//Atualiza o início
		Pt = C->Ini_Topo;
		C->Ini_Topo = C->Ini_Topo->Prox;
		
		//Atualiza totais
		C->Qtde_Total--;
		C->Valor_Total -= Pt->Valor;
	}
	
	return Pt;
}

//Fila
//Inserção na fila
void Enqueue(Cab *C, int Chave, const char* Desc, float Valor){
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);	
	//Se a fila estiver vazia, atualiza cabeça
	if(Lista_Vazia(C)){
		C->Ini_Topo = Pt;			
	}
	else{ 
		C->Fim->Prox = Pt;
	}
	
	//Atualiza final da dila
	C->Fim = Pt;	
	
	//Atualiza totais
	C->Qtde_Total++;
	C->Valor_Total += Valor;
}

//Remoção da fila
Elemento* Dequeue(Cab* C){
	Elemento *Pt;
	
	//Se a pilha não estiver vazia, atualiza início
	if (!Lista_Vazia(C)){
		//Atualiza o início
		Pt = C->Ini_Topo;
		C->Ini_Topo = C->Ini_Topo->Prox;
		
		//Atualiza totais
		C->Qtde_Total--;
		C->Valor_Total -= Pt->Valor;
		
		if (C->Ini_Topo == NULL){
			//Inicializar fim novamente
			C->Fim=NULL;
		}
	}
	else{
		Pt = NULL; 
	}
	
	return Pt;
}

void Imprime(Elemento *Pt){
	if(Pt != NULL){
		if (Pt->Desc[0] == '$'){
			cout << Pt->Valor << " ";	
		}
		else{
			cout << Pt->Desc << " ";	
		} 
		
		Imprime(Pt->Prox);
	}
}

Elemento* Busca(Elemento *Pt, int Chave){
	Elemento* Ret=NULL;	
	
	if(Pt != NULL){
		if (Pt->Chave != Chave){
			Ret = Busca(Pt->Prox, Chave);	
		}
		else{
			Ret = Pt;		
		}		
	}
	
	return Ret;
}

/*
1 - Cadastra a expressão numa fila
2 - Loop para retirar elementos da Fila
	2.1 - Se El == "(", Push()
		  Senão
		  	Se El == ")"
		  		Se a pilha não estiver vazia
		  			Pop()
		  		Senão
		  			retorna Erro e para o loop;
3 - Se a pilha está vazia, expressão tá OK
	Senão, retorna Erro.
		  			
*/
int Processa_Parenteses(Cab *Fila){
	Cab Pilha;
	int Ret=1;
	Elemento *Item;
	
	Ini_Lista(&Pilha);
	while (Fila->Qtde_Total && Ret == 1){
		Item = Dequeue(Fila);
		if (Item->Desc[0] == '('){
			Push(&Pilha, 0, "(", 0);
		}
		else{
			if (Item->Desc[0] == ')'){
				if (!Lista_Vazia(&Pilha)){
					Item = Pop(&Pilha);
				}
				else{
					Ret = 0;
				}
					
			}
		}
	}
	
	if (Pilha.Qtde_Total > 0){ //Erro
		Ret = 0;
	}
	
	return Ret;
}
/*
2: * e /
1: + e -
0: <=
-1: Número
*/
int Calc_Precedencia(string Valor){
	int Ret = -1; //Não é operador!!
	
	if ((Valor == "*") || (Valor == "/") ){ //operador
		Ret = 2;	
	}
	else{
		if ( (Valor == "+") || (Valor == "-")){
			Ret = 1;
		}
		else{
			if (Valor == "<=" || Valor == ">=" || Valor == "=" ){ 
				Ret = 0;
			}
		}
	}

	return Ret;
}

float Resolve_Expressao(float Num1, float Num2, string Op){
	float Res;
	
	if (Op == "*"){
		Res = Num1 * Num2;
	}
	else{
		if (Op == "/"){
			Res = Num1 / Num2;
		}
		else{
			if (Op == "+"){
				Res = Num1 + Num2;
			}
			else{
				if (Op == "-"){
					Res = Num1 - Num2;
				}
				else{// <=
					if (Op == "<="){
						Res = Num1 <= Num2;
					}
					else{
						if (Op == ">="){
							Res = Num1 >= Num2;
						}	
						else{
							Res = Num1 == Num2;
						}
					}
				}
			}
		}
	}	
	
	return Res;
}

void Resolve_Pilhas(Cab *Pilha_Num, Cab *Pilha_Op){
	string Op;
	float Num1, Num2, Res;
	Elemento* Item;
	
	//Desempilha os números
	Item = Pop(Pilha_Num);
	Num2 = Item->Valor; 
	Item = Pop(Pilha_Num);
	Num1 = Item->Valor; 
	
	//Desempilha o operador
	Item = Pop(Pilha_Op);
	Op = Item->Desc; 
	Res = Resolve_Expressao(Num1, Num2, Op);
	
	//Atualiza a pilha de números
	Push(Pilha_Num,0, "$", Res);
}


/*
1. Loop para retirar elementos da fila ou da pilha
	1.1 Se tem fila, pega o elemento da fila
		Senão loop para processar Pilha

*/
int Calc_Expressao(Cab *F, float *ValRet){
	int Ret = -1;
	int Prec, FlagRepete;
	string Res;
	Cab Pilha_Num, Pilha_Op;
	Elemento* Item;
	
	if (!Lista_Vazia(F)){
		Ini_Lista(&Pilha_Num);
		Ini_Lista(&Pilha_Op);
		
		do{		
			Item = Dequeue(F);
			if (Item != NULL){ //Fila
				if (Item->Desc[0] == '$'){ //Número
					Push(&Pilha_Num, 0, "$",Item->Valor);
				}
				else{ //Operador
					//1 - Se a pilha tá vazia, empilha
					//2 - Se o operador da fila tem precedência maior que
					//    o operador da pilha, empilha
					//	  Senão fazer a baixa simples da pilha	
					do{		
						//cout << endl << "Verificando..."<< endl;
						//system("pause");			
						if (Lista_Vazia(&Pilha_Op) == 1 || 
							Calc_Precedencia(Item->Desc) > Calc_Precedencia(Pilha_Op.Ini_Topo->Desc)){
							//cout << endl << "Op fila entra na pilha..."<< endl;
							//system("pause");											
							Push(&Pilha_Op, 0, Item->Desc ,0);							
							FlagRepete = 0;
						}
						else{
							//cout << endl << "Resolve pilha com fila..."<< endl;
							//system("pause");
						   	Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
						   	FlagRepete = 1;
						}									
					}while (FlagRepete == 1);
				
				}
			}
			else{ //Pilha
				//cout << endl << "Resolve pilha sem fila..."<< endl;
				//system("pause");

				Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
			}
			/*cout << endl;
			Imprime(Pilha_Num.Ini_Topo);
			cout << endl;
			Imprime(Pilha_Op.Ini_Topo);
			system("pause");*/
		}while(F->Qtde_Total > 0 || Pilha_Op.Qtde_Total > 0 );
		*ValRet = Pilha_Num.Ini_Topo->Valor;
		Ret = 1;
	}
	
	return Ret;
}
	
Cab Fila;
Elemento *Pt;
int Ret;
float Valor;
int main () {
	setlocale (LC_ALL,"Portuguese");
	
	Ini_Lista(&Fila);
	
	// 14 <= 4 - 3 * 2 + 7
	Enqueue(&Fila, 0, "$", 14);
	Enqueue(&Fila, 0, ">=", 0);
	Enqueue(&Fila, 0, "$", 4);
	Enqueue(&Fila, 0, "-", 0);
	Enqueue(&Fila, 0, "$", 3);
	Enqueue(&Fila, 0, "*", 0);
	Enqueue(&Fila, 0, "$", 2);
	Enqueue(&Fila, 0, "+", 0);
	Enqueue(&Fila, 0, "$", 7);
	
	Imprime(Fila.Ini_Topo);
	
	Ret = Calc_Expressao(&Fila, &Valor);
	if (Ret){
		cout << endl << "Resultado: " << Valor;
	}

	return 0;
}
