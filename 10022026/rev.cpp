#include <iostream>
using namespace std;
//antes das variaveis temos as funções ;)
//double Altura[5]; --> uma variavel que vale para o sistema inteiro, RARAMENTE deve ser MUDADA.
//string Nome[5];
void Imprimir(string N[],double A[]){
	int Cont;
	system("cls");
	for(Cont = 0; Cont<5;Cont++){
		cout<<"Pessoa "<<Cont<<endl;
		cout<<"Nome: "<< N[Cont] << endl;
		cout<<"Altura: "<< A[Cont]<< endl;
		cout<<endl;
		
	}
}

int Num, Cont, ContAnoes;
double Altura[5], SomaAlt, MaiorAlt;
string Nome[5], MaiorAltNome;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	SomaAlt=0;
	MaiorAlt = 0;
	ContAnoes = 0;
	
	for(Cont = 0; Cont<5;Cont++){
		system("cls");
		cout<<"Pessoa °"<<Cont<<endl;
		cout<<"Nome: ";
		cin>>Nome[Cont];
		cout<<"Altura: ";
		cin>>Altura[Cont];
		SomaAlt += Altura[Cont];
		cout<<endl;
		
		if(Altura[Cont] <= 1.3){
			ContAnoes++;
		}
		if(Cont == 0 || Altura[Cont] > MaiorAlt){
			MaiorAlt = Altura[Cont];
			MaiorAltNome = Nome[Cont];
		}
	}
	
	cout<<endl<<"Média das alturas: "<< SomaAlt/5<<endl; //estamos fazendo o calc aqui pois não iremos mais ultilizar a media.
	cout<<endl;
	cout<<"Quantidade de anões é "<<ContAnoes<<", e representam "<<100*ContAnoes/5<<"% da amostra"<<endl;
	cout<<endl;
	cout<<"A maior pessoa é a "<<MaiorAltNome<<" pessoa, com a Altura de: "<<MaiorAlt<<endl;
	
	Imprimir(Nome, Altura);
	
	
	/* =Tabuadas=
	cout <<"Qual número será a tabuada: ";
	cin >>Num;
	cout<<endl<<"-------------(FOR) Tabuada do "<< Num<< "-------------"<<endl;
	//com for - eu sei a quantidade de vezes que eu quero fazer
	for(Cont = 1; Cont<=10; Cont++){
		cout<< Num << " X " << Cont << " = " << Num*Cont << endl;
	}
	cout<< endl;
	
	//com while - repito 0 ou mais vezes (I.A)
	// se eu colocar 1, a condição sera eternamente verdadeira.
	cout<<endl<<"-------------(WHILE)Tabuada do "<< Num<< "-------------"<<endl;
	Cont = 1;
	while(Cont <= 10){
		//Cont++; - caso inicializar com 0, podemos fazer nesta ordem. porêm convenhamos, fica feio.
		cout<< Num << " X " << Cont << " = " << Num*Cont << endl;
		Cont ++; //sai como 11.
	}
	cout<< endl;
	
	//Do while - Qualquer Menu, repetir pelo menos uma vez!!
	cout<<endl<<"-------------(DO WHILE)Tabuada do "<< Num<< "-------------"<<endl;
	Cont =1;
	do{
		cout<< Num << " X " << Cont << " = " << Num*Cont << endl;
		Cont ++;
	}while(Cont <= 10);
	//++cont e cont++
	//se eu tenho comandos repetidos está errado!!
	

	*/
	return 0;
}
