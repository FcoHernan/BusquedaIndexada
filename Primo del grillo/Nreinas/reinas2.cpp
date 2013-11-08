// reinas2.cpp: define el punto de entrada de la aplicación de consola.
//

//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>

#include    <cstdlib>
#include    <ctime>
#include    <sys/timeb.h>
//#define NREINAS 8 // dimensiones del tablero y número de reinas
using namespace std;
vector<int> sol;
int nro_sol=1;
int NREINAS;
 
inline bool contiene(const vector<int>& v, const int val)
{
    return find(v.begin(), v.end(), val) != v.end();
}
 
void reinas(int k, vector<int> col, vector<int> diag45, vector<int> diag135)
{
    if( k == NREINAS )
    {
		cout << nro_sol++;
        for(int j=0; j<NREINAS; j++)
        cout << " (" << j+1 << "," << sol[j] << ")";
		cout << endl;
    }
    else
    {
        for(int j=1; j<=NREINAS; j++)
            if( !contiene(col, j) && !contiene(diag45, j-k) && !contiene(diag135, j+k) )
            {
                sol[k] = j;
                col.push_back(j);
                diag45.push_back(j-k);
                diag135.push_back(j+k);
                reinas(k+1,col, diag45, diag135);
                col.pop_back();
                diag45.pop_back();
                diag135.pop_back();
            }
    }
}
 

int main()
{
	clock_t startC, finishC;
    struct timeb startT, finishT;
	unsigned int seconds, milliseconds, milli, mill;
	
	int op=1;
	while (op != 0){
		cout<<"1) N Reinas"<<endl;
		cout<<"0) Salir"<<endl;
		cin >> op;
		cout << cls;
		if(op > 1)
		{
			cout<<"Ingrese opcion correctamente"<<endl;	
		}
		else{
			if(op == 1)
			{
				cout << "Introducir la cantidad de reinas: ";
				cin >> NREINAS;
				cout << "SOLUCIONES AL PROBLEMA DE LAS " << NREINAS << " REINAS" << endl;
				
				//Inicia el reloj, para contar lo que se demora en ejecutar el algoritmo de N-Reinas
				startC = clock(); 
				ftime(&startT);
				
				//Llamado a algoritmo N-Reinas
				sol.resize(NREINAS);
				reinas(0, vector<int>(), vector<int>(), vector<int>());
				
				//Finaliza el Reloj
				finishC = clock();
				ftime(&finishT);
				
				//Calculos
				seconds = finishT.time - startT.time;
				milli = (1000 * (finishT.time - startT.time));//segundos a milisegundos
				mill = (finishT.millitm - startT.millitm);
				milliseconds = (milli + (finishT.millitm - startT.millitm)); //milisegundos totales
 
				cout << "Time (clock): "    << (finishC - startC)/CLOCKS_PER_SEC << " Segundos" << endl;
				cout << "Time (difftime): " << difftime(finishC, startC) << " Milisegundos" <<endl;//Diferencia en Milisegundos entre Inicio y Fin 
				cout << "Time (ftime): " << milliseconds << " milisegundos" <<endl; //milisegundos
				cout <<milli<<endl;
				cout <<mill<<endl;

				cin.get();
				cin.get();
			}
		}
	}
	return 0;
}

