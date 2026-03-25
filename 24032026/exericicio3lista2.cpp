#include <iostream>
using namespace std;
/*
Soma de dois números naturais, através de incrementos sucessivos (Ex.:3 + 4 = 1+1+ 1+1 + 3).
*/
int Soma(int A, int B){
	int S;
	if(A > 0){
		S = 1 + Soma(A - 1, B);
	}else{
		S = B;
	}
	return S;
}
int soma;
int main(){
	soma = Soma(4, 3);
	cout<<soma;
	return 0;
}
