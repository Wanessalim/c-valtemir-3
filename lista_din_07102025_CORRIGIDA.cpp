#include <iostream>
#include <string.h>

// Este é um exemplo de programa em C++

using namespace std;

struct Elemento{
	int Chave;
	char Desc[30];
	float Valor;
	Elemento *Prox;
};

struct Cab{
	Elemento *Ini_Topo;
	Elemento *Fim;
	int Qtde_Total;
	float Valor_Total;
};

int Lista_Vazia(Cab *C){
	
	return C->Ini_Topo == NULL;
}

void Ini_Lista(Cab *C){
	C->Ini_Topo = NULL;
	C->Fim = NULL;
	C->Qtde_Total = 0;
	C->Valor_Total = 0;
}

Elemento* Cria_Elemento(int Chave, const char* Desc, float Valor){
	Elemento *Pt;

	Pt = (Elemento *) malloc(sizeof(Elemento));
	if (Pt != NULL){
		Pt->Chave = Chave;
		strcpy(Pt->Desc,Desc);
		Pt->Valor = Valor;	
		Pt->Prox = NULL;
	}
	
	return Pt;
}

//Lista
void Insere(Cab *C, int Chave, const char* Desc, float Valor){
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);
	
	//Insere na cabeça da lista
	Pt->Prox = C->Ini_Topo;	
	C->Ini_Topo = Pt;
	
	//Atualiza totais
	C->Qtde_Total++;
	C->Valor_Total += Valor;
}

Elemento* Remove(Cab *C, Elemento *Pt, int Chave){
	Elemento *Ret;
	int Atualiza_Totais;
	
	if (Pt!=NULL){
		Atualiza_Totais = 0;
		//CORREÇÃO na lógica dos condicionais
		if (Pt == C->Ini_Topo && Pt->Chave == Chave){ //Atualiza o início
			Ret = Pt;
			//Elimina o elemento
			C->Ini_Topo = C->Ini_Topo->Prox;

			//Atualiza totais
			Atualiza_Totais = 1;
		}
		else{					
			if (Pt->Prox!= NULL && Pt->Prox->Chave == Chave){ 	
				//cout << endl << "Elem Chave: " << Pt->Prox->Chave << " Chave: " << Chave << endl;
				Ret = Pt->Prox; 
				
				//Elimina o elemento
				Pt->Prox = Pt->Prox->Prox;			
				
				//Atualiza totais
				Atualiza_Totais = 1;
			}
			else{
				Ret = Remove(C, Pt->Prox, Chave);
			}
		}
		
		if (Atualiza_Totais){
			C->Qtde_Total--;
			C->Valor_Total -= Ret->Valor;
		}
	}
	
	return Ret; 
}

//Pilha 
//Inserção na pilha
void Push(Cab *C, int Chave, const char* Desc, float Valor){
	Insere(C, Chave, Desc, Valor);
}

//Remoção da pilha
Elemento* Pop(Cab* C){
	Elemento *Pt;
	
	//Se a pilha não estiver vazia, atualiza início
	if (!Lista_Vazia(C)){
		//Atualiza o início
		Pt = C->Ini_Topo;
		C->Ini_Topo = C->Ini_Topo->Prox;
		
		//Atualiza totais
		C->Qtde_Total--;
		C->Valor_Total -= Pt->Valor;
	}
	
	return Pt;
}

//Fila
//Inserção na fila
void Enqueue(Cab *C, int Chave, const char* Desc, float Valor){
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);	
	//Se a fila estiver vazia, atualiza cabeça
	if(Lista_Vazia(C)){
		C->Ini_Topo = Pt;			
	}
	else{ 
		C->Fim->Prox = Pt;
	}
	
	//Atualiza final da dila
	C->Fim = Pt;	
	
	//Atualiza totais
	C->Qtde_Total++;
	C->Valor_Total += Valor;
}

//Remoção da fila
Elemento* Dequeue(Cab* C){
	Elemento *Pt;
	
	//Se a pilha não estiver vazia, atualiza início
	if (!Lista_Vazia(C)){
		//Atualiza o início
		Pt = C->Ini_Topo;
		C->Ini_Topo = C->Ini_Topo->Prox;
		
		//Atualiza totais
		C->Qtde_Total--;
		C->Valor_Total -= Pt->Valor;
		
		if (C->Ini_Topo == NULL){
			//Inicializar fim novamente
			C->Fim=NULL;
		}
	}
	
	return Pt;
}

void Imprime(Cab *C, Elemento *Pt){
	if(Pt != NULL){
		cout << endl<< "Chave: " << Pt->Chave << endl;
		cout << "Descrição: " << Pt->Desc << endl;
		cout << "Valor: " << Pt->Valor << endl;
		Imprime(C, Pt->Prox);
	}
	else{
		cout << "-----------------------------"<< endl;
		cout << "Total de elementos: " << C->Qtde_Total<<endl;
		cout << "Valor total: " << C->Valor_Total<<endl;
	}
}

Elemento* Busca(Elemento *Pt, int Chave){
	Elemento* Ret=NULL;	
	
	if(Pt != NULL){
		if (Pt->Chave != Chave){
			Ret = Busca(Pt->Prox, Chave);	
		}
		else{
			Ret = Pt;		
		}		
	}
	
	return Ret;
}


Cab L, Pilha, Fila;
Elemento *Pt;
int main () {
	setlocale (LC_ALL,"Portuguese");
	
	Ini_Lista(&L);
	Insere(&L,1, "Coxinha", 5);
	Insere(&L,2, "Risólis", 7);
	Insere(&L,3, "Chocolate", 4.5);
	Imprime(&L, L.Ini_Topo);
	system("pause");
	Pt = Remove(&L, L.Ini_Topo, 2);
	if (Pt){
		cout << endl <<"Elemento removido: "<<Pt->Desc <<"("<<Pt->Chave<<")" << endl;		
	}	
	system("pause");
	Imprime(&L, L.Ini_Topo);
	//Pt = Busca(L.Ini_Topo, 2);
	//if (Pt!=NULL){ //Achei!!
	//	cout << endl <<"Elemento encontrado: "<<Pt->Desc <<"("<<Pt->Chave<<")" << endl;			
	//}
	//else{
	//	cout << endl << "Elemento não encontrado!!!";
	//}
	
	/*Ini_Lista(&Pilha);
	Push(&Pilha,1, "Coxinha", 5);
	Push(&Pilha,2, "Risólis", 7);
	Push(&Pilha,3, "Chocolate", 4.5);	
	Imprime(&Pilha, Pilha.Ini_Topo);
	system("pause");
	Pop(&Pilha);
	Pop(&Pilha);
	//Pt = Pop(&Pilha);
	//if (Pt){
	//		cout << endl <<"Elemento removido: "<<Pt->Desc <<"("<<Pt->Chave<<")" << endl;		
	//}	
	//system("pause");
	Imprime(&Pilha, Pilha.Ini_Topo);*/
	
	/*Ini_Lista(&Fila);
	Enqueue(&Fila,1, "Coxinha", 5);
	Enqueue(&Fila,2, "Risólis", 7);
	Enqueue(&Fila,3, "Chocolate", 4.5);	
	Imprime(&Fila, Fila.Ini_Topo);
	system("pause");
	Dequeue(&Fila);
	Dequeue(&Fila);
	//Pt = Dequeue(&Fila);
	//if (Pt){
	//		cout << endl <<"Elemento removido: "<<Pt->Desc <<"("<<Pt->Chave<<")" << endl;		
	//}	
	Imprime(&Fila, Fila.Ini_Topo);*/
	
	return 0;
}
