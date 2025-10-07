#include <iostream>
#include <cstdlib>
using namespace std;

struct List{ // estrutura para todas as listas :)
	int n; // valor que será passado
	List* prox; // ponteiro que aponta para o proxímo
};

List * CriaLista(int num){ //criando um novo elemento de struct
	List *pt;
	
	pt = (List*)malloc(sizeof(List));
	
	if(pt != NULL){
		/*
		se a alocaçõa for bem sucedida, atribui o num e define o ponteiro prox como nulo, será o final da lista.
		exemplo:
		criaaluno(1) -> [1| NULL]
		*/
		pt->n = num; 
		pt->prox = NULL;
	}
	return pt;
}
/*
Primeira função :)
desenvolva Uma função que receba como parâmetros uma lista encadeada e um número inteiro a ser inserido na lista;
1. preciso criar uma lista.
2. mandar essa lista por parametro(primeiro elemento da lista) == ponteiro
3. Inserir esse novo elemento na lista == int main
*/
List * InsereLista(List* Ini, int num){ 
	List *Pt;
	Pt = CriaLista(num); //recebe a lista
	Pt->prox = Ini; //esse elemento vai para o primeiro local da lista
	
	return Pt;
}


int main(){
	setlocale(LC_ALL, "portuguese");
	// menuzinho
	int esc,a;
	do{
		cout<<"------------------Teste operação com listas------------------"<< endl;
		cout<<"1 - Inserir em lista (Lista 1 ou Lista 2)"<<endl;
		cout<<"2 -Remover da lista (Lista 1 ou Lista 2)"<<endl;
		cout<<"3 -Imprimir as listas"<<endl;
		cout<<"4 -Calcular comprimento das listas"<<endl;
		cout<<"5 -Contar ocorrencias de um numero em uma lista (Lista 1 ou Lista 2)"<<endl;
		cout<<"6 -Substituir ocorrencias de um numero em uma lista (Lista 1 ou Lista 2)"<<endl;
		cout<<"7 -Dividir uma lista em duas (Lista 1 ou Lista 2)"<<endl;
		cout<<"8 -Interseção das listas"<<endl;
		cout<<"0 - sair"<< endl;
		cout<<"Opção: ";
		cin>> esc;
		
		
		switch(esc){
			case 1:
				system("cls");
				cout<<"Você escolheu Inserir"<< endl;
				cout<<"Digite seu novo elemento: ";
				break;
				
			case 2:
				system("cls");
				cout<<"Você escolheu Remover"<< endl;
				break;
				
			case 3:
				system("cls");
				cout<<"Você escolheu Imprimir"<< endl;
				break;
				
			case 4:
				system("cls");
				cout<<"Você escolheu Calcular comprimento das listas"<< endl;
				break;
				
			case 5:
				system("cls");
				cout<<"Você escolheu Contar ocorrencias de um numero em uma lista"<< endl;
				break;
				
			case 6:
				system("cls");
				cout<<"Você escolheu Substituir ocorrencias de um numero em uma lista"<< endl;
				break;
				
			case 7:
				system("cls");
				cout<<"Você escolheu Dividir uma lista em duas"<< endl;
				break;
				
			case 8:
				system("cls");
				cout<<"Você escolheu Interseção das listas"<< endl;
				break;
				
			case 0:
				system("cls");
				cout<<"Saindo..."<< endl;
				break;
			
			default:
				cout<<"Numero invalido"<< endl;
		}
	}while(esc != 0); // obs, qnão esta realizando as operações :(
	
	
	return 0;
}
