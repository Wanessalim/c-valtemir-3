#include <iostream>
using namespace std;
//Impressão de um número natural em base binária.
/*
resto1 = 30% 2 
retorna resto1
resto2 = resto2 % 2
retorna resto1 resto2 ...
*/
void BaseBinaria(int N){
	if(N > 0){
		BaseBinaria(N/2);
		cout<< N % 2;
	}else{
		cout << 0;
	}
}
//faze com retorno
void Binario(int Dec){
	int Quociente;		
	Quociente = Dec/2;		
	if (Quociente != 0){
		Binario(Quociente);

	}
	cout << Dec%2;
}

// Outra forma

string conv_bin(int Num){
	string Res="";
	if (Num > 0){
		Res = conv_bin(Num/2) + to_string(Num%2);
	}		
	return Res;	
}

int main(){
	BaseBinaria(0);
	cout<<endl;
	Binario(0);
	return 0;
}
