public class BookShop {

    String nombreTienda;
    Book[] productos = new Book[50];
    int validos;

    public BookShop()
    {
        nombreTienda = "";
        validos = 0;
    }

    public String getNombreTienda() {
        return nombreTienda;
    }

    public void setNombreTienda(String nombreTienda) {
        this.nombreTienda = nombreTienda;
    }

    public int agregarProducto(Book datos,int pos)
    {
        productos[pos] = datos;
        validos = pos+1;

        return validos;
    }
}
