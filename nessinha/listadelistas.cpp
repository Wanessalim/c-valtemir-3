#include <iostream>
using namespace std;

struct Dados{
	int Id;
	float Valor;
	Dados* Prox;
};

struct Lista{
	Dados* Ini;
	int Qtd;
	float Valores;
};
 
void Ini_Lista(Lista* L){
	L->Ini = NULL;
	L->Qtd = 0;
	L->Valores = 0;
}

Dados* Cria_Elemento(int Id, float Valor){
	Dados* Ret;
	Ret = (Dados*)malloc(sizeof(Dados));
	if(Ret != NULL){
		Ret->Id = Id;
		Ret->Valor = Valor;
		Ret->Prox = NULL;
	}
	return Ret;
}

Dados* Insere_Elemento(Lista* L, int Id, float Valor){
	Dados* Ret;
	Ret = Cria_Elemento(Id, Valor);
	if(Ret != NULL){
		Ret->Prox = L->Ini;
		L->Ini = Ret;
		L->Qtd ++;
		L->Valores = L->Valores + Valor;
	}
	return Ret;
}

Dados* Remover_Elem(Lista *L, Dados *D, int Id){
	Dados *Ret;
	if (D != NULL){
		Ret = D;
		if(D->Id == Id){   
		   Ret = D->Prox;
		   
		   if(D == L->Ini){
		   		L->Ini = Ret;
		   } 
		   
		   L->Qtd--;
		   L->Valores = L->Valores - D->Valor;
		   free(D);			
		}
		else{
			D->Prox = Remover_Elem(L, D->Prox, Id);
		}		
	}
	else{
		Ret = NULL;
	}
	
	return Ret;
}

void Imprime_Lista(Lista *L, Dados *D){
	if (D != NULL){
		cout << "Id: "<<D->Id << endl;
		cout << "Preço unitário: "<< D->Valor << endl << endl;	
		Imprime_Lista(L, D->Prox);	
	}
		
}

int CalculaTam(Lista *L, Dados *D){
	int Ret = 0;
	if (D != NULL){
		Ret = 1 + CalculaTam(L, D->Prox);	
	}
	return Ret;
		
}

int CalcularOcorrencia(Lista *L, Dados *D, int Id){
	int Ret;
	if (D != NULL){
		if(D->Id == Id){
			Ret = 1 + CalcularOcorrencia(L, D->Prox, Id);
		}else{
			Ret = CalcularOcorrencia(L, D->Prox, Id);
		}
	}
	return Ret;		
}

void TrocaOcorrencia(Lista *L, Dados *D, int Id, int NovoId, float NovoValor){
	if (D != NULL){
		if(D->Id == Id){
			D->Id = NovoId;
			D->Valor = NovoValor;
		}	
		TrocaOcorrencia(L, D->Prox, Id, NovoId, NovoValor);
	}	
}


void DivideLista(Dados* D, int N, Lista* Maiores, Lista* Menores) {

    if (D != NULL  ) {
        if (D->Id < N) {
        	Insere_Elemento(Menores, D->Id, D->Valor);
        } else {
        	Insere_Elemento(Maiores, D->Id, D->Valor);
        }
        DivideLista(D->Prox, N, Maiores, Menores);
    }else{
    	
	}
}

Lista* EscolhaLista(Lista* L1, Lista *L2){
	Lista* Ret;
 	int Escolha;
 	cout<<"Escolha a Lista desejada: "<<endl;
 	cout<<"1 -Lista 1 "<<endl;
 	cout<<"2- Lista 2 "<<endl;
 	cout<<"Escolha: ";
 	cin>>Escolha;
 	if(Escolha == 1){
 		Ret = L1;
	 }else{
	 	Ret = L2;
	 }
 	return Ret;
 }

void Menu(Lista* L1, Lista* L2){
	int Escolha,a;
	Lista* EscolherL;
	do{
		system("cls");
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
		cin>> Escolha;
		system("cls");
		
		
		switch(Escolha){
			case 1:
				cout<<"Você escolheu Inserir"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				Insere_Elemento(EscolherL, 1, 1.2);
				Insere_Elemento(EscolherL, 2, 6.3);
				Insere_Elemento(EscolherL, 5, 1.3);
				Insere_Elemento(EscolherL, 6, 1.7);
				break;
				
			case 2:
				cout<<"Você escolheu Remover"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				Remover_Elem(EscolherL, EscolherL->Ini, 3);
				break;
				
			case 3:
				cout<<"Você escolheu Imprimir"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				Imprime_Lista(EscolherL, EscolherL->Ini);
				system("pause");
				break;
				
			case 4:{
				cout<<"Você escolheu Calcular comprimento das listas"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				int Calc = CalculaTam(EscolherL, EscolherL->Ini);
				cout<<Calc <<endl;
				system("pause");
				break;
			}
				
				
			case 5:{
				cout<<"Você escolheu Contar ocorrencias de um numero em uma lista"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				int CalcO = CalcularOcorrencia(EscolherL, EscolherL->Ini, 2);
				cout<< CalcO <<endl;
				system("pause");
				break;
			}
				
				
			case 6:{
				cout<<"Você escolheu Substituir ocorrencias de um numero em uma lista"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				TrocaOcorrencia(EscolherL, EscolherL->Ini, 3, 2, 1.2);
				break;
			}
				
				
			case 7:{
				cout<<"Você escolheu Dividir uma lista em duas"<< endl;
				EscolherL = EscolhaLista(L1, L2);
				Lista Maior, Menor;
				DivideLista(EscolherL->Ini, 4, &Maior, &Menor);
				
				Imprime_Lista(&Menor, Menor.Ini);
				cout<<endl; //ta pegando um 0
				
				Imprime_Lista(&Maior, Maior.Ini);
				cout<<endl; // ta pegando numeros de sei la onde
				
				break;
			}
				
				
			case 8:
				cout<<"Você escolheu Interseção das listas"<< endl;
				break;
				
			case 0:
				cout<<"Saindo..."<< endl;
				break;
			
			default:
				cout<<"Numero invalido"<< endl;
		}
	}while(Escolha != 0); 
}

Lista L1, L2;
int main(){
	setlocale(LC_ALL,"Portuguese");
	Menu(&L1, &L2);
	return 0;
}
