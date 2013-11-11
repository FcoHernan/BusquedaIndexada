/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonacci.dinamico;

import java.util.Arrays;

/**
 *
 * @author alumnos
 */
public class FibonacciDinamico {

  static long calls;
  static long[] arreglo;

public static long fib (int n){
    if(arreglo[n]!= -1) 
        return arreglo[n];
    else if (n == 1 || n==0){
    arreglo[n]=n;
    return n;
    }
    else{
    calls += 2;
    long aux = fib (n-1) + fib(n-2);
    arreglo[n] = aux;
    return aux;
    }
}
public static void main(String[] args) {
    arreglo = new long [1000];      
    for (int i=1; i < 91; i++){
        Arrays.fill(arreglo, -1);
        calls = 0;
        Long tiempoI = System.currentTimeMillis(); 
        Long fib = fib(i);
        Long tiempoF = System.currentTimeMillis();
        System.out.println( i + "\t\t" + fib + "\t\t\t" + (tiempoF-tiempoI)+ "\t\t" + calls );
}

}
}