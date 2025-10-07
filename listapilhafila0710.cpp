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
	Elemento *Ini_top; //em pilha é sempre na cabeça
	Elemento *Fim;//pra fila.
	int Qtde_Total;
	float Valor_Total;
};
//funções basicas


int Lista_Vazia(Cab* C){
	
	return C->Ini_top == NULL; // isso so retorna 0 e 1
}


void Ini_Lista(Cab* C){ //inicialização da lista
	C->Ini_top = NULL;
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


void Insere(Cab *C, int Chave,const char* Desc, float Valor){ //insercão da fila é a mesma da pilha
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);
	Pt->prox = C->Ini_top;
	C->Ini_top = Pt;
	C->Qtde_Total++;
	C->Valor_Total+= Valor;
}
//pilha
//insercão == atualiza o topo se apilha não for vazia.
//inserção
void Push(Cab *C, int Chave,const char* Desc, float Valor){
	Insere(C, Chave, Desc, Valor);
}
//remoção
Elemento* Pop(Cab* C){
	Elemento *Pt;
	//se a pilha não estiver vazia atualiza ini.
	if(!Lista_Vazia(C)){
		//atualiza o inicio
		Pt = C->Ini_top;
		C->Ini_top = C->Ini_top->prox; //estudar essa porra aqui
		//atualiza totais
		C->Qtde_Total--;
		C->Valor_Total-= Pt->Valor;
	}
	return Pt;
}

//fila
//inserção========================
void Enqueue(Cab *C, int Chave,const char* Desc, float Valor){ //insercão da fila é a mesma da pilha
	Elemento *Pt;
	
	Pt = Cria_Elemento(Chave, Desc, Valor);

	// se a fila estiver vazia

	if(Lista_Vazia(C)){
		C->Ini_top = Pt;
	}
	else{ 
		C->Fim->prox = Pt;
	
	}
	C->Fim = Pt;
	//insere no fim da fila
	
	
	C->Qtde_Total++;
	C->Valor_Total+= Valor;
}
//Remoção===============================
Elemento* Dequeue(Cab *C){
		Elemento *Pt;
		
	//se a pilha não estiver vazia atualiza ini.
	if(!Lista_Vazia(C)){
		//atualiza o inicio
		Pt = C->Ini_top;
		C->Ini_top = C->Ini_top->prox; //estudar essa porra aqui
		
		//atualiza totais
		C->Qtde_Total--;
		C->Valor_Total-= Pt->Valor;
		
		if(C->Ini_top == NULL){
			//inicializar fim novamente
			C->Fim=NULL;
		}
	}
	return Pt;
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

Elemento* Busca(Elemento *Pt, int Chave){
	Elemento* Ret;
	if(Pt != NULL){
		if(Pt->Chave != Chave){
			Ret = Busca(Pt->prox, Chave);
		}
		else{
			Ret = Pt;
		}
	}	
	return Ret;
}

Cab L, Pilha, Fila; //L1, L2  
Elemento* Pt;  
int main(){
	setlocale(LC_ALL,"Portuguese");
 //remoção lista??
	Ini_Lista(&L);
	Insere(&L, 1, "Coxinha", 5); //acesso ao primeiro
	Insere(&L, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o Ini_top
	Insere(&L, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o Ini_top
	Imprime(&L, L.Ini_top);
	Pt = Busca(L.Ini_top, 3);
	if(Pt!=NULL){
		cout << endl <<"Elemento encontrado: "<< Pt->Desc <<"("<< Pt->Chave <<")"<<endl;
	}
	
/* pilha
	Ini_Lista(&Pilha);
	Push(&Pilha, 1, "Coxinha", 5); //acesso ao primeiro
	Push(&Pilha, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o Ini_top
	Push(&Pilha, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o Ini_top
	Imprime(&Pilha, Pilha.Ini_top); // o ultimo que entra ? o primeiro que sai. ==> come?a pelo ultimo.
	system("Pause");
	Pop(&Pilha);
	Pop(&Pilha);

	//Pt = Pop(&Pilha);
	
	//if(Pt){
	//	cout << endl <<"Elemento removido: "<< Pt->Desc <<"("<< Pt->Chave <<")"<<endl;
	//}

	//system("pause");
	
	Imprime(&Pilha, Pilha.Ini_top);
*/	

	
	
	
	/*
	Insere(&L, 1, "Coxinha", 5); //acesso ao primeiro
	Insere(&L, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o Ini_top
	Insere(&L, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o Ini_top
	
	*/
	
	/*
	Ini_Lista(&Fila);
	Enqueue(&Fila, 1, "Coxinha", 5); //acesso ao primeiro
	Enqueue(&Fila, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o Ini_top
	Enqueue(&Fila, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o Ini_top
	Imprime(&Fila, Fila.Ini_top);
	*/

 /*
		Ini_Lista(&Fila);
	Enqueue(&Fila, 1, "Coxinha", 5); //acesso ao primeiro
	Enqueue(&Fila, 2, "Risolis", 7); // dois aponta pro 1 e o 2 vira o Ini_top
	Enqueue(&Fila, 3, "Chocolate", 4.5); // tres aponta por 2 e 3 vira o Ini_top
	Imprime(&Fila, Fila.Ini_top);
	system("pause");
	Dequeue(&Fila);
	Dequeue(&Fila);
	//if(Pt){
		//cout << endl <<"Elemento removido: "<< Pt->Desc <<"("<< Pt->Chave <<")"<<endl;
	//}
	Imprime(&Fila, Fila.Ini_top);
	*/
	
	
	return 0;
}
