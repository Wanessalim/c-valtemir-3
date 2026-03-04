#include <iostream>
#include <string.h>
using namespace std;

struct Contato{ //variavel struct têm muitos bytes.
	char Nome[50];
	int Idade;
};

void AlteraContato(Contato C){
	strcpy(C.Nome,"Andre");
	C.Idade = 23;
	cout<<"Nome(Dentro): "<< C.Nome<<endl;
	cout<<"Idade(Dentro): "<<C.Idade<<endl;
}

void AlteraContato2(Contato *C){
	strcpy((*C).Nome,"Andre"); // C->Nome == (*C).Nome
	(*C).Idade = 23;
}

void Funcao1(int Tot){ //passei um parametro pra função por valor. == copia do valor
	Tot = Tot + 100;
	cout<<"Endereço de Tot: "<< &Tot<<endl;
	cout<<"Total: "<<Tot<<endl;
}

void Funcao2(int *Tot){ //passei uma referencia de endereço para função. ==copia do endereço (consigo alterar contéudo)
	*Tot = *Tot + 100;
	cout<<"Endereço de Tot: "<< Tot<<endl;
	cout<<"Total: "<<*Tot<<endl;
}

int T = 5;
Contato Con;
int main(){
	/*
	Funcao1(T); //contéudo de t não é mudado.
	cout<<"Total(Fora da função): "<<T<<endl;
	cout<<"Endereço de T: "<< &T<<endl;
	cout<<endl;
	
	Funcao2(&T);//Endreço de t é passado para tot
	cout<<"Total(Fora da função): "<<T<<endl;
	cout<<"Endereço de T: "<< &T<<endl;
	*/
	setlocale(LC_ALL,"Portuguese");
	
	
	Con.Idade = 54;
	strcpy(Con.Nome,"Temir");
	cout<<"Valores originais"<<endl;
	cout<<"Nome: "<< Con.Nome<<endl;
	cout<<"Idade: "<<Con.Idade<<endl;
	cout<<endl;
	
	AlteraContato(Con);
	cout<<endl;
	cout<<"Valores após altera contato 1"<<endl;
	cout<<"Nome: "<< Con.Nome<<endl;
	cout<<"Idade: "<<Con.Idade<<endl;
	
	//altera corrigida.
	AlteraContato2(&Con); //Com ponteiros
	cout<<endl;
	cout<<"Valores após altera contato 2"<<endl;
	cout<<"Nome: "<< Con.Nome<<endl;
	cout<<"Idade: "<<Con.Idade<<endl;

	
	return 0;
}
