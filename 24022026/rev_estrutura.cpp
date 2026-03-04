#include <iostream>

using namespace std;

struct Pessoa{
	string Nome;
	double Altura;
};

void Cadastrar(Pessoa[]){
	int Cont;

	for (Cont=0;Cont<5;Cont++){
		system("cls");
		cout << "Pessoa "<<Cont<<":"<< endl;
		cout << "Nome: ";
		cin >> Pessoa[Cont].Nome;
		cout << "Altura: ";
		cin >>Pessoa[Cont].Altura;
	}
}

void Imprimir(Pessoa[]){
	int Cont;
	
	system("cls");
	for (Cont=0;Cont<5;Cont++){
		cout << "Pessoa "<<Cont<<":"<< endl;
		cout << "Nome: "<<Pessoa[Cont].Nome << endl;
		cout << "Altura: "<<Pessoa[Cont].Altura << endl;
	}
}

void Processamento(Pessoa[]){
	int Cont, ContAnoes;
	double SomaAlt, MaiorAlt;
	string NomeMaiorAlt;
	
	SomaAlt=0;
	ContAnoes = 0;
	for (Cont=0;Cont<5;Cont++){		
		SomaAlt = SomaAlt + Pessoa[Cont].Altura;
		
		if (A[Cont] <= 1.3){
			ContAnoes++;	
		}
		//SomaAlt += Altura;
		//Maior altura: primeiro da amostra OU atualiza quando a altura lida
		//for maior que o da variável de armazenamento
		if(Cont==0 || Pessoa[Cont].Altura > MaiorAlt){//Atualiza
			MaiorAlt = Pessoa[Cont].Altura;
			NomeMaiorAlt = Pessoa[Cont].Nome;
		}
	}
	cout << endl << "Média das alturas: " << SomaAlt/5;
	cout << endl << "Qtde de anões: " << ContAnoes << " e representam " << 100*ContAnoes/5 <<"% da amostra.";
	cout << endl << NomeMaiorAlt << " tem a maior altura (" << MaiorAlt << ")";
}

double Media(Pessoa[].Altura){
	int Cont;
	double SomaAlt;
	
	SomaAlt=0;

	for (Cont=0;Cont<5;Cont++){		
		SomaAlt = SomaAlt + Pessoa[Cont].Altura;
	}
	
	return SomaAlt/5;
}

int Num;
double Altura[5], MediaAlt;
string Nome[5];
Pessoa P[5];
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	/*
	cout << "Qual número será a tabuada: ";
	cin >> Num;
	cout << endl << "-------- (WHILE) TABUADA DO " << Num << " --------"<< endl << endl;

	//WHILE - repetir 0 ou mais vezes (I.A.)
 	//DO WHILE  - repetir 0 ou mais vezes (Menu)
	//FOR - repetir N vezes ( ou saber início e fim)
	
	//WHILE
	Cont = 1;
	while(Cont <=10){
		cout << Num << " X "<< Cont <<" = "<< Num*Cont << endl;
		Cont = Cont+1;	
	}
	
	Cont = 1;
	cout << endl << "-------- (DO WHILE) TABUADA DO " << Num << " --------"<< endl << endl;	
	do{
		cout << Num << " X "<< Cont <<" = "<< Num*Cont << endl;
		Cont = Cont+1;
	}while(Cont <=10);
	
	cout << endl << "-------- (FOR) TABUADA DO " << Num << " --------"<< endl << endl;	
	for(Cont = 1;Cont<=10; Cont++){
		cout << Num << " X "<< Cont <<" = "<< Num*Cont << endl;
	}
	*/

	
	Cadastrar(P);
	Imprimir(P);
	//Processamento(Nome, Altura);
	MediaAlt = Media(Altura);
	cout << endl << "Média das alturas: " << Media(Altura);//MediaAlt;

	return 0;
}
