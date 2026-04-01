#include <iostream>
#include <string.h>
using namespace std;

struct Dados{
	int Id;
	float Valor;
	char Desc[50];
	Dados *Prox;
};

struct Lista{ //para criar o primeiro elemento da lista
	Dados *Ini;
	int Qtd;
	float Total;
};

Dados* Criar_Elemento(int Id, char* Desc ,float Valor){
	Dados *Ret;
	
	Ret = (Dados *)malloc(sizeof(Dados));
	if(Ret != NULL){
		Ret->Id = Id;
		strcpy(Ret->Desc, Desc);
		Ret->Valor = Valor;
		Ret->Prox = NULL;
	}
	
	return Ret;
}

Dados* Inserir_Elemento(Lista *L ,int Id, char* Desc ,float Valor){ //a grosso modo poderia ser void, porem é melhor retornar //Lista *L é pra amarrar
	Dados* Ret;
	
	Ret = Criar_Elemento(Id, Desc, Valor);
	if(Ret != NULL){
		Ret->Prox = L->Ini; 
		//atualiza cabeçalho	
		L->Ini = Ret;
		L->Qtd++;
		L->Total = L->Total + Valor;
	}
	
	return Ret;
}


void Ini_Lista(Lista *L){ //não fazer apenas Lista L, se não não poderei alterar L
	L->Ini = NULL;
	L->Qtd = 0;
	L->Total = 0;
}

int Lista_Vazia(Lista *L){ //verificar se a lista está ou não vazia
	return (L->Ini == NULL); 
}


void Imprimir_Lista(Lista* L,Dados *D){//passar ponteiro gera para Distas
	if(D != NULL){
		
		cout<<"Identificador: "<<D->Id<<endl;
		cout<<"Descrição: "<<D->Desc<<endl;
		cout<<"Valor: "<<D->Valor<<endl;
	
		cout<<endl;
		Imprimir_Lista(L, D->Prox);
	}else{
		cout<<endl <<"-------------------------TOTAIS-------------------------"<<endl;
		cout<<"Quantidade Itens: "<< L->Qtd << "    Valor Total:" <<L->Total;
	}

}

Dados* Buscar_Elemento(Dados *D, int Id){ //importante retornar um valor!!
	Dados *Ret;
	if(D != NULL){
		if(D->Id != Id){
			Ret = Buscar_Elemento(D->Prox, Id);
		}else{
			Ret = D;
		}
		
	}else{
		Ret = NULL;
	}
	return Ret;
}

Dados* Remover_Elemento(Lista* L,  Dados *D, int Id){
	Dados *Ret;
	if(D != NULL){
		Ret = D; //inicializa ele mesmo
		if(D->Id == Id){ // achei o id
			Ret = D->Prox;  // pulei pro proximo
			
			if(D == L->Ini){
				L->Ini = Ret;
			}
			L->Qtd --;
			L->Total = L->Total - D->Valor;
			free(D);
		}else{
			D->Prox = Remover_Elemento(L, D->Prox , Id);
		}
	}
	return Ret;
}

//int Valor[10]; //lista estatica

//Dados *L1, *L2, *L3, IniNaopont, *Ini;

Lista L; //ele é o cabeçalho da lista, logo ele deve ser estatico.
Dados *PtD;
int main(){
	setlocale(LC_ALL,"Portuguese");
	
	Ini_Lista(&L);
	Inserir_Elemento(&L, 1, "sabonete", 09.99);
	Inserir_Elemento(&L, 2, "Bucha", 2.01);
	Inserir_Elemento(&L, 3, "Pao integral", 10.0);
	
	//Imprimir_Lista(&L ,L.Ini);
	cout<<endl<<endl;
	PtD = Buscar_Elemento(L.Ini, 2);
	//PtD = Buscar_Elemento(L.Ini, 4); //item não existe
	
	/*
	if(PtD != NULL){
		cout<<"Identificador: "<<PtD->Id<<endl;
		cout<<"Descrição: "<<PtD->Desc<<endl;
		cout<<"Valor: "<<PtD->Valor<<endl;
	}else{
		cout<<"Item não encontrado!"<<endl;
	}
	*/
	
	
	Remover_Elemento(&L, L.Ini, 2);
	Imprimir_Lista(&L ,L.Ini);
	/*
	//Lista feita a mão
	
	L1 = Cria_Elemento(1);
	L2 =  Cria_Elemento(2);
	L3 =  Cria_Elemento(3);
	//tres elementos separados.
	L1->Prox = L2;
	L2->Prox = L3;
	//Juntando elementos
	
	Ini = Cria_Elemento(1);
	Ini->Prox = Cria_Elemento(1);
	Ini->Prox->Prox = Cria_Elemento(1);
	
	IniNaopont.Prox = Cria_Elemento(1);
	IniNaopont.Prox->Prox = Cria_Elemento(6);
	*/
	
	/*
	
	cout<<L1->Valor<<endl << L2->Valor<< endl<<L3->Valor; //imprimindo separado.
	cout<<endl;
	cout<<L1->Valor<<endl << L1->Prox->Valor<< endl<<L2->Prox->Valor; //imrpimindo juntinho
	cout<<endl;
	cout<<L1->Valor<<endl << L1->Prox->Valor<< endl<<L1->Prox->Prox->Valor; //imrpimindo juntinho em função de l1
	//por isso preciso gravar o primeiro elemento da lista.
	
	*/
	/*
	
	//Teste de impressões 
	Imprimir_Lista(L1);
	cout<<endl;
	Imprimir_Lista(Ini);
	Imprimir_Lista(IniNaopont.Prox);
	
	*/
	
	return 0;
}
