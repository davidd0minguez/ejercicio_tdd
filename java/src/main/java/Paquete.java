public class Paquete {
    private int cantidad;
    private int costo;
    private Producto producto;

    public Paquete(Producto producto, int cantidad, int costo) {
        this.cantidad = cantidad;
        this.costo = costo;
        this.producto = producto;
    }

    public Producto unidad() {
        if (this.producto instanceof Coca){
            return new Coca(this.costo / this.cantidad);    
        }
        else{
            return new Papa(this.costo / this.cantidad);
        }
        
    }
}
