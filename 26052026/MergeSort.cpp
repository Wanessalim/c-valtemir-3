#include <iostream>
using namespace std;
//teste
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    
    //------------Divisão------------
    
    if(posicaoInicio == posicaoFim) return; //sem return em função void. Resolver com If(Inicio < Fim)
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2; //busco metade do tamanho do vetor/ lista

    mergeSort(vetor, posicaoInicio, metadeTamanho); //Primeira Metade do vetor
    mergeSort(vetor, metadeTamanho + 1, posicaoFim); //Segunda metade do vetor
    
 	//-----------Conquista-----------
 	 
    i = posicaoInicio; //Vetor A
    j = metadeTamanho + 1; //Vetor B
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1)); //Vetor dinâmico para não estourar memoria.

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) { // i representa inicio, 
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

int main(){
	return 0;
}
