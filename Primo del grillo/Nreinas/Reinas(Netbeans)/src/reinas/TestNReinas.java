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
import java.io.*;

public class TestNReinas {
	public static void main(String[] args)throws IOException {
		int cont=0;
		System.out.println("Â¿Cuantas reinas quieres?: ");
		int numReinas = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
		Controlador.setNReinas(numReinas);
		ArrayList<Reina> reinas = new ArrayList<Reina> ();
		reinas.add(new Reina(0,0));
			if (numReinas > 3 || numReinas==1){
			while(reinas.size() != Controlador.nReinas){
				if (reinas.get(0).getFila()==Controlador.nReinas) break;
				if (reinas.size()!=Controlador.nReinas){
					if (reinas.get(0).getFila()!=Controlador.nReinas+1){
						reinas.get(reinas.size()-1).moverReina(reinas, reinas.get(reinas.size()-1).getColumna());
					}
				}else{
					break;
				}
				if (reinas.size()==Controlador.nReinas){
					cont++;
					System.out.println("\n*** Solucion #: "+cont+" ***");
					reinas.get(reinas.size()-1).printarTablero(reinas);
					reinas.remove(reinas.size()-1);
					reinas.get(reinas.size()-1).moverPuesta(reinas);
				}
			}
		}
		System.out.println("\nNÃºmero de soluciones para "+ Controlador.nReinas +"-Reinas: " +cont);
		/*if (reinas.size()==Controlador.nReinas){
			reinas.get(reinas.size()-1).printarTablero(reinas);
		}*/
	}
}
