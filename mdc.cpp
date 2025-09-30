#include <iostream>
using namespace std;

//mdc, revisar hoje!!
/*

36, 24
36/24 = q=1, r=12 (36%24)
24/12 == q=2, r = 0 (36%24)


*/

int mdc(int a, int b){
	int  ret = 0;
	if(b != 0){ // condicional
		ret = mdc(b, a%b); // troca de parametros de ligar!!
	} else{
		ret = a;
	}
	return ret;
}

int main(){
	
	cout<<mdc(24, 36);
	
}
