#include <iostream>
#include <stdlib.h>
using namespace std;
//Este é o teste de uma interface

void menu(){
	int num;
	cout<<"------------------Teste operação com listas------------------"<< endl;
	cout<<"1 -Inserir em lista (Lista 1 ou Lista 2)"<<endl;
	cout<<"2 -Remover da lista (Lista 1 ou Lista 2)"<<endl;
	cout<<"3 -Imprimir as listas"<<endl;
	cout<<"4 -Calcular comprimento das listas"<<endl;
	cout<<"5 -Contar ocorrencias de um numero em uma lista (Lista 1 ou Lista 2)"<<endl;
	cout<<"6 -Substituir ocorrencias de um numero em uma lista (Lista 1 ou Lista 2)"<<endl;
	cout<<"7 -Dividir uma lista em duas (Lista 1 ou Lista 2)"<<endl;
	cout<<"8 -Interseção das listas"<<endl;
	cout<<"0 -sair"<< endl<< endl;
	cout<<"Digite sua opção: ";
}

int listaescolha(){
		int op;
		cout<<"----Escolha sua lista----"<< endl;
		cout<<"1 - Lista 1"<< endl;
		cout<<"2 - Lista 2"<< endl;
		cout<<"0 - sair"<< endl;
		cout<<"Escolha: ";
		cin>> op;
		return op;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	int op;
	do{
		system("cls");
		menu();
		cin>>op;
		switch(op){
			case 1:{
				system("cls");
				int opl = listaescolha();
				do{
					if(opl == 1){
						cout<<"Inserido na lista 1"<< endl;
						system("pause");
					} else{
						if(opl == 2){
							cout<<"Inserido na lista 2"<< endl;
							system("pause");
						}
					}
				}while(opl != 0);
				cout<<"Fudida";
				break;
			}
			case 2:
				cout<<"Marmelada";
				break;
		}
	}while(op != 0);
	return 0;
}
