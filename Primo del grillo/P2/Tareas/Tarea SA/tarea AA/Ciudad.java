


public class Ciudad {

    private int x;
    private int y;
    private int id;
    
    public Ciudad(){
        this.id = -1;
        this.x = 0;
        this.y = 0;
    }

    public Ciudad(int x, int y){
        this.id = -1;
        this.x = x;
        this.y = y;
    }
    
    public Ciudad(int id, int x, int y){
        this.id = id;
        this.x = x;
        this.y = y;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
    
    public int distanceTo(Ciudad c){
        return (int) Math.sqrt(
                Math.pow(this.x - c.getX(),2) + 
                Math.pow(this.y - c.getY(),2)
               );
    }

    @Override
    public String toString() {
        return "\n" + id + "{" + x + ", " + y + "}";
        
    }
}
