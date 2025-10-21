#include <iostream>
#include <stdlib.h>
/*
Implementar uma função RECURSIVA chamada Troca_Preco que receba como parâmetros uma lista encadeada (contendo apenas o campo Preco do tipo float), 

dois preços (original e novo, ambos float) e um parâmetro de referência chamado Total_Trocas (int). 

função troca preço(lista, original,  novo, parametro){
	REcursividade!!
	troque todas as ocorrências 
	Total_Trocas a quantidade de trocas realizadas. 
	retorna: lista(retorna com ponteiro.) + qtde total.
}

lista alterada deve ser impressa na tela (função Imprimir) para mostrar as mudanças na lista e a quantidade de trocas
*/

using namespace std;

struct Elemento{
	float Preco;
	Elemento* Prox;
};

struct Cab{
	Elemento* Ini_topo;
	int Qtde_Total;
};

void Ini_lista(Cab *C){
	C->Ini_topo = NULL;
	C->Qtde_Total = 0;	
}

Elemento *Cria_Elemento(float Preco){
	Elemento *Pt;
	Pt = (Elemento*)malloc(sizeof(Elemento));
	if(Pt != NULL){
		Pt->Preco = Preco;
		Pt->Prox = NULL;
	}
	return Pt;
}

void Insere(Cab *C, float Preco){
	Elemento *Pt;
	// insere
	Pt = Cria_Elemento(Preco);
	Pt->Prox = C->Ini_topo;
	C->Ini_topo = Pt;
	C->Qtde_Total ++;
}

void Imprime(Cab *C, Elemento *Pt){
	if(Pt != NULL){
		cout<<"Preço: "<< Pt->Preco<< endl;
		Imprime(C, Pt->Prox);
	}
}

void Troca_Preco(Elemento *Pt, float Preco_Original, float Preco_Novo,int *Total_Trocas){ //Cab não é necessario.
	if(Pt != NULL){
		Troca_Preco(Pt->Prox, Preco_Original, Preco_Novo, Total_Trocas); //backtrack ajuda :)
		if(Pt->Preco == Preco_Original){
			Pt->Preco = Preco_Novo;
			(*Total_Trocas) ++;
		}
	}else{
		(*Total_Trocas) = 0;
	}
}


Cab L1;
int cont;
int main(){
	
	cont = 10; // como zerar o total trocas lá dentro.== se houver lixo aqui dá erro
	setlocale(LC_ALL,"Portuguese");
	Ini_lista(&L1);
	//adicionando valores originais
	Insere(&L1, 2.5);
	Insere(&L1, 2.5);
	Insere(&L1, 2.9);
	Imprime(&L1, L1.Ini_topo);
	// chamando a troca.
	cout<<endl<<"Apos trocas: "<< endl;
	Troca_Preco( L1.Ini_topo , 2.5, 4.1, &cont);
	Imprime(&L1, L1.Ini_topo);
	cout<<"Qtde de trocas: "<<cont;

	return 0;
}
