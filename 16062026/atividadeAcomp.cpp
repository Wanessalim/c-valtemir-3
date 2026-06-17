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



//Implemente uma função recursiva para calcular o NÍVEL de qualquer nó de uma árvore binária.

/*
Impressão - a cada passada da raiz ate o nó, conta nivel.
lógica comça na raiz -- a cada descida até o nó ++.
obs: não conta raiz, -- a cada chamada recursiva não nula conta
pre - conta raiz...
pos - raiz por utlimo.

parar quando não tiver pai.

percorrer arvore do no desejado ate a raiz...
*/

/*
Implemente uma função para imprimir APENAS os valores dos nós de uma árvore binária que possuam EXATAMENTE 2 filhos.
*/
void ImprimeApenasPaiDeDois(NoArv *No){
	if(No!= NULL){
		if(No->Dir != NULL && No->Esq != NULL){
			cout<< No->Chave << ",";
		}
		ImprimeApenasPaiDeDois(No->Esq);
		ImprimeApenasPaiDeDois(No->Dir);
		
	}
} 


Arvore A;
NoArv *Esq, *Esq2, *Dir;
int Nivelcalculado;
int main(){
	setlocale(LC_ALL, "Portuguese");
		
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
	
	//Pré-Ordem: 1, 2, 4, 7, 10, 11, 3, 5, 6, 8, 12, 9
	Imprime(A.Raiz, "PRE");
	cout << endl;
	
	ImprimeApenasPaiDeDois(A.Raiz);
	return 0;
}

