#include <iostream>
using namespace std;
/*
Cálculo de 2/4 + 5/5 + 10/6 + 17/7 + 26/8 + ... + 
(n²+1)/(n+3).
*/
float Soma(float N){
	float Ret;
	if(N == 0){
		Ret = 0;
	}else{
		Ret = ((N*N) + 1) / (N + 3) + Soma(N - 1);
		cout<<(N*N) + 1 <<"/"<< (N + 3) <<" + ";
		//obs resolver impressão depois!!
		
	}
	return Ret;
}
float t;
int main(){
	t = Soma(3);
	cout<<t;
	return 0;
}
