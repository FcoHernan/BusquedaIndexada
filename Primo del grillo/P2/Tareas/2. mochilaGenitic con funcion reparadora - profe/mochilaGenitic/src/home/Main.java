package home;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {

	public static void main(String[] args){
		System.out.println("HOLA MUNDO !!!");
		
		List<Producto> productos = new ArrayList<Producto>();
		Random rand = new Random(12);
		
		
		int cantProductos = 10;
		int disponible = 2100;
		
		
		for (int i=1; i <=10; i++){
			productos.add(new Producto(i + "", 
					rand.nextInt(1000), 
					rand.nextInt(500)));
		}
		
		
		Poblacion p = new Poblacion();
		p.fillAletorias(10, productos, rand, disponible);
		
	
		
		for (int gen = 1; gen >=0; gen--){
			
			
			
			Solucion st = p.ruleta();
			Solucion st2 = p.ruleta();

			System.out.println(st);
			System.out.println(st2);

			if (rand.nextInt(100) <= 49){
				System.out.println(st.cruzaminto(st2));
			}
			
			
			
		}
		
		

		
//		Solucion sol00 =new Solucion(productos, rand, disponible);
//		sol00.genAletoria();
//
//		Solucion sol01 =new Solucion(productos, rand, disponible);
//		sol01.genAletoria();
//		
//		System.out.println("Sol00 = " + sol00);
//		System.out.println("Sol01 = " + sol01);
//		
//		List<Solucion> hijas = sol00.cruzaminto(sol01);
//		System.out.println(hijas.get(0).getCosto());
//		System.out.println(hijas.get(1).getCosto());
	}
	
}
