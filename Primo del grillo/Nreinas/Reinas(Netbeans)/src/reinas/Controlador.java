/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package reinas;

/**
 *
 * @author ADMIN
 */
import java.util.ArrayList;

public abstract class Controlador {
	public static int nReinas;
	public abstract void moverReina(ArrayList<Reina> reinas, int nReinas);
	
	public static void setNReinas(int numReinas){ nReinas = numReinas; }

	public void printarTablero(ArrayList<Reina> reinas){
		boolean reina = false;
		for (int i=0; i<nReinas; i++){
			for (int j=0;j<nReinas; j++){
				reina = false;
				for (int k = 0; k < nReinas; k++){
					int fila = reinas.get(k).getFila();
					int col = reinas.get(k).getColumna();
					if (fila == i && col == j){
						reina = true;
					}
				}
				if (reina){
					System.out.print(" Q ");
				}else{
					System.out.print(" * ");
				}
			}
			System.out.print("\n");
		}
	}
	
	public boolean validarPosicion(ArrayList<Reina> reinas){
		Reina r = reinas.get(reinas.size()-1);
		int fila2=r.getFila();
		int col2=r.getColumna();
		for (int j=0; j<reinas.size()-1;j++){
			int fila1=reinas.get(j).getFila();
			int col1=reinas.get(j).getColumna();
			if (fila1 == fila2){
				return false;
			}
			if(fila1-col1 == fila2-col2 || fila1+col1 == fila2 + col2){
				return false;
			}
			if (col1 - col2 == fila1 - fila2 || col1 - col2 == fila2 - fila1){
				return false;
			}
		}
		return true;
	}
}
