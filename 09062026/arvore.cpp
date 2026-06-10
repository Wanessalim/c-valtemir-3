#include <iostream>
using namespace std;

struct NoArv{ //estrutura do nó da arvore
	int Chave; 
	NoArv *Esq;
	NoArv *Dir;
};

struct Arvore{ //Equivalente ão cabeçalho da lista.
	int Quantidade;
	NoArv *Raiz;
};

void Ini_Arvore(Arvore *A){
	A->Quantidade = 0;
	A->Raiz = NULL;
}

/*
Arvore vazia -> perguntar se raiz == NULL
*/

NoArv *Cria_No(int Chave){ //Eu retorno um cara
	NoArv* Ret;
	Ret = (NoArv*) malloc(sizeof(NoArv));
	
	if(Ret != NULL){
		Ret->Chave = Chave;
		Ret->Esq = NULL;
		Ret->Dir = NULL;
	} 
	
	return Ret;
}

/*
Fuunção pra inserir manual
Passar o pai, o lado que eu quero inserir e o que eu vou inserir
NoArv *Insere_Manual(Arvore,No pai, Esquerda ou diretita, Chave);
obs: preciso que retorne pra pendurar os caba.

tipo: 
 se for E (Lado Esdquerdo)
 se for D (Lado Direito)
*/
NoArv *Insere_Manual(Arvore *A, NoArv *Pai, int Chave, string Tipo){
	NoArv *Ret;
	//toda vez que inserir algum, eu crio o bendito nó
	Ret = Cria_No(Chave);
	
	if(Ret != NULL){
		if(A->Raiz == NULL){
			A->Raiz = Ret;
			A->Quantidade ++;
		}else{// cria um nó descendente
			if(Pai != NULL){
				if(Tipo == "E"){
					Pai->Esq = Ret;
				}else{
					Pai->Dir = Ret;
				}
				A->Quantidade ++;
			}else{
				cout<< "Pai não informado"<<endl;
			}
		}
		
	}
	
	return Ret;
}
//  Impressão basica, posso passar qualquer nó

void Imprime(NoArv *No, string Tipo){
	if(No!= NULL){
		if(Tipo == "PRE"){
			cout<< No->Chave << ",";
		}
		Imprime(No->Esq, Tipo);
		if(Tipo == "CEN"){
			cout<< No->Chave << ",";
		}
		Imprime(No->Dir, Tipo);
		if(Tipo == "POS"){
			cout<< No->Chave << ",";
		}
		
	}
} 

Arvore A;
NoArv *Esq, *Dir;
int main(){
	Ini_Arvore(&A);
	Insere_Manual(&A, NULL, 1, "");
	Esq = Insere_Manual(&A, A.Raiz, 2, "E"); 
	Esq = Insere_Manual(&A, Esq, 4, "E");
	Esq = Insere_Manual(&A, Esq, 7, "E");
	Insere_Manual(&A, Esq, 10, "E"); 
	Insere_Manual(&A, Esq, 11, "D");   
	
	
	Dir = Insere_Manual(&A, A.Raiz, 3, "D");
	Insere_Manual(&A, Dir, 5, "E");
	Dir = Insere_Manual(&A, Dir, 6, "D");
	Esq = Insere_Manual(&A, Dir, 8, "E");
	Insere_Manual(&A, Esq, 12, "E");
	Insere_Manual(&A, Dir, 9, "D");  
	
	
	
	
	
	//mergulhando no lado do 2
	cout<<"Pre- Ordem: ";
	Imprime(A.Raiz, "PRE");
	cout<<endl;
	cout<<"Ordem-Central: ";
	Imprime(A.Raiz, "CEN");
	cout<<endl;
	cout<<"Pos- Ordem-: ";
	Imprime(A.Raiz, "POS");
	cout<<endl;
	
	
	
	return 0;
}
