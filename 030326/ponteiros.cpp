#include <iostream>
using namespace std;
//ponteiros

int X = 10,Y ,*PtX;
int main(){
	
	//cout << (&X) + 1; //£
	cout << (&X)<<endl;
	PtX = &X;
	*PtX = (*PtX) + 50;
	cout <<"Endereço de X: "<< PtX<<endl;
	//como mostrar valor de x?
	cout<<"Conteudo de X: "<<*PtX;
	/*
	cout << PtX<<endl;
	PtX = &Y;
	cout << PtX;
	*/
	
	
	
	return 0;
}
