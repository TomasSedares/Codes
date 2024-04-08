import java.util.Arrays;

public class Estudiante {

    private String nombre;
    private int edad;
    private double[] calificaciones;
    private String[] materias;



    public Estudiante()
    {
        nombre = "";
        edad = 0;
        calificaciones = new double[5];
        materias = new String[] {"matematicas","ingles","literatura","quimica","fisica"};
    }

    public String getNombre()
    {
        return nombre;
    }

    public int getEdad()
    {
        return edad;
    }

    public double[] getCalificaciones()
    {
        return calificaciones;
    }

    public void setNombre(String nombre)
    {
        this.nombre = nombre;
    }

    public void setEdad(int edad)
    {
        this.edad = edad;
    }

    ///metodos--------------------------------------------

    public String mostrarMaterias(int pos)
    {
        return materias[pos];
    }

    public void agregarCalificacion(double nota,int pos)
    {
        calificaciones[pos] = nota;
    }

    public double calcularPromedio()
    {
        double acumulador = 0;

        for (int i = 0; i < 5; i++)
        {
            acumulador = acumulador + calificaciones[i];
        }

        return acumulador/5;
    }

    public String concatenarCalif()
    {
        String calif = "";

        for(int i = 0; i < 5;i++)
        {
            calif = calif + ". La nota de " + materias[i]  + " es " + calificaciones[i];
        }

        return calif;
    }

    public String mostrarInformacion()
    {
        String datos = "el promedio de " + getNombre() + " es " + calcularPromedio() + ". Tiene " + getEdad() + " anios, y tiene las siguientes calificaciones" + concatenarCalif();

        return datos;
    }


}
