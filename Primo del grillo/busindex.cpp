
/*
 * Programa: busca.c
 *
 * Programa muestra de una busqueda secuencial, binaria y sequencial indexada
 *
 * Autor: Jesús Manuel Mager Hois
 * Materia: Informática III
 * Facultad de Contaduría y Administración
 * UNAM
 * 
 * Licencia GPL 3 o superior
 * 2009
 *
 */
 
#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 50000
#define MAX_IND 50000

using namespace std;

typedef struct index{
 int valor;
 int pos;
}index;

// Funciones de utilidad

void quick_sort(int v[], int size);
void q_sort(int v[], int left, int right);


// Devuelve la posición int del arreglo de enteros v de tamaño tam entero
int b_secuencial(int v[], int tam, int buscar);
int b_binaria(int v[], int tam, int buscar);
int index_creator(int tam);
int b_secindexada(int v[], int tam, int buscar);

int main (int argc, char * argv[]){

 int v[TAM];
 int i;
 int pos;
 int temp;
 clock_t start, end, ini, fin, empezar, acabar;
 double tiem, min, seg;

 printf("********* Programa demostrar algoritmos de ordenamiento *********\n");

 printf("Números generados en el vector: ");
 for(i=0; i<TAM; i++){
  v[i]=rand()%5000;
  printf("%d ",v[i]);
 }
  

 printf("\nNúmero a buscar?");
 scanf("%d", &temp);

 printf("\n# Por búsqueda secuencial ");
 start = clock();
 if((pos=b_secuencial(v, TAM, temp))!=-1)
  printf("%d se encuenra en la posición: %d\n", temp, pos);
 else
  printf("%d no se encuentra en la lista", temp);
  end = clock();
  tiem = (double)(end - start) / CLOCKS_PER_SEC;
  ini = clock();
 printf("\nOrdenando la lista.... (Quicksort)");
 printf("\nEl vector ordenado es: ");

 quick_sort(v, TAM);

 for(i=0; i<TAM; i++)
  printf("%d ", v[i]);
 printf("\n");

 printf("\n# Por búsqueda binaria  ");

 if((pos=b_binaria(v, TAM, temp))!=-1)
  printf("%d se encuenra en la posición: %d\n", temp, pos);
 else
  printf("%d no se encuentra en la lista", temp);

 if((pos=b_secindexada(v, TAM, temp))!=-1)
  printf("%d se encuenra en la posición: %d\n", temp, pos);
 else
  printf("%d no se encuentra en la lista\n", temp);
  fin = clock();
  min = (double)(fin - ini) / CLOCKS_PER_SEC;
  cout << "la busqueda demoro: " << tiem << endl;
  cout << "la busqueda index demoro: " << min << endl;


 printf("\n ****************** Fin del Programa *******************\n");

   system("pause");
 //return 0;
system("pause");
// cin.get();
 //cin.get();
}

/*
 * Funciones de utilidad para ordenar mediante
 * Quicksort
 */

void quick_sort(int v[], int size)
{
 q_sort(v, 0, size-1);
}

void q_sort(int v[], int left, int right)
{

 int pivot, lTmp, rTmp;
 lTmp=left;
 rTmp=right;
 pivot=v[left];

 while ( left < right )
 {
  while((v[right] >= pivot) && (left < right))
   right--;
  if(left != right)
  {
   v[left]=v[right];
   left++;
  }
  while ((v[left] <= pivot) && (left<right))
   left++;
  if(left!=right)
  {
   v[right]=v[left];
   right--;
  }
 }
 v[left]=pivot;
 pivot=left;
 left=lTmp;
 right=rTmp;

 if(left<pivot)
  q_sort(v, left, pivot-1);
 if(right>pivot)
  q_sort(v, pivot+1, right);
}

/*
 * Función que recorre el vector sin ordenar en busca
 * del valor deseado. 
 * Devuelve la posición o -1 si no existe el valor
 * en el vector.
 */

int b_secuencial(int v[], int tam, int buscar){
 int i;

 for(i=0; i<tam; i++)
  if(v[i]==buscar)
   return i;
 return -1;
}

/*
 * Función que busca un elemento en una lista ordenada
 * partiendo la lista en dos, descartando la mitad de la lista 
 * donde no se puede encontrar el valor buscado, y así 
 * sucesivamente.
 * Devuelve la posición del valor en el vector o -1 si 
 * no se encontró el valor.
 */

int b_binaria(int v[], int tam, int buscar){

 int ini=0;
 int fin=tam;
 int centro;

 while (ini<=fin){
  centro=((ini+fin)/2);

  if (v[centro] == buscar)
   return centro;

  if (buscar<v[centro])
   fin=centro-1;
  else
   ini=centro+1;
 }
 return -1;
}

/*
 * Función que busca un intervalo adecuado para el índice
 */

int index_creator(int tam){
 
 int i;

 printf("El tamaño del arreglo es %i", tam);

 if (tam<=1000){
  for(i=5; i<=30; i++)
   if(tam%i==0 && tam!=i)
    return i;
  for (i=5; i>=3; i--)
   if(tam%i==0 && tam!=i)
    return i;
  return -1;
 }
 else if(tam>1000 && tam < 99999){
  for(i=20; i<99; i++)
   if(tam%i==0 && tam!=i)
    return i;
  return -1;
 }
}

/* Función que realiza una búsqueda secuencial indexada
 * Primero busca un intervalo para el indice, luego
 * general el ínidce.
 * Una vez teniendo el ínidice realiza una búsqueda 
 * en secuencial en el ínidce, para posteriormente encontrar
 * las claves entre las cuales realizar otra búsqueda
 * secuencial y asi encontrar la posición que se devuele.
 * Si no existe el valor en el vector se devuelve -1.
 * El vector tiene que estar ordenado.
 */

int b_secindexada(int v[], int tam, int buscar){

 int intervalo;
 int i;
 int j=0;
 int tam_ind=0;
 index indice[MAX_IND];

 printf("\nGenerando el indice:\n");

 intervalo=index_creator(tam);
 if(intervalo==-1){
  printf("\nNo se encontró un intervalo adecuado... abortando...\n");
  return -1;
 }

 printf("\nEl intervalo es: %d\n", intervalo);

 for(i=0; i<=tam; i=i+intervalo){
  indice[tam_ind].pos=i;
  indice[tam_ind].valor=v[i];
  tam_ind++;
 }

 for(i=0; i<tam_ind; i++)
  printf("\n %d, %d", indice[i].pos,indice[i].valor);

 printf("\n");
 
 for(i=0; i<tam_ind; i++)
 {
  printf("La posición es: %d\n",indice[i].pos);
  if(indice[i].valor>=buscar)
  {
   printf("Estamos buscando %d entre %d a %d \n", buscar, indice[i].pos-intervalo, indice[i].pos);
   for(j=(indice[i].pos-intervalo); j<=indice[i].pos; j++)
   {
    printf("Estamos buscando %d en %d:%d \n", buscar, j, v[j]);
    if(v[j]==buscar)
    {
     return j;
    }
   }
  }
 }
 return -1;
}
