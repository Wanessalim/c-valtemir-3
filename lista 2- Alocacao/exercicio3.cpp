#include <iostream>
using namespace std;

int *AlocaVetor(int N){
	int *V;
	V = (int*)malloc(sizeof(int)*N);
	return V;
}

void InsereVetor(int* Vet, int N){
	int Cont;
	for(Cont = 0; Cont < N; Cont++){
		do{
			cout<<"Insira valor "<< Cont<<": ";
			cin>>Vet[Cont];
			if(Vet[Cont] < 2){
				cout<<"Insira um valor igual ou maior que 2"<<endl;
			}
		}while(Vet[Cont] < 2);
	}
}

void ImprimeVetor(int* Vet, int N){
	int Cont;
	for(Cont = 0; Cont < N; Cont++){
		cout<<"Item "<<Cont<< ": "<<Vet[Cont]<<endl;
	}
}

int N, *Vet;
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	do {
    	cout << "Digite um valor positivo para N: ";
    	cin >> N;
    
    	if (N <= 0) {
    	    cout << "Valor inválido! Tente novamente." << endl;
    	}
	} while (N <= 0);
	
	Vet = AlocaVetor(N);
	cout<<endl;
	InsereVetor(Vet, N);
	cout<<endl;
	ImprimeVetor(Vet, N);
	
	
	return 0;
}
