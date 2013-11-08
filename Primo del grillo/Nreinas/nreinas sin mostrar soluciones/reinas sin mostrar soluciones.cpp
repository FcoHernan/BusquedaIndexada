

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <time.h> 

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
if (NREINAS == 2 || NREINAS == 3)
{
    cout << "El problema no tiene soluciones" << endl;
}
else
{
    if( k == NREINAS )
    {
		/*cout << */nro_sol++;/* << endl;*/
        //for(int j=0; j<NREINAS; j++)
        //cout << " (" << j+1 << "," << sol[j] << ")";
		//cout << endl;
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
}
 
int main() 
{
    clock_t start, end;
    double seg;
	cout << "Introducir la cantidad de reinas: ";
	cin >> NREINAS;
    cout << "SOLUCIONES AL PROBLEMA DE LAS " << NREINAS << " REINAS" << endl << endl;
    start = clock();
    sol.resize(NREINAS);
    reinas(0, vector<int>(), vector<int>(), vector<int>());
	end = clock();
	seg = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "El numero de soluciones encontradas es de: " << nro_sol-1;
    cout << endl << "El tiempo de ejecucion fue de: " << seg * 1000.0 << " milisegundos" << endl;
    cin.get();
	cin.get();
}
