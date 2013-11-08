/* Sebasti�n Maureira Toledo */

#include <iostream> 
using namespace std;
 
void Permutaciones(char *, int l=0); 

int main(int argc, char *argv[]) {
   char palabra[1000];
   cout << "Ingrese las variables a permutar (Ej: 'ABCD'):" << endl;
   cin >> palabra;	 /* Ingreso del valor a permutar en el arreglo palabra*/
   Permutaciones(palabra);
   cin.get();
   cin.get();
   return 0;
}

/*Funci�n para las permutaciones*/
void Permutaciones(char * cad, int l) {
   char c;    /* variable auxiliar para intercambio */
   int i, j;  /* variables para bucles */
   int n = strlen(cad);
  

   for(i = 0; i < n-l; i++) {
      if(n-l > 2) Permutaciones(cad, l+1);
      else cout << cad << ", ";
      /* Intercambio de posiciones */
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == n-1) {
         for(j = l; j < n; j++) cad[j] = cad[j+1];
         cad[n] = 0;
      }
   }
}

