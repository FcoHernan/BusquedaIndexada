package home;

public class Producto {
	
	String nombre;
	Integer costo;
	Integer benef;
	
	public Producto(String nombre, Integer costo, Integer benef) {
		super();
		this.nombre = nombre;
		this.costo = costo;
		this.benef = benef;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	
	public Integer getCosto() {
		return costo;
	}
	
	public void setCosto(Integer costo) {
		this.costo = costo;
	}
	
	public Integer getBenef() {
		return benef;
	}

	public void setBenef(Integer benef) {
		this.benef = benef;
	}

	@Override
	public String toString() {
		return "Producto [nombre=" + nombre + ", costo=" + costo + ", benef="
				+ benef + "] \n";
	}

	
	
}
