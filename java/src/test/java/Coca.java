public class Coca implements Producto {
    private final int costo;

    public Coca(int costo) {
        this.costo = costo;
    }

    public Coca() {
        this.costo = new Integer(0);
    }

    @Override
    public int diferenciaEntreParamCosto(Integer precioVenta) {
        return precioVenta - this.costo;
    }
}
