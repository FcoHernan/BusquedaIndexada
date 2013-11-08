

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class Solucion {

    
    private int id;
    private List<Ciudad> ciudades;
    private int fitness;
    
    public Solucion(){
        this.id = -1;
        this.fitness = -1;
        this.ciudades = new ArrayList<Ciudad>();
    }
    
    public Solucion(int id){
        this.id = id;
        this.fitness = -1;
        this.ciudades = new ArrayList<Ciudad>();
    }
    
    public Solucion(int id, List ciudades){
        this.id = id;
        this.fitness = -1;
        this.ciudades = new ArrayList<Ciudad>();
        this.ciudades.addAll(ciudades);
    }
    
    public void add(Ciudad c){
        if (ciudades == null)
            this.ciudades = new ArrayList<Ciudad>();
        this.ciudades.add(c);
    }
    
    public void addAll(List<Ciudad> lista){
        if (ciudades == null)
            this.ciudades = new ArrayList<Ciudad>();
        this.ciudades.addAll(lista);
    }
    
    public int fitness(){
        if (this.fitness == -1){
            int f = 0;
            Ciudad temp = null;
            Iterator iter = ciudades.iterator();
            while (iter.hasNext()){
                if (temp == null){
                    temp = (Ciudad) iter.next();
                }else{
                    Ciudad temp2 = (Ciudad) iter.next();
                    f += temp.distanceTo(temp2);
                    temp = temp2;
                }
            }

            Ciudad primera = ciudades.get(0);
            Ciudad ultima = ciudades.get(ciudades.size()-1);
            int distancia = primera.distanceTo(ultima);
            
            this.fitness = f + distancia;
        }
        return this.fitness;
        
    }

    @Override
    public String toString() {
        return "Solucion " + id +  ciudades  ;
    }
    
    public String toStringCorto() {
        return "Solucion " + id + " f=" +  this.fitness()  ;
    }
    
    
    public void llenaAleatorio(List ciudades, Random ran){
        List<Ciudad> listaTemp = new ArrayList<Ciudad>();
        listaTemp.addAll(ciudades);
        
        this.ciudades = new ArrayList();
        
        while (listaTemp != null && listaTemp.size()>0){
            int indice = ran.nextInt(listaTemp.size());
            this.ciudades.add(listaTemp.get(indice));
            listaTemp.remove(indice);
        }
    }
    
    public Solucion getVecina(int id, Random ran){
        Solucion vecina = new Solucion(id);
        
        List<Ciudad> listaTemp = new ArrayList<Ciudad>();
        listaTemp.addAll(this.ciudades);
        
        int dado1 = ran.nextInt(listaTemp.size());
        int dado2 = ran.nextInt(listaTemp.size());
        
        Ciudad temp = listaTemp.get(dado1);
        listaTemp.set(dado1, listaTemp.get(dado2));
        listaTemp.set(dado2, temp);
        
        vecina.addAll(listaTemp);
        return vecina;
    }
    
    
}
