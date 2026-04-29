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
	}else{
		cout<< endl<<endl;
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

Item * Pop(Pilha* P){
	Item* Pt;
	if(!Pilha_Vazia(P)){ //Se lista não está vazia
		//retira item do topo
		Pt = P->Topo;
		P->Topo = P->Topo->Prox;
		--P->Qtd;
	}else{ // se a lista têm apenas um item retorna lista null
		Pt = NULL;
	}
	
	
	return Pt;
}

Item * Enqueue(Fila* F, int Chave){ //Enfileirar
	Item *Pt;
	
	Pt = Cria_Item(Chave);
	if(Pt != NULL){
		if(Fila_Vazia(F)){ //fila vazia
			F->Inicio = Pt; //atualiza cabeça 
		}else{ //fila não vazia
			F->Fim->Prox = Pt; //atualiza o final (Ultimo final aponta pra mim)
		}
		F->Fim = Pt; //Fim aponta para mim
		++F->Qtd;
	}
	
	return Pt;
}

Item * Dequeue(Fila* F){ //desenfileirar
	Item *Pt;

	if(!Fila_Vazia(F)){
		//retira item do topo
		Pt = F->Inicio; 
		F->Inicio = F->Inicio->Prox;
		if(F->Inicio == NULL){
			F->Fim = F->Inicio;
		}
		--F->Qtd;
	}else{
		Pt = NULL;
	}
	
	return Pt;
}



Pilha P;
Fila F;
Item *Pt; //ver oq ocorre com item
int main () {
	setlocale (LC_ALL,"Portuguese");
	Ini_Pilha(&P);
	Ini_Fila(&F);
	
	//Teste pilha
	Push(&P, 4);
	Push(&P, 6);
	Push(&P, 8);
	Pt = Pop(&P);
	cout<< endl<<"Item Exluido: " << Pt->Chave<< endl;
	//Pop(&P);
	//Pop(&P); //Caso do Pt = NULL;
	
	Imprime_Lista(P.Topo);

	//Teste Fila
	Enqueue(&F, 4);
	Enqueue(&F, 6);
	Enqueue(&F, 8);
	Pt = Dequeue(&F);
	cout<< endl<<"Item Exluido: " << Pt->Chave<<endl;
	//Dequeue(&F);
	Imprime_Lista(F.Inicio);
	
	return 0;
}
