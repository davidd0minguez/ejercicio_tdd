public class Sprite implements Producto  {
    private Integer costo;

    public Sprite(int costo) {
        this.costo = costo;
    }

    public int diferenciaEntreParamCosto(Integer precioVenta) {
        return precioVenta - this.costo;
    }
}
