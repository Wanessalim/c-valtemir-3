#include <iostream>
using namespace std;
/*
Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
igual a zero, um ponteiro nulo deverá ser retornado
*/

int * Aloca_Vetor(int N){
	int *P;	
	if (N > 0){
		P = (int *) malloc(sizeof(int)*N);
	} 	
	else{
		P = NULL;
	}
 	return P;
}

int Num = 5;
int main(){
	setlocale(LC_ALL, "Portuguese");
	// esta funfando
	
	int* Vetor = Aloca_Vetor(Num);
	if(Vetor != NULL){
		for(int Cont = 0; Cont < Num; Cont++){	
			cout<<"Insira valor "<<Cont<<": ";
			cin>>Vetor[Cont];
		}	
	}

	
	return 0;
}
