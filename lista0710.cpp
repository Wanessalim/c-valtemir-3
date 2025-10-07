#include <iostream>
#include <string.h>
using namespace std;

struct Elemento{
	int Chave;//cpf, pront, numero de regidstro, etc
	char Desc[30];
	float Valor;
	Elemento *prox; //Encadeamento
	//criando cabeçalho == tem o inicio da lista
};
struct Cab{ //cabeçalho
	Elemento *Inicio; //em pilha é topo
	int Qtde_Total;
	float Valor_Total;
};
//funções basicas


int Lista_Vazia(Cab* C){
	
	return C->Inicio == NULL;
}


void Ini_Lista(Cab* C){ //inicialização da lista
	C->Inicio = NULL;
	C->Qtde_Total = 0;
	C->Valor_Total = 0.0;
}


Elemento * Cria_Elemento(int Chave,const char* Desc, float Valor){ 
	Elemento *pt;
	
	pt = (Elemento*)malloc(sizeof(Elemento));
	
	if(pt != NULL){
		pt->Chave = Chave; 
		strcpy(pt->Desc, Desc);
		pt->Valor = Valor;
	}
	return pt;
}


void Insere(Cab *C, int Chave,const char* Desc, float Valor){ // imperativa
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);
	Pt->prox = C->Inicio;
	C->Inicio = Pt;
	C->Qtde_Total++;
	C->Valor_Total+= Valor;
}

void Imprime(Cab *C, Elemento *Pt){
	
	if(Pt != NULL){
		cout<<endl<< "Chave: "<< Pt->Chave << endl;
		cout<< "Descrição: "<< Pt->Desc << endl;
		cout<< "Valor: "<< Pt->Valor << endl;
		Imprime(C, Pt->prox);
	}	
	else{
		cout<<"----------------"<< endl;
		cout<<"Total de elementos: "<< C->Qtde_Total<< endl;
		cout<<"Valor total: "<< C->Valor_Total << endl;
	}
}

Cab L; //L1, L2    
int main(){
	setlocale(LC_ALL,"Portuguese");
 
	Ini_Lista(&L);
	
	Insere(&L, 1, "Coxinha", 5); //acesso ao primeiro
	Insere(&L, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o inicio
	Insere(&L, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o inicio
	
	
	Imprime(&L, L.Inicio); // o ultimo que entra ? o primeiro que sai. ==> come?a pelo ultimo.
	
	return 0;
}
