#include <iostream>

using namespace std;

int Idades[5];
int Cont;
int main(){
	
	Idades[0] = 5;
	Idades[1] = 4; //*(Idades + 1) = 4;
	Idades[2] = 3;
	Idades[3] = 2;
	Idades[4] = 1;
	
	for(Cont = 0; Cont < 5; Cont++){
		cout<< Idades [Cont]<<endl; //mostra conteudo.
		cout<< Idades + Cont<<endl; //mostra memoria
		cout<< *(Idades + Cont)<<endl; //mostra conteudo
	}
	
	return 0;
}
