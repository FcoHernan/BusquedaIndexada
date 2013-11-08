/* Sebastián Maureira Toledo */

#include<iostream>    
#include <stdio.h>
using namespace std;

    
int N, K;

void frecursiva(int numero, int indice, int longitud){
    int i;
    if (longitud==K) {
      cout << numero << endl;
    }
    else {
      for (i=indice; i<=N; i++){
        frecursiva(numero*10+i,i+1,longitud+1);	/* funcion que realiza la combinacion */
      }
    }
  }
  int main(int argc, char *argv[])
  {
	cout << "ingrese N:";
	cin >> N;		/* Ingresamos el elemento a combinar */
	cout << "ingrese K:";
	cin >> K;		/* Ingresamos el largo de la combinatoria */
    int i;
    for (i=1; i<N;i++){
      frecursiva(i,i+1,1);
	}
	 cin.get();
	 cin.get();
    }