#include <iostream>
using namespace std;
//Soma de dois números naturais, através de incrementos sucessivos (Ex.:3 + 4 = 1+1+ 1+1 + 3).
// 
/*
s(6, 4) = 6 + s(6, 3)
*/
int multiD(int a, int b){
	int result;
	if(b == 0){
		return result;
	}
	result = a + multiD(a, b - 1);	
}  

int main(){
//	cout << multiD(6, 4);

	
	return 0;
	
}
