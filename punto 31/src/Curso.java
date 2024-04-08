public class Curso {


    private String nombreCurso;
    private Estudiante[] estudiantes;

    private int posTope = 0;

    public Curso()
    {
        estudiantes = new Estudiante[30];
        nombreCurso = "";
        posTope = 0;
    }

    public String getNombreCurso()
    {
        return nombreCurso;
    }

    public int getPosTope()
    {
        return posTope;
    }

    public void setNombreCurso(String nombreCurso)
    {
        this.nombreCurso = nombreCurso;
    }

    public void setPosTope(int posTope)
    {
        this.posTope = posTope;
    }

    public void cargarEstudiante(Estudiante estudiante, int pos)
    {
        estudiantes[pos] = estudiante;
    }
    public String obtenerInformacion(int pos)
    {
        return estudiantes[pos].mostrarInformacion();
    }
}
