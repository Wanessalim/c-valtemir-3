#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct NoArv{ 
	int Chave; 
	char Num_Op[50];
	NoArv *Esq;
	NoArv *Dir;
};

struct Arvore{ 
	int Quantidade;
	NoArv *Raiz;
};


void Ini_Arvore(Arvore *A){
	A->Quantidade = 0;
	A->Raiz = NULL;
}

NoArv *Cria_No(int Chave,const char *Num_Op){ 
	NoArv* Ret;
	Ret = (NoArv*) malloc(sizeof(NoArv));
	
	if(Ret != NULL){
		Ret->Chave = Chave;
		strcpy(Ret->Num_Op, Num_Op);
		Ret->Esq = NULL;
		Ret->Dir = NULL;
	} 
	
	return Ret;
}

NoArv *Insere_Manual(Arvore *A, NoArv *Pai, int Chave,const char *Num_Op, string Tipo){
	NoArv *Ret;

	Ret = Cria_No(Chave, Num_Op);
	
	if(Ret != NULL){
		if(A->Raiz == NULL){
			A->Raiz = Ret;
			A->Quantidade ++;
		}else{
			if(Pai != NULL){
				if(Tipo == "E"){
					Pai->Esq = Ret;
				}else{
					Pai->Dir = Ret;
				}
				A->Quantidade ++;
			}else{
				cout<< "Pai não informado"<<endl;
			}
		}
		
	}
	
	return Ret;
}


void Imprime(NoArv *No, string Tipo){
	if(No!= NULL){
		if(Tipo == "PRE"){
			cout<< No->Num_Op << ",";
		}
		Imprime(No->Esq, Tipo);
		if(Tipo == "CEN"){
			cout<< No->Num_Op << ",";
		}
		Imprime(No->Dir, Tipo);
		if(Tipo == "POS"){
			cout<< No->Num_Op << ",";
		}
		
	}
} 

Arvore A;
NoArv *Esq, *Dir, *Esq2;
int main(){
	Ini_Arvore(&A);
	Insere_Manual(&A, NULL, 0, "*", "");
	Insere_Manual(&A, A.Raiz, 0, "5", "E");
	
	Dir = Insere_Manual(&A, A.Raiz, 0, "+", "D");
	Esq = Insere_Manual(&A, Dir, 0, "*", "E");
	Insere_Manual(&A, Dir, 0, "7", "D");
	
	Esq2 = Insere_Manual(&A, Esq, 0, "+", "E");
	Insere_Manual(&A, Esq2, 0, "9", "E");
	Insere_Manual(&A, Esq2, 0, "8", "D");
	
	Dir = Insere_Manual(&A, Esq, 0, "*", "");
	
	Insere_Manual(&A, Dir, 0, "4", "E");
	Insere_Manual(&A, Dir, 0, "6", "D");
	
	Imprime(A.Raiz, "POS");

	return 0;
}
