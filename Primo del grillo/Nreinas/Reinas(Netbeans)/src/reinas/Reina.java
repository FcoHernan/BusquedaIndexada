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

public class Reina extends Controlador {
	private int columna;
	private int fila;
	
	
	public Reina (){ }
	
	public Reina(int fila, int columna){
		setColumna(columna);
		setFila(fila);
	}
	
	public void setColumna(int columna) { this.columna = columna; }
	public int getColumna() { return columna; }
	public void setFila(int fila) {	this.fila = fila; }
	public int getFila() { return fila; }
	
	public void moverPuesta(ArrayList<Reina> reinas){
		reinas.get(reinas.size()-1).setFila(reinas.get(reinas.size()-1).getFila()+1);
		if (reinas.get(reinas.size()-1).getFila() > nReinas-1){
			if (reinas.size()-1 > 0){
				reinas.remove(reinas.size()-1);
				reinas.get(reinas.size()-1).moverPuesta(reinas);
			}
		}else{
			if (! validarPosicion(reinas)){
				reinas.get(reinas.size()-1).moverPuesta(reinas);
			}
		}
	}
	
	public void moverReina(ArrayList<Reina> reinas, int n){
		for (int i=0; i < nReinas;i++){
			if (reinas.size()<nReinas && n<nReinas){
				reinas.add(new Reina(i,n+1));
				if (validarPosicion(reinas)){
					reinas.get(reinas.size()-1).moverReina(reinas, n+1);
					break;
				}else{
					if (reinas.get(reinas.size()-1).getFila() == nReinas-1){
						reinas.remove(reinas.size()-1);
						reinas.get(reinas.size()-1).moverPuesta(reinas);
					}else{
						reinas.remove(reinas.size()-1);
					}
				}
			}
		}
	}
}
