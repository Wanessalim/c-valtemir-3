#include <iostream>
#include <stdlib.h>
using namespace std;
//este é um codigo para listas ordenadas
struct Elemento{
	int Chave;
	Elemento* Prox;
};

struct Lista{ // estrutura que aponta pro primeiro item
	Elemento* Ini_Topo;
};

int Lista_Vazia(Lista *C){ // criando uma lista vazia qualquer p/ ref :)
	return C->Ini_Topo == NULL;
}

void Ini_Lista(Lista *C){
	C->Ini_Topo = NULL;
}
// criando elemento p/ lista
Elemento* Cria_Elemento( int num){
	Elemento* Pt = (Elemento*)malloc(sizeof(Elemento));
	if(Pt != NULL){
		Pt->Chave = num;
		Pt->Prox = NULL;
	}
	return Pt;
}
// começando a brincadeira de vdd
/*
1. lista está vazia?
	1.2 si: cria novo elemento e torna o primeiro
	1.3 se chave <= ao primeiro elemento
		1.3.1 insere no inicio(atualiza inicio)
	1.4 se nenhum caso desses
		1.4.1 caminhar até encontrar:
			elemento > chave
			pt->prox = null.
2. atualiza ponteiro
*/
Elemento* Insere_Ord(Lista *C, Elemento *Pt, int Chave){
	Elemento *Ret;
	
	if (Pt!=NULL){
		Ret = Pt;
		if ( Pt->Chave >= Chave ){ 					
			Ret = Cria_Elemento(Chave);
			if (Pt == C->Ini_Topo ){				 		
				Ret->Prox = C->Ini_Topo;
				C->Ini_Topo = Ret;	
			}
			else{
				Ret->Prox = Pt;					
			}
		}
		else{			
			Pt->Prox = Insere_Ord(C, Pt->Prox, Chave);
		}		
	}
	else{ 	
		Ret = Cria_Elemento(Chave);
		if (C->Ini_Topo==NULL){				 							
			Ret->Prox = C->Ini_Topo;
			C->Ini_Topo = Ret;			
		}	
	}
	return Ret; 
}

void Imprime(Elemento *Pt){
	if(Pt != NULL){
		cout << Pt->Chave << ", ";
		Imprime(Pt->Prox);
	}
	else{
		cout << endl;
	}
}


int main(){
	Lista L1;
	Elemento *Pt;
	
	Insere_Ord(&L1, L1.Ini_Topo, 10);
	Insere_Ord(&L1, L1.Ini_Topo, 3);
	Insere_Ord(&L1, L1.Ini_Topo, 5);
	Imprime(L1.Ini_Topo);
	
	return 0;
}
