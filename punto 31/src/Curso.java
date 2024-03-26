public class Curso {

    String nombreCurso;
    Estudiante[] estudiantes;

    int posTope = 0;

    public Curso()
    {
        nombreCurso = "";
        posTope = 0;
    }

    public String getNombreCurso()
    {
        return nombreCurso;
    }

    public Estudiante[] getEstudiantes()
    {
        return estudiantes;
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
}
