// reinas2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
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
 

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t startC, finishC;
    struct timeb startT, finishT;
	unsigned int seconds, milliseconds, minutos, horas, dias, a;
	
	int op=1;
	while (op != 0){
		cout<<"1) N Reinas"<<endl;
		cout<<"0) Salir"<<endl;
		cin >> op;
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
				//milliseconds = (finishT.millitm - startT.millitm);//milisegundos a sumar
				seconds = (finishC - startC)/CLOCKS_PER_SEC;//segundos 
				//mill= (finishT.millitm - startT.millitm); milisegundos a sumar
				minutos = (seconds/60);//A Minutos
				horas = (seconds/3600);// A Horas sec/(60*60) = sec/3600
				dias = (seconds/86400);// A Horas sec/(60*60*24) = sec/86400
				if(seconds>=60){
					seconds = seconds - minutos*60;
				}
				//milli = (1000 * (finishT.time - startT.time));segundos a milisegundos
				//milliseconds = (milli + (finishT.millitm - startT.millitm)); milisegundos totales
				
 
				//cout << "Milisegundos:  "<< milliseconds << endl;
				cout << "Segundos:      "    << (finishC - startC)/CLOCKS_PER_SEC <<endl; //segundos
				//cout << "Time (difftime) : " << difftime(finishC, startC) << " Milisegundos" <<endl; Diferencia en Milisegundos entre Inicio y Fin
				//cout << "Time (ftime) milisegundos: " << milliseconds << " milisegundos" <<endl; milisegundos totales calculados
				cout << "Minutos:       " << minutos <<endl;
				cout << "Horas:         "<< horas <<endl;
				cout << "Dias:          "<< dias <<endl;


				milliseconds = 0;
				
				cin.get();
				cin.get();
			}
		}
	}
	return 0;
}

