#include <iostream>
using namespace std;

void  REPETE_NOME(string Nome, int N){
	if(N > 0){
		cout<< Nome<<endl;
		REPETE_NOME( Nome, N - 1);
	}
}

int main(){
	REPETE_NOME("OI", 10);
	return 0;
}
