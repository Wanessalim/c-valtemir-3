#include <iostream>
using namespace std;

using namespace std;

//Elemento a usar usado na pilha e na fila
struct Item{
	char Parenteses;
	Item *Prox;
};

struct Pilha{
	Item *Topo;
	int Qtde;
};

struct Fila{
	Item *Inicio;
	Item *Fim;
	int Qtde;
};

void Ini_Pilha(Pilha *P){
	P->Topo = NULL;
	P->Qtde = 0;
}

void Ini_Fila(Fila *F){
	F->Inicio = NULL;
	F->Fim = NULL;
	F->Qtde = 0;
}

int Pilha_Vazia(Pilha *P){
	return P->Topo == NULL;
}

int Fila_Vazia(Fila *F){
	return F->Inicio == NULL;
}

void Imprime_Lista(Item *Elemento){
	if (Elemento != NULL){
		cout << Elemento->Parenteses;
		if (Elemento->Prox!= NULL){
			cout << ", ";
		}
		Imprime_Lista(Elemento->Prox);
	}
	else{
		cout << endl << endl;
	}
}

Item* Cria_Item(char Parenteses){
	Item *Pt;
	
	Pt = (Item *) malloc(sizeof(Item));
	if (Pt != NULL){ 
		Pt->Parenteses = Parenteses;
		Pt->Prox = NULL;	
	}
	
	return Pt;
}

Item* Push(Pilha *P, char Parenteses){ 
	Item *Pt;
	
	Pt = Cria_Item(Parenteses);
	if (Pt != NULL){
		Pt->Prox = P->Topo;
		P->Topo = Pt;
		++P->Qtde;			
	}
	
	return Pt;
}

Item* Pop(Pilha *P){
	Item* Pt;
	
	if (!Pilha_Vazia(P)){
		Pt = P->Topo;
		P->Topo = P->Topo->Prox;
		--P->Qtde;
	}
	else{
		Pt = NULL;
	}
	
	return Pt;
}

Item* Enqueue(Fila *F, char Parenteses){ 
	Item *Pt;
	
	Pt = Cria_Item(Parenteses);
	if (Pt != NULL){
		if (Fila_Vazia(F)){
			F->Inicio = Pt; //atualiza a cabeça
		}
		else{
			F->Fim->Prox = Pt; //atualiza o final			
		}
		
		F->Fim = Pt;//atualiza o final no cabeçalho				
		++F->Qtde;			
	}
		
	return Pt;
}

Item* Dequeue(Fila *F){ //Desenfileirar
	Item *Pt;
	
	if (!Fila_Vazia(F)){
		//Retira o item do início
		Pt = F->Inicio;
		F->Inicio = F->Inicio->Prox;
		if (F->Inicio == NULL){
			F->Fim = F->Inicio;
		}
		--F->Qtde;
	}
	else{
		Pt = NULL;
	}
		
	return Pt;
}

int ProcessaParenteses(Fila* F){
	int Ret = 1; 
	Pilha Aux;
	Ini_Pilha(&Aux);
	Item *Temp;
	
	while(!Fila_Vazia(F)){
		
		Temp = Dequeue(F);
		
		if(Temp->Parenteses == '('){ // (
			Push(&Aux, Temp->Parenteses);
			
		}else{ // ) ou Vazia(Se for vazia R = 0) se ) Pop
			
			if(Pilha_Vazia(&Aux)){
				Ret = 0;
				Pop(&Aux);
			}
		}	
	}
	
	if(Pilha_Vazia(&Aux)){ 
		Ret = 0;	
	}
	return Ret;
}

Fila Expressao;
int P;
int main(){
	setlocale (LC_ALL,"Portuguese");
	Ini_Fila(&Expressao);

	Enqueue(&Expressao, '(');
	Enqueue(&Expressao, ')');
	Enqueue(&Expressao, '(');
	Enqueue(&Expressao, ')');


	P = ProcessaParenteses(&Expressao);
	if(P== 1){
		cout<<"correto";
	}else{
		cout << "Incorreto";
	}
	

	return 0;
}
