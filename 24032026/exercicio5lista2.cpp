#include <iostream>
using namespace std;
/*
Cálculo de 1 + 1/2 + 1/3 + 1/4 + ... + 1/N.
*/
float Calc(float N){
	float Ret;
	if(N == 0){
		Ret = 0;
	}else{
		Ret = 1/N + Calc(N -1);
		cout<<"1/"<<N <<" + ";
	}
	return Ret;
}
float T;
int main(){
	
	T = Calc(3);
	cout<<" = "<< T;
	
	return 0;
}
