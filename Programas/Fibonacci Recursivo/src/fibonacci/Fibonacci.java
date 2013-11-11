/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonacci;

/**
 *
 * @author alumnos
 */
public class Fibonacci {
    private static long calls;

    /**
     * @param args the command line arguments
     */
    
    static long Fibo(int n){
        calls++;
        if(n==1 || n==0) {
            return n;
        }
        else
            return Fibo(n-1)+ Fibo(n-2);
            
        
    }
    public static void main(String[] args) {
        long f;
        for(int n=0; n<=100; n++){
            calls =0;
            long tiempoInicio = System.currentTimeMillis();
            f=Fibo(n);
            long totalTiempo = System.currentTimeMillis() - tiempoInicio;
            System.out.println(n+"\t\t"+f+"\t\t"+totalTiempo+"\t"+calls);           
            
        }
    }
}
