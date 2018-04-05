public class Papa implements Producto {
    private final Integer costo;

    public Papa(int costo) {
        this.costo = costo;
    }

    public int diferenciaEntreParamCosto(Integer precioVenta) {
        return precioVenta - this.costo;
    }
}
