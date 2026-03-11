#include <iostream> //GNU C++11
#include <stdlib.h> //função malloc tá aqui
#include <string.h>
using namespace std;
//alocação de memoria

int * Aloca_Vetor(int N){
	int * PtV;

	if(N < 0){
		PtV = NULL;
	}else{
		PtV = (int *) malloc(sizeof(int)*N);
	}
	return PtV;
}

void LerVetor(int V[], int N){
	int Cont;
	
	for(Cont = 0; Cont < N; Cont++){
		cout<<"V["<<Cont<<"]: ";
		cin>>V[Cont];
	}
}

void ImprimirVetor(int V[], int N){
	int Cont;
	for(Cont = 0; Cont< N; Cont++){
		cout<<"V["<<Cont<<"]: "<<V[Cont]<<endl;
	}
}

struct Contato{
	int Id;
	char Nome[40];
};
//primeiro exercicio.
/*
Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
igual a zero, um ponteiro nulo deverá ser retornado
*/


int *PtX, *Pt; //este X, é uma alocação estatíca.
Contato *PtC;
int main(){
	setlocale(LC_ALL,"Portuguese");
	PtX = (int*) malloc(sizeof(int));
	*PtX = 4;
	free(PtX); //liberei a memoria pro sistema/ qualquer outra coisa
	//cout<<*PtX;
	//cout<< ((float) 5)/2; //mudando 5 para float.
	//malloc não funciona com tipo string

	
	PtC = (Contato *) malloc(sizeof(Contato));
	if(PtC != NULL){//não esquecer!!!
		PtC->Id = 12; // ou (*PtC).Id -> (pouco usual)
		strcpy(PtC->Nome, "Pedro");
		cout<<"Id: "<< PtC->Id<<endl;
		cout<<"Nome: "<< PtC->Nome;
		cout<<endl;
	}
	
	Pt = Aloca_Vetor(5);
	if(Pt != NULL){
		LerVetor(Pt, 5);
		cout<<endl;
		ImprimirVetor(Pt, 5);
	}
	
	return 0;
}
