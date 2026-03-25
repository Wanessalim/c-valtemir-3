#include <iostream>
using namespace std;
/*
Multiplicação de dois números naturais
através de incrementos sucessivos.
*/
//misturar 2 e 3
int Incremento(int Valor, int Vezes){
	int Ret;
	if(Vezes == 0){
		Ret = 0;
	}else{
		Ret = 1 + Incremento(Valor, Vezes - 1);
	}
	return Ret;
}

int MultiIncremento(int A, int B){
	int Ret;
	if(B == 0){
		Ret = 0;
	}else{
		
		Ret = Incremento(A, A) + MultiIncremento(A, B - 1);
	}
	return Ret;	
}

int T;
int main(){
	T = MultiIncremento(3 , 4);
	cout << T;
	return 0;
}
