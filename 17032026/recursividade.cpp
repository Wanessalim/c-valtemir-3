#include <iostream>
using namespace std;
//rebvisão função com retorno

string funcao1(string Msg, string Nome,int* Tam){// função com retorno
	string Ret;
	
	Ret = Msg + "," +Nome;
	*Tam = 2; // isso não muda a varuavel.
	cout<<*Tam<<endl;
	
	return Ret;
}
//recursão precisa
/*
1 chamar a si mesmo, inicalizar a variavel
2 condição de saída
3.  variavel na condição alterada na recursão
*/
void funcao2(string Saida){ //equivalente a um while(1){}
	if(Saida != "s"){ //condição de saída
		cout<<"Aló mundo"<<endl;
		cout<<"Sair?";
		cin>>Saida;
		funcao2(Saida); //recursão direta
	}
}

//recursividade não é para interface!!
//chamada direta
void Contagem(int Cont){
	if(Cont  <= 10){
		Contagem(Cont + 1); //bakctraking-  processamento após a chamada recursiva
		//cout <<Cont<< endl;
	}
	
}

void ContagemPR(int Cont, int *ContChamadas){
	
	if(Cont  <= 10){
		cout <<Cont<< endl;
		(*ContChamadas) ++;
		ContagemPR(Cont + 1, ContChamadas); 
	}
}

void ContagemPRB(int Cont, int *ContChamadas){
	
	if(Cont  <= 10){
		ContagemPRB(Cont + 1, ContChamadas); 
		cout <<Cont<< endl;
		(*ContChamadas) ++;
	}else{
		(*ContChamadas) = 0;
	}
}

int ContagemRB(int Cont){ // importante!!
	int ContChamadas;
	
	if(Cont  <= 10){
		ContChamadas = ContagemRB(Cont + 1) + 1; 
		cout <<Cont<< endl;
	}else{
		ContChamadas = 0;
	}
	return ContChamadas;
}

//chamada indireta --deadlock(pesadelo no programa)
void F1();
void F2(){
	cout<<"Hello World!"<<endl;
	F1();
}
void F1(){
	F2();
}
//Fatorial *Brilhos*
/*
fat(5) = 5*4*3*2*1;
fat(5) = 5 * fat(4);
fat(4) = 4 * fat(3);
...
Fat(N) = N * fat(N -1);
Fat(0) = 1;
*/

int Fat(int N){
	int Ret, Cont;
	
	Ret = 1;
	for(Cont=N;Cont>=1;Cont--){
		Ret = Ret*Cont;
	}
	return Ret;
}

int FatR(int N){
	int Ret;
	if(N >= 1){
		Ret = N * FatR(N - 1); // Fat(N) = N * fat(N -1);
		//Ret = FatR(N - 1)* N; // com backtraking - não faz diferença neste caso!! 
	}else{
		Ret = 1; //não pode ser 0
	}
	return Ret;
}
//fibonacci -- Fn = F(n-1) + f(n - 2)
//looping
int Fibloop(int N){
	int Prox, Ant, Atual,Cont;
	if(N == 0 || N == 1){
		Prox = N;
	}else{
		Ant = 0;
		Atual = 1;
		for(Cont=2; Cont<=N; Cont++){
			Prox = Ant + Atual;
			Ant = Atual;
			Atual = Prox;
		}
	}
	return Prox;
}
//Recursivo - Fn = F(n-1) + f(n - 2)
int FibLoop(int N){
	int Ret;
	if(N == 0 || N == 1){
		Ret = N;
	}else{
		Ret = FibLoop(N - 1) + FibLoop(N - 2);
	}
	return Ret;
}


string R;
int Tam = 8;
int main(){
	setlocale(LC_ALL,"Portuguese");
	
	/* // revisao sobre retorno de função e passagem por referencia
	R = funcao1("Vai Brasil", "Nessinha", &Tam); // chamando a funçao para ela funcionar
	cout<<Tam<<endl;
	cout<< R;
	*/
	/*
	rev rapida repetição
	1. condição de saida
	2. inicializar variaveol na condição
	3. variavel na condiçãoa alt
	*/
	
	//funcao2(" ");//inicialização
	//Contagem(5);
	
	//ContagemPR(-15, &Tam);

	//ContagemPRB(-15, &Tam);
	
	//Tam = ContagemRB(5);
	//cout<<endl;
	//cout<<"Tam: "<<Tam;
	
	//F2();
	//-----fatorial-----
	//int i = FatR(5);
	//cout << i;
	//-----Fibonacci
	int F = Fibloop(6);
	cout << F<<endl;
	cout<<endl;
	int Fl = FibLoop(6);
	cout<< Fl <<endl;
	return 0;
}
