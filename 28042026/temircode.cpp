#include <iostream>

//pilha filha

using namespace std;
//Elemento a ser usado na pilha e na fila
struct Item{
	int Chave;
	Item *Prox;
};

struct Pilha{
	Item* Topo;
	int Qtd;
};

struct Fila{
	Item* Inicio;
	Item* Fim;
	int Qtd;
};

void Ini_Pilha(Pilha* P){
	P->Topo = NULL;
	P->Qtd = 0;
}

void Ini_Fila(Fila* F){
	F->Inicio = NULL;
	F->Fim = NULL;
	F->Qtd = 0;
}

int Pilha_Vazia(Pilha* P){
	return P->Topo == NULL; //vdd = 1, se fake = 0
}

int Fila_Vazia(Fila* F){
	return F->Inicio == NULL;
}

void Imprime_Lista(Item* Elemento){
	if(Elemento != NULL){
		cout<< Elemento->Chave;
		if(Elemento->Prox !=NULL){
			cout<<" , ";
		}
		
		Imprime_Lista(Elemento->Prox);
	}
}

Item * Cria_Item(int Chave){
	Item *Pt;
	
	Pt = (Item *) malloc(sizeof(Item));
	if (Pt != NULL){ //têm memoria
		Pt->Chave = Chave; //grava campo chave
		Pt->Prox = NULL;	
	}
	
	return Pt;
}

Item * Push(Pilha* P, int Chave){ //Empilhar
	Item *Pt;
	
	Pt = Cria_Item(Chave);
	if(Pt != NULL){
		Pt->Prox = P->Topo; //"Eu aponto pro elemento antigo"
		P->Topo = Pt;//"e o topo aponta pra mim"
		++P->Qtd;
	}
	
	return Pt;
}

/*
I(A) = mostrar A e I(A->prox)
*/
void Imprime_Item(Item *Ini){
	if(Ini != NULL){
		cout << Ini->Chave << endl;
		Imprime_Item(Ini->Prox);
	}
}

Pilha P;
int main () {
	setlocale (LC_ALL,"Portuguese");
	Ini_Pilha(&P);
	//Teste pilha
	Push(&P, 4);
	Push(&P, 6);
	Push(&P, 8);
	
	Imprime_Item(P.Topo);
	return 0;
}
