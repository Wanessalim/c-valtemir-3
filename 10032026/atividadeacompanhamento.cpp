#include <iostream>
using namespace std;
/*
Faça uma função que retorne o valor total de uma compra acrescida dos impostos (ICMS e IPI).
 Como entrada,
  a função deve receber o valor da compra, 
  taxa de ICMS e taxa de IPI.
  A função deve ter 2 outros parâmetros passados por referência: Valor do ICMS e Valor do IPI. 
  Nestes dois últimos parâmetros devem ser retornados o valor de cada imposto calculado na função.
*/
float CalculoImpostos(float ValorCompra, float ICMS, float IPI,float *ValorICMS, float *ValorIPI){
	float Ret;
	*ValorICMS = ValorCompra*ICMS;
	*ValorIPI = ValorCompra*IPI;
	Ret = *ValorICMS + *ValorIPI  + ValorCompra;
	return Ret;
}

float ValorCompra = 10, ICMS = 0.1, IPI = 0.5;

int main(){
	setlocale(LC_ALL,"Portuguese");
	cout<<"Valores das taxas antes: "<<endl;
	cout<<"ICMS: "<<ICMS<< endl;
	cout<<"IPI: " << IPI<<endl;
	cout<<"Valor da compra: "<<ValorCompra<<endl;
	cout<<endl;
	cout <<"Resultado função: "<< CalculoImpostos(ValorCompra,ICMS, IPI ,&ICMS, &IPI)<<endl;
	cout<<"Valores das taxas Apos: "<<endl;
	cout<<"ICMS: "<<ICMS<< endl;
	cout<<"IPI: " << IPI;
	return 0;
}
