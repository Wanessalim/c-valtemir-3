#include <iostream>
using namespace std;
//lista  encadeada sem ordem
// sentinha é ponteiro de estrutura
/*
o cara novo aponta por inicio, e o inicio aponta pra ele.

*/
struct aluno{
	int pront;
	aluno *prox; //ponteiro que aponta para um dado do tipo aluno, e todo aluno tem um ponteiro.
};

aluno * CriaAluno(int pront){ //criando um novo elemento de struct, forninho hihi :3
	aluno *pt;
	
	pt = (aluno*)malloc(sizeof(aluno));
	
	if(pt != NULL){
		pt->pront = pront; // detalhe importante
		pt->prox = NULL;
	}
	return pt;
}

aluno * InsereAluno(aluno *Ini, int pront){ // imperativa
	aluno *Pt;
	
	Pt = CriaAluno(pront);
	Pt->prox = Ini;
	
	return Pt;
}

void ImprimeAluno(aluno *Ini){
	
	if(Ini != NULL){
		// se colocar imprimir aqui inverte a funçaõ :)
		cout<< Ini->pront<< endl;
		ImprimeAluno(Ini->prox);
	}	
}
/*
i(a) = mostrar A e i(a->prox)
*/

//aluno lista[10]; ==> lista estatíca
aluno *Inicio; // dois ponteiros
int main(){
	
/*	Pt = (aluno*)malloc(sizeof(aluno));
	Pt->pront = 2;
	Pt->prox = NULL;
	Inicio->prox = Pt; // o segundo cara aponta pro inicio
	aux = Pt; //guardando a memoria
	
	
	Pt = (aluno*)malloc(sizeof(aluno));
	Pt->pront = 3; // acesso ao ultimo
	Pt->prox = NULL;
	//Inicio->prox = pt;
	aux->prox = Pt; */
	
	Inicio = InsereAluno(Inicio, 1); //acesso ao primeiro
	Inicio= InsereAluno(Inicio, 2); // dois aponta pro 1 e o 2 vira o inicio
	Inicio = InsereAluno(Inicio, 3); // tres aponta por 2 e 3 vira o inicio
	
	
	//mostrando lista
	/*
	cout<< Inicio->pront<< endl;
	cout<< Inicio->prox->pront<< endl; // esta notação permite o não uso do aux
	//cout<<Pt->pront;
	cout<< Inicio->prox->prox->pront; //alma da lista encadeada!!
	*/
	ImprimeAluno(Inicio); // o ultimo que entra é o primeiro que sai. ==> começa pelo ultimo.
	
	

	return 0;
}
