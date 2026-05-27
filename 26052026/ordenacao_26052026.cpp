#include <iostream>
#include <time.h>

#define MAX 10

using namespace std;

struct Dados{
    int Valor;
    int Ordem;
};

//Carrega o vetor com valores aleatórios
void CarregaLista(Dados *L){
    int Cont;
    
    if (MAX>10){
        for(Cont=0;Cont<MAX;Cont++){ 
            L[Cont].Valor = rand()%100; //menores que 100 aleatorios
            L[Cont].Ordem = Cont;
        }        
    }
    else{
       L[0].Valor = 3; L[1].Valor = 3; L[2].Valor = 1; L[3].Valor = 2; L[4].Valor = 7;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        L[5].Valor = 0; L[6].Valor = 5; L[7].Valor = 4; L[8].Valor = 9; L[9].Valor = 6;
        L[5].Ordem = 5; L[6].Ordem = 6; L[7].Ordem = 7; L[8].Ordem = 8; L[9].Ordem = 9;
		/*L[0].Valor = 5; L[1].Valor = 4; L[2].Valor = 3; L[3].Valor = 2; L[4].Valor = 1;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;*/         
    }    
}

void ImprimeLista(Dados *L){
    int Cont;
    
    for(Cont=0;Cont<MAX;Cont++){
        cout <<    "[" << L[Cont].Ordem << "] " << L[Cont].Valor << ", ";
    }        
}

void Swap(Dados *L, int Origem, int Destino){
    Dados Aux;
    
    Aux = L[Origem];
    L[Origem] = L[Destino];
    L[Destino] = Aux;    
}

void SelectionSort(Dados *L, int Tam){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        //Procura o valor mínimo na lista não ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min].Valor > L[Cont2].Valor){
                Min = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);
    }                
}

void InsertionSort(Dados *L, int Tam){
    int Cont1, Cont2;
    
    for(Cont1=1;Cont1<Tam;Cont1++){
        Cont2 = Cont1; //Próximo item da lista não ordenada
        
        //Move o próximo item da lista não ordenada para
        //a posição correta na lista ordenada
        while (Cont2 > 0 && L[Cont2].Valor < L[Cont2-1].Valor ) {        
            //Move o valor encontrado pra lista ordenada
            Swap(L, Cont2, Cont2-1);
            
            Cont2--;    
        } 
    }                
}

void BubbleSort(Dados *L , int Tam){
    int Cont1, Cont2, FezSwap;
    
    Cont1=0;
    do{    
        FezSwap = 0; //indica movimentação 
        for (Cont2=Tam-1;Cont2>Cont1;Cont2--) {        
            if (L[Cont2].Valor < L[Cont2-1].Valor){
                //Troca os valores de posição
                Swap(L, Cont2, Cont2-1);
                FezSwap = 1;            
            }        
        }        
        
        Cont1++;                    
    } while (Cont1<Tam && FezSwap==1); //controla subvetor dos ordenados
} 

void MergeSort(Dados* Lista, int Inicio, int Fim){ //precisa ser inicio e fim, pra não ser bruto. 
	int Meio,Cont ,ContA, ContB;
	/*
	Cont Conta gravação do vetro auxiliar
	Vetor A que tem ContA
	...
	*/
	Dados* Auxiliar;
	if(Inicio < Fim){
		//-----dividir-----
		Meio = (Inicio + Fim)/2;
		MergeSort(Lista, Inicio, Meio);
		MergeSort(Lista, Meio + 1, Fim);
		
		//----Conquistar----
		/*
		1. Têm que ser o bakctracking
		!Não usar swap bruto.
		2. Vetor Dinamico (A, B, Auxiliar)
		*/
		ContA = Inicio; //Vetor maior (A) - Esquerdo
		ContB = Meio+1; //Vetor Menor (B) - Direito
		Cont = 0; //Vetor Auxiliar
		
		//Criando o vetor auxiliar
		Auxiliar = (Dados*)malloc(sizeof(Dados) * (Fim - Inicio + 1)); // não entendi a contagêm:(
		while(ContA <= Meio || ContB <= Fim){ //Preenche vetor Auxiliar
			if(ContA > Meio){ //Acabou o vetor A, Começamos a usar o vetor b
				//O que esta em B vai pro auxiliar.
				Auxiliar[Cont] = Lista[ContB];
				ContB ++;
			}else{
				if(ContB > Fim){ //Acabou vetor B
				
					Auxiliar[Cont] = Lista[ContA];
					ContA++;
				}else{
					//!!!!!Critério de ordenação!!!!
					if(Lista[ContA].Valor < Lista[ContB].Valor){ //Garante que seja crescente
						Auxiliar[Cont] = Lista[ContA];
						ContA++;
					}else{
						Auxiliar[Cont] = Lista[ContB];
						ContB ++;
					}
				}
				
			}
			Cont++;
		}
		//copia valores do vetro auxiliar para vetor principal. Aqui eu zerei o Cont, e mudei sua função.
		for(Cont = Inicio; Cont <= Fim; Cont++){
			Lista[Cont].Valor = Auxiliar[Cont - Inicio].Valor;
			Lista[Cont].Ordem = Auxiliar[Cont - Inicio].Ordem;
		}
		free(Auxiliar); //se não usar vai travar tudo.
	}	
}

Dados Lista[MAX]; //lista estatica pra facilitar entendimento de lógica
clock_t T;
int main(){
	setlocale(LC_ALL, "Portuguese");
	CarregaLista(Lista);
	
	if (MAX <= 100){
        cout << endl << endl << "Lista original" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    T = clock();
    
	//SelectionSort(Lista, MAX);
	//InsertionSort(Lista, MAX);
	//BubbleSort(Lista, MAX);
	MergeSort(Lista, 0, MAX-1);

	
	
    T = clock() - T;//tempo decorrido!!
     
    if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    cout << endl << endl << "Tempo de Ordenação: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
	
	return 0;
}
