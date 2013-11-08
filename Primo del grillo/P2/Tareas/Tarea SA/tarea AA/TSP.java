


import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class TSP {

    public static void main(String[] args) {
        System.out.println("Hola Mundo !!!");
        
        int NC = 1000;
        
        
        Random ran = new Random(111);
        List<Ciudad> ciudades = new ArrayList<Ciudad>();
        
        for (int i=0; i < NC; i++){
            Ciudad temp = new Ciudad(i, ran.nextInt(1000), ran.nextInt(1000));
            ciudades.add(temp);
        }
        
        Solucion solMejor = new Solucion(0, ciudades);
        System.out.println(solMejor.toStringCorto());
        int n =0;
        
        for (n=1;  n <= 10000; n++){
            Solucion solTemp = new Solucion(n);
            solTemp.llenaAleatorio(ciudades, ran);
            
            if (solTemp.fitness() < solMejor.fitness()){
//                System.out.println("Mejor " + 
//                        solTemp.toStringCorto() +  
//                        " < " +  solMejor.toStringCorto());
                solMejor = solTemp;
                
            }else{
//                System.out.println("Mas Mala "+ 
//                        solTemp.toStringCorto() +  
//                        " < " +  solMejor.toStringCorto());;
            }
                
        }
        System.out.println("==Aleatorio==================");
        System.out.println(solMejor.toStringCorto());
        
    
        for (;  n <= 20000; n++){
            Solucion vecina = solMejor.getVecina(n, ran);
            
            if (vecina.fitness() < solMejor.fitness()){
//                System.out.println("Mejor " + 
//                        vecina.toStringCorto() +  
//                        " < " +  solMejor.toStringCorto());
                solMejor = vecina;
                
            }else{
//                System.out.println("Mas Mala "+ 
//                        vecina.toStringCorto() +  
//                        " < " +  solMejor.toStringCorto());;
            }
        }
        System.out.println("==Gradiente==================");
        System.out.println(solMejor.toStringCorto());
        
        System.out.println("==SA==================");
        
        double T = 1000000; 
        int iterMax = 100000;
        Solucion s0 = solMejor;
        while (iterMax > 0){
        	 Solucion vecina = s0.getVecina(n, ran);
        	
//        	System.out.println(T);
        	 if (vecina.fitness() < s0.fitness()){
        		 s0 = vecina;
        	 } else {
        		 double b = Math.exp((-(vecina.fitness() - s0.fitness()))/T);
        		 if (b > ran.nextDouble())
        			 s0 = vecina;
        	 }
        	 if (s0.fitness() < solMejor.fitness())
        		 solMejor = s0;
        	
        	iterMax --;
        	T =T - (T * 0.0001);
        }
        System.out.println(solMejor.toStringCorto());
        
    }
}

