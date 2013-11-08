#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 100000
#define MAX_IND 100000

using namespace std;

typedef struct index
{
        int valor;
        int pos;
}index;

// Funciones de utilidad

void quick_sort(int v[], int size);
void q_sort(int v[], int left, int right);


// Devuelve la posici�n int del arreglo de enteros v de tama�o tam entero

int b_secuencial(int v[], int tam, int buscar);
int b_binaria(int v[], int tam, int buscar);
int index_creator(int tam);
int b_secindexada(int v[], int tam, int buscar);

int main (int argc, char * argv[])
{
    //int TAM, MAX_IND;
    int v[TAM];
    int i;
    int pos;
    int temp;
    clock_t start, end, ini, fin, empezar, acabar;
    double tiem, min, seg;

    cout << "********* Programa demostrar algoritmos de ordenamiento *********" << endl;
    //cout << "Ingrese el tama�o del vector: ";
    //cin >> TAM, MAX_IND;
    printf("N�meros generados en el vector: ");
    for(i=0; i<TAM; i++)
    {
             v[i]=rand()%5000;
             cout << " " << v[i];
    }
    cout << endl << "N�mero a buscar: ";
    cin >> temp;
    cout << "# Por b�squeda secuencial ";
    start = clock();
    if((pos=b_secuencial(v, TAM, temp))!=-1)
           cout << temp << " se encuenra en la posici�n: " << pos << endl;
    else
           cout << temp << " no se encuentra en la lista";
    end = clock();
    tiem = (double)(end - start) / CLOCKS_PER_SEC;
    ini = clock();
    cout << endl << "Ordenando la lista.... (Quicksort)";
    cout << endl << "El vector ordenado es: ";
    quick_sort(v, TAM);
    for(i=0; i<TAM; i++)
           cout << v[i];
           cout << endl;
    //printf("\n# Por b�squeda binaria  ");
    //if((pos=b_binaria(v, TAM, temp))!=-1)
           //printf("%d se encuenra en la posici�n: %d\n", temp, pos);
    // else
           //printf("%d no se encuentra en la lista", temp);
    if((pos=b_secindexada(v, TAM, temp))!=-1)
           cout << temp << " se encuenra en la posici�n: " << pos << endl;
    else
           cout << temp << " no se encuentra en la lista" << endl;
    fin = clock();
    min = (double)(fin - ini) / CLOCKS_PER_SEC;
    cout << "la busqueda demoro secuencial: " << tiem << endl;
    cout << "la busqueda index demoro: " << min << endl;
    cout << endl << "****************** Fin del Programa *******************" << endl;
    cin.get();
    cin.get();
    //return 0;
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
 * Funci�n que recorre el vector sin ordenar en busca
 * del valor deseado. 
 * Devuelve la posici�n o -1 si no existe el valor
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
 * Funci�n que busca un elemento en una lista ordenada
 * partiendo la lista en dos, descartando la mitad de la lista 
 * donde no se puede encontrar el valor buscado, y as� 
 * sucesivamente.
 * Devuelve la posici�n del valor en el vector o -1 si 
 * no se encontr� el valor.
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
 * Funci�n que busca un intervalo adecuado para el �ndice
 */

int index_creator(int tam){
 
 int i;

 printf("El tama�o del arreglo es %i", tam);

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

/* Funci�n que realiza una b�squeda secuencial indexada
 * Primero busca un intervalo para el indice, luego
 * general el �nidce.
 * Una vez teniendo el �nidice realiza una b�squeda 
 * en secuencial en el �nidce, para posteriormente encontrar
 * las claves entre las cuales realizar otra b�squeda
 * secuencial y asi encontrar la posici�n que se devuele.
 * Si no existe el valor en el vector se devuelve -1.
 * El vector tiene que estar ordenado.
 */

int b_secindexada(int v[], int tam, int buscar){

 int intervalo;
 int i;
 int j=0;
 int tam_ind=0;
 index indice[MAX_IND];

 cout << endl << "Generando el indice:" << endl;

 intervalo=index_creator(tam);
 if(intervalo==-1){
  cout << endl << "No se encontr� un intervalo adecuado... abortando..." << endl;
  return -1;
 }

 cout << endl << "El intervalo es: " << intervalo << endl;

 for(i=0; i<=tam; i=i+intervalo){
  indice[tam_ind].pos=i;
  indice[tam_ind].valor=v[i];
  tam_ind++;
 }

 for(i=0; i<tam_ind; i++)
  cout << endl << indice[i].pos << ", " << indice[i].valor;
  cout << endl;
 
 for(i=0; i<tam_ind; i++)
 {
  cout << "La posici�n es: " << indice[i].pos << endl;
  if(indice[i].valor>=buscar)
  {
   cout << "Estamos buscando " << buscar << " entre " << indice[i].pos-intervalo << " y " << indice[i].pos << endl;
   for(j=(indice[i].pos-intervalo); j<=indice[i].pos; j++)
   {
    cout << "Estamos buscando " << buscar << " en " << j << ":" << v[j] << endl;
    if(v[j]==buscar)
    {
     return j;
    }
   }
  }
 }
 return -1;
}
