#include<iostream>
#include<windows.h> //para system
#define TAM 1000
#include<time.h>
#define INDEXADO 100
#define CANT_INDICES 10
/* 
para modificar la cantidad de datos con los que trabaja el algoritmo debemos modificar la variable TAM
para modificar el rango de indexacion debemos modificar la variable INDEXADO
para modificar la cantidad de indices se debe modificar CANT_INDICES
estos tres deben tener relacion para que el algoritmo no se caiga
por ejemplo: si se quiere trabajar con 50 datos con una cantida de 10 indices el rango debe ser 50/10 de lo contrario el algoritmo se caera

*/
using namespace std;
void LlenarArreglo(int arreglo[])
{
    int i;
    for(i=0;i<TAM;i++)
    {
        arreglo[i] = rand()%5000; //llenar el arreglo con numeros aleatorios
    }
}
void MostrarArreglo(int arreglo[])
{
	cout<<"*****ARREGLO ALEATORIO******"<<endl;
    int i;
    for (i=0;i<TAM;i++)
    {
        cout<<arreglo[i]<<","; 
    }
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
            {//
                right--;
            }//
            if(left != right)
            {
                v[left]=v[right];
                left++;
            }
            while ((v[left] <= pivot) && (left<right))
            {//
                left++;
            }//
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
void quick_sort(int v[], int size)
{
    q_sort(v, 0, size-1);
}
void BuscarNumero(int arreglo[], int contenido[], int posiciones[],int buscado)
{
	int i=0,aux,principio,final,encontrado;
	while(i<100)
	{
		//cout<<contenido[i]<<endl;
		if(buscado > contenido[i])
		{
			i++;
		}
		else
		{
			aux = i;
			break;
		}
	}
	//cout<<"La posicion maxima en la que puede estar el numero es "<<aux<<endl;
	//cout<<"La posicion maxima en la que puede estar el numero es "<<posiciones[aux]<<endl;
	principio = posiciones[aux-1];
	final = posiciones[aux];
	/*cout<<"El numero podria estar entre las posiciones "<<principio<<" y la "<<final<<endl;
	cout<<"los posibles numeros a encontrar son: "<<endl;
	for(i=principio;i<=final;i++)
	{
		cout<<arreglo[i]<<endl;
	}*/
	for (i=principio; i<final;i++)
	{
		//cout<<buscado<<" es igual a "<<arreglo[i]<<"?"<<endl;
		if(buscado == arreglo[i])
		{
			//cout<<"si"<<endl;
			encontrado =1; //funciona como un swich para saber si lo encontro o no
			break;
		}
		else
		{	
			//cout<<"no"<<endl;
			encontrado =0;
		}
		
	}
	//cout<<"Hola"<<ends<<encontrado<<endl;
	if (encontrado ==1)
	{
		cout<<"el numero fue encontrado en la posicion "<<i<<endl;
	}
	else
	{
		cout<<"el numero no fue encontrado en el arreglo"<<endl;
	}
	
}
int main ()
{
    int arreglo[TAM];
    int i,contenido[CANT_INDICES],j=0,posiciones[INDEXADO],buscado;
    LlenarArreglo(arreglo);
    MostrarArreglo(arreglo);
    cout<<"\n Ingrese numero que desea buscar"<<endl;
    cin>>buscado;
    clock_t start = clock();
    quick_sort(arreglo,TAM); //para ordenar arreglo inicial
    /*cout<<"el arreglo ordenado es "<<endl; //comprobar que el arreglo este ordenado (pruebas)
    MostrarArreglo(arreglo);*/
    
    //se divide el arreglo en la cantidad de partes que se estime conveniente en este caso en 100 partes
    for (i=0;i<TAM;i=i+INDEXADO)//se guardan los contenidos de los indices que nos van a servir para hacer la busqueda
    {
        contenido[j] = arreglo[i]; //guardando el contenido 
        j++;
    }
    //prueba para mostrar el arreglo de indices
    //cout<<"El arreglo de indices es"<<endl; //mostrar el arreglo de indices (pruebas)
    j=0;
    for(i=0;i<10;i++) //guardamos las posiciones que nos serviran para hacer la busqueda
    {
        posiciones[i] = j; //guardar las posiciones en caso de cualquier cosa
        cout<<"posicion"<<ends<<j<<ends<<contenido[i]<<endl;
        j=j+100;
        /*Tener claro que la posicion 0 del vector de indices es la posicion 0 del original, la posicion
          1 del vector de indices es la posicion 11 del vector original y as� ... */
    }
    //cout<<"\n Ingrese numero que desea buscar"<<endl;
    //cin>>buscado;
    
    //clock_t start = clock(); // inicia el contador de tiempo para ver cuanto demora la busqueda
    BuscarNumero(arreglo,contenido,posiciones,buscado);
    cout<<"Tiempo transcurrido es:"<<ends<<((double)clock()-start)/CLOCKS_PER_SEC<<endl; //entrega el tiempo que demoro
    system ("pause");
}
