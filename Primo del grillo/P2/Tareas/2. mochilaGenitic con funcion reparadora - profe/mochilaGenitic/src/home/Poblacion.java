package home;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class Poblacion {
	
	private List<Solucion> soluciones;
	Random rand;
	
	
	
	Poblacion(){
	
		this.soluciones = new ArrayList<Solucion>();
	}
	
	private int sumaBeneficios(){
		int sumaB = 0;
		Iterator<Solucion> iter = this.soluciones.iterator();
		while (iter.hasNext()){
			sumaB += iter.next().getBenef();
		}
		
		return sumaB;
	}
	
	public Solucion ruleta(){
		int sumaB = this.sumaBeneficios();
		System.out.println("sumaB = " + sumaB);
		
		Solucion temp = null;
		
		int dado = this.rand.nextInt(sumaB);
		
		
		System.out.println("dado = " + dado);
		
		Iterator<Solucion> iter = this.soluciones.iterator();
		
		int acu = 0;
		while (iter.hasNext() && temp == null){
			Solucion objTemp = iter.next();
			acu += objTemp.getBenef();
			if (acu >= dado)
				temp = objTemp;
		}
		return temp;
	}
	
	public void fillAletorias(int nPoblacion, 
			List<Producto> productos, 
			Random rand, 
			int disponible){
		
		this.rand = rand;
		for (int i=0; i < nPoblacion; i++){
			Solucion sol00 =new Solucion(productos, rand, disponible);
			sol00.genAletoria();
			
			this.soluciones.add(sol00);
		}
		
	}

	@Override
	public String toString() {
		return "Poblacion " + soluciones + "";
	}
	
	

}
