#include <iostream>
#include <string.h>
using namespace std;

struct Elemento{ 
	char Op_Num[10];
	float Valor;
	Elemento *Prox;
};

struct Fila{
	Elemento* Inicio;
	Elemento* Fim;
	int Qtde_Total;
};

struct Pilha{
	Elemento* Topo;
	int Qtde_Total;
};

void Ini_Pilha(Pilha* P){
	P->Topo = NULL;
	P->Qtde_Total = 0;
}

int Pilha_Vazia(Pilha* P){
	return P->Topo == NULL; //vdd = 1, se fake = 0
}

int Fila_Vazia(Fila* F){
	return F->Inicio == NULL;
}

void Ini_Fila(Fila* F){
	F->Inicio = NULL;
	F->Fim = NULL;
	F->Qtde_Total = 0;
}

Elemento * Cria_Item(const char* Op, float Valor){
	Elemento *Pt;
	
	Pt = (Elemento *) malloc(sizeof(Elemento));
	if (Pt != NULL){ 
		strcpy(Pt->Op_Num, Op);
		Pt->Valor = Valor; 
		Pt->Prox = NULL;	
	}
	
	return Pt;
}



Elemento * Enqueue(Fila* F, const char* Op, float Valor){ 
	Elemento *Pt;
	
	Pt = Cria_Item(Op, Valor);
	if(Pt != NULL){
		if(Fila_Vazia(F)){ 
			F->Inicio = Pt; 
		}else{ 
			F->Fim->Prox = Pt; 
		}
		F->Fim = Pt; 
		++F->Qtde_Total;
	}
	
	return Pt;
}

Elemento * Push(Pilha* P, const char* Op, float Valor){ //Empilhar
	Elemento *Pt;
	
	Pt = Cria_Item(Op, Valor);
	if(Pt != NULL){
		Pt->Prox = P->Topo; //"Eu aponto pro elemento antigo"
		P->Topo = Pt;//"e o topo aponta pra mim"
	}
	
	return Pt;
}

Elemento * Dequeue(Fila* F){ 
	Elemento *Pt;

	if(!Fila_Vazia(F)){
		
		Pt = F->Inicio; 
		F->Inicio = F->Inicio->Prox;
		if(F->Inicio == NULL){
			F->Fim = F->Inicio;
		}
		--F->Qtde_Total;
	}else{
		Pt = NULL;
	}
	
	return Pt;
}

Elemento * Pop(Pilha* P){
	Elemento* Pt;
	if(!Pilha_Vazia(P)){ //Se lista não está vazia
		//retira item do topo
		Pt = P->Topo;
		P->Topo = P->Topo->Prox;
	}else{ // se a lista têm apenas um item retorna lista null
		Pt = NULL;
	}
	
	
	return Pt;
}

void Imprime(Elemento *Pt, char Tipo){
	if(Pt != NULL){
		if (Tipo == 'P'){
			cout << Pt->Valor << " ";	
		}
		else{
			cout << Pt->Op_Num << " ";	
		} 
		
		Imprime(Pt->Prox, Tipo);
	}
}

/*
2: * e /
1: + e -
0: <=, <=, =, !=, < ou >
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
			if (Valor == "<=" || Valor == "<=" || Valor == "=" ){ 
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
						Res = (Num1 <= Num2) ;
					}
					else{
						if (Op == ">="){
							Res = (Num1 >= Num2);
						}	
						else{
							Res = (Num1 == Num2) ;
						}
					}
				}
			}
		}
	}	
	
	return Res;
}

void Resolve_Pilhas(Pilha *Pilha_Num, Pilha *Pilha_Op){
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
	Op = Item->Op_Num; 
	Res = Resolve_Expressao(Num1, Num2, Op);
	
	//Atualiza a pilha de números
	Push(Pilha_Num, "$", Res);
}

/*
1. Loop para retirar elementos da fila ou da pilha
	1.1 Se tem fila, pega o elemento da fila
		Senão loop para processar Pilha

*/
int Calc_Expressao(Fila *F, float *ValRet){
	int Ret = -1;
	int Prec_Fila, FlagRepete;
	string Res;
	Pilha Pilha_Num, Pilha_Op;
	Elemento* Item;
	
	if (!Fila_Vazia(F)){ //processa so se tiver fila.
	Ini_Pilha(&Pilha_Num);
	Ini_Pilha(&Pilha_Op);
		
	}
	
	do{
		Item = Dequeue(F); //tirei item da fila
		if(Item != NULL){ //fila
		
			Prec_Fila = Calc_Precedencia(Item->Op_Num);
			if(Prec_Fila == - 1){ //Número
					Push(&Pilha_Num,"$",Item->Valor);
					
				}else{ //operador
					//1 - Se a pilha tá vazia, empilha
					//2 - Se o operador da fila tem precedência maior que
					//    o operador da pilha, empilha
					//	  Senão fazer a baixa simples da pilha	
					do{				
						if ((Pilha_Op.Topo == NULL) || 
							(Prec_Fila > Calc_Precedencia(Pilha_Op.Topo->Op_Num) )){
						
															
							Push(&Pilha_Op, Item->Op_Num ,0);							
							FlagRepete = 0;
						}
						else{
						
						   	Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
						   	FlagRepete = 1;
						}									
					}while (FlagRepete == 1);
					
					
				
				}
			
			
			
		}else{ //a fila acabou
			Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
		}
		
		
		
		
	}while(F->Qtde_Total > 0 || Pilha_Op.Qtde_Total > 0 ); //enquanto tiver fila ou pilha de operadores ele repete
	
	*ValRet = Pilha_Num.Topo->Valor;
	Ret = 1;
	return Ret;
}

Fila F;
float Valor;
int Ret;
int main(){
	setlocale (LC_ALL,"Portuguese");
	Ini_Fila(&F);
	
	//Enqueue(&F, "14", 14);
	//Enqueue(&F, "<=", 0);
	//Enqueue(&F, "4", 4);
	//Enqueue(&F, "-", 0);
	Enqueue(&F, "3", 3);
	Enqueue(&F, "*", 0);
	Enqueue(&F, "2", 2);
	Enqueue(&F, "+", 0);
	Enqueue(&F, "7", 7);
	
	Imprime(F.Inicio, 'F');
	
	Ret = Calc_Expressao(&F, &Valor);
	if (Ret){
		cout << endl << "Resultado: " << Valor;
	}
	
	return 0;
}
