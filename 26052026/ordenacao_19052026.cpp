#include <iostream>
#include <time.h>

#define MAX 100000

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
            L[Cont].Valor = rand()%100; //menores que 100
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
        FezSwap = 0;    
        //Traz, a partir do fim da lista, cada menor valor
        //até achar algum valor maior que ele. Se achar,
        //passa a fazer o mesmo com esse novo valor
        for (Cont2=Tam-1;Cont2>Cont1;Cont2--) {        
            if (L[Cont2].Valor < L[Cont2-1].Valor){
                //Troca os valores de posição
                Swap(L, Cont2, Cont2-1);
                FezSwap = 1;            
            }        
        }        
        
        Cont1++;                    
    } while (Cont1<Tam && FezSwap==1);
}

Dados Lista[MAX];
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
	InsertionSort(Lista, MAX);
	
    T = clock() - T;//tempo decorrido!!
     
    if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    cout << endl << endl << "Tempo de Ordenação: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
	
	return 0;
}
