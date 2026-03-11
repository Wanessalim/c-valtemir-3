#include <iostream> //GNU C++11
#include <stdlib.h> //função malloc tá aqui
using namespace std;
//alocação de memoria

int *PtX; //este X, é uma alocação estatíca.

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	PtX = (int*) malloc(sizeof(int));
	*PtX = 4;
	free(PtX);
	//cout<< ((float) 5)/2;
	
	cout<<*PtX;
	return 0;
}
