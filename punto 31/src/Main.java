import java.util.Scanner;

public class Main {
    static Scanner scan;
    public static void main(String[] args) {

        String respuestaWhile;
        int pos = 0;

        scan = new Scanner(System.in);

        Curso curso = new Curso();
        Estudiante nuevoEstudiante = new Estudiante();

        System.out.printf("ingrese el nombre del curso: ");
        String nombreCurso = scan.nextLine();

        curso.setNombreCurso(nombreCurso);

        do
        {
            System.out.printf("ingrese el nombre del estudiante: ");
            String nombre = scan.nextLine();

            nuevoEstudiante.setNombre(nombre);

            System.out.printf("ingrese la edad del estudiante: ");
            int edad = scan.nextInt();

            nuevoEstudiante.setEdad(edad);

            for (int i = 0; i < 5; i++)
            {
                System.out.printf("ingrese la nota de " + nuevoEstudiante.getNombre() + " en la materia de " + nuevoEstudiante.mostrarMaterias(i) + ": ");
                double nota = scan.nextInt();

                nuevoEstudiante.agregarCalificacion(nota,i);
            }

            curso.estudiantes[pos] = nuevoEstudiante;

            System.out.printf("ingresar un nuevo alumno?: ");
            respuestaWhile = scan.nextLine();

        }while(respuestaWhile.equals("si") || respuestaWhile.equals("SI"));

        nuevoEstudiante.mostrarInformacion();
    }
}