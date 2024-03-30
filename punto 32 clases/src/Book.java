public class Book {

    String titulo;
    String autor;
    int anioPublicacion;

    Book[] datos = new Book[3];

    public Book()
    {
        titulo = "";
        autor = "";
        anioPublicacion = 0;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAnioPublicacion() {
        return anioPublicacion;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setAnioPublicacion(int anioPublicacion) {
        this.anioPublicacion = anioPublicacion;
    }

    public BookShop obtenerInformacion(BookShop productos[],int pos)
    {
        return productos[pos];
    }
}

