#include <iostream>
using namespace std;
/*
Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho
N cada. A função deve retornar o ponteiro para um vetor C de tamanho N alocado
dinamicamente, em que C[i] = A[i] + B[i].
*/

//N =5

int * SomaVetores(int* A, int* B, int N){
	int* C;
	int Cont;
	C = (int*)malloc(sizeof(int)*N);
	if(C != NULL){
		for(Cont = 0; Cont < N; Cont++){
			C[Cont] = A[Cont] + B[Cont];
		}
	}
	return C;
}

void ImprimeVetor(int* Vet, int N){
	int Cont;
	for(Cont = 0; Cont < N; Cont++){
		cout<<"Item "<<Cont<< ": "<<Vet[Cont]<<endl;
	}
}

int A[] = {1, 2, 3, 4, 5};
int B[] = {5, 4, 3, 2, 1};
int *Vetor;
int N = 5;
int main(){
	setlocale(LC_ALL, "Portuguese");
	Vetor =	SomaVetores(A, B, N);
	ImprimeVetor(Vetor, N);
	return 0;
}
