#include <iostream>
using namespace std;
/*
Multiplicação de dois números naturais, através de somas sucessivas (Ex.:6*4 =4 + 4 + 4 + 4 + 4 + 4).
*/
int Multiplicacao(int A, int B){
	int Mult;
	
	if(B > 0){
		Mult = A + Multiplicacao(A ,B - 1);
	}else{
		Mult = 0;
	}
	
	return Mult;
}

int M;
int main(){
	M = Multiplicacao(2, 7);
	cout<< M;
	return 0;
}
