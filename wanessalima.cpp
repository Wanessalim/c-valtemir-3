
#include <iostream>
using namespace std;
//repete nome

void rep_Nome(int n, string nome){
	
	if(n > 0){
		rep_Nome(n-1, nome);
		cout << nome<< endl;
		
	}
}

int main(){
	
	rep_Nome(6, "lucy");
	
	return 0;
}
