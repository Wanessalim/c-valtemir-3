#include <iostream>

#define MAX 3
using namespace std;

struct Contato{
	string Nome, Email, Endereco, Cidade, Estado, Telefone, Observacoes;
	int Idade;
};

void Cadastrar(Contato A[]){
	int Cont;
	
	cout << "\n\t\t**** AGENDA >> CADASTRAR ****" << endl<< endl;
	for(Cont=0;Cont<MAX;Cont++){
		cout << "Pessoa["<<Cont<<"]: " << endl;
		cout << "Nome: ";		
		cin >> A[Cont].Nome;
		cout << "Idade: ";		
		cin >> A[Cont].Idade;
		cout << "E-mail: ";
		cin >> A[Cont].Email;
		cout << "Endere?: ";
		cin >> A[Cont].Endereco;
		cout << "Cidade: ";
		cin >> A[Cont].Cidade;
		cout << "Estado: ";
		cin >> A[Cont].Estado;
		cout << "Telefone: ";
		cin >> A[Cont].Telefone;
		cout << "Observa?es: ";
		cin >> A[Cont].Observacoes;
	}
}

void Imprimir(Contato A[]){
	int Cont;
	
	cout << "\n\t\t**** AGENDA >> IMPRIMIR ****" << endl<< endl;
	for(Cont=0;Cont<MAX;Cont++){
		cout << "Pessoa["<<Cont<<"]: " << endl;
		cout << "Nome: "<< A[Cont].Nome << endl;
		cout << "Idade: "<< A[Cont].Idade<< endl;
		cout << "E-mail: "<< A[Cont].Email<< endl;
		cout << "Endere?: "<< A[Cont].Endereco<< endl;
		cout << "Cidade: "<< A[Cont].Cidade<< endl;
		cout << "Estado: "<< A[Cont].Estado<< endl;
		cout << "Telefone: "<<  A[Cont].Telefone<< endl;
		cout << "Observa?es: "<< A[Cont].Observacoes<< endl;
	}
}


void Menu(Contato A[]){
	int Op;
	
	do{
		system("cls");
		cout << "\t\t**** AGENDA ****" << endl<< endl;
		cout << "[1] - Cadastrar" << endl;
		cout << "[2] - Buscar adultos por estado" << endl;
		cout << "[3] - Buscar pessoa mais velha" << endl;
		cout << "[4] - Imprimir" << endl;
		cout << "[5] - Sair" << endl;
		cout << "Op?o: ";
		cin >> Op;	
		
		switch(Op){
			case 1:
				Cadastrar(A);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				Imprimir(A);
				break;
			case 5:
				break;
			default:
				cout << endl << "Op?o inv?ida!!"<<endl;
		}
		
		if (Op != 5){
			system("pause");
		}
	}while(Op!=5);
}

Contato Agenda[MAX];
int main(){	
	setlocale(LC_ALL,"Portuguese");

	Menu(Agenda);

	return 0;
}


