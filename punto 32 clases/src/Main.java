import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    static Scanner scan;
    public static void main(String[] args) {

        scan = new Scanner(System.in);

        int pos = 0;
        int validos = 0;
        String respuesta;

        Book libro = new Book();
        BookShop tienda = new BookShop();

        System.out.printf("ingrese el nombre de la tienda: ");
        String nombre = scan.nextLine();

        tienda.setNombreTienda(nombre);

        do
        {
            System.out.printf("ingrese el nombre del libro: ");
            String nombreLibro = scan.nextLine();

            System.out.printf("ingrese el nombre del autor de dicho libro: ");
            String autorLibro = scan.nextLine();

            System.out.printf("ingrese el anio de publicacion del libro: ");
            int anioLibro = scan.nextInt();

            libro.setTitulo(nombreLibro);
            libro.setAutor(autorLibro);
            libro.setAnioPublicacion(anioLibro);

            validos = tienda.agregarProducto(libro,pos);

            pos++;

            System.out.printf("agregar otro producto?: ");
            respuesta = scan.nextLine();
        }while(respuesta.equals("si") || respuesta.equals("SI"));



        ///SOLUCIONAR COMO ARMAR EL METODO DE OBTENER INFORMACION Y CONSULTAR POR LA CONSIGNA


        for(int i = 0; i < validos; i++)
        {
            libro.obtenerInformacion(tienda.productos[pos]);
        }
    }
}