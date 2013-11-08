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
		
		System.out.println(productos);
		
		Solucion sol00 =new Solucion(productos, rand, disponible);
		sol00.genAletoria();

		Solucion sol01 =new Solucion(productos, rand, disponible);
		sol01.genAletoria();
		
		System.out.println("Sol00 = " + sol00);
		System.out.println("Sol01 = " + sol01);
		
		List<Solucion> hijas = sol00.cruzaminto(sol01);
		System.out.println(hijas.get(0).getCosto());
		System.out.println(hijas.get(1).getCosto());
	}
	
}
