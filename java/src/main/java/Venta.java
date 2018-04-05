public class Venta {
    private Integer precioVenta;
    private Producto producto;

    public Venta(Producto producto, int precioVenta) {
        this.precioVenta = precioVenta;
        this.producto = producto;
    }
    public int rentabilidad() {
        return this.producto.diferenciaEntreParamCosto(this.precioVenta);
    }
}
