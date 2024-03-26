public class Estudiante {

    String nombre;
    int edad;
    double[] calificaciones;
    String[] materias;

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

    public void mostrarInformacion()
    {
        double promedio = calcularPromedio();
        String nombreAlumno = getNombre();
        int edadAlumno = getEdad();
        double[] calificacionesAlumno = getCalificaciones();
    }
}
