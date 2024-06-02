#ifndef PROTOTIPADOS_H_INCLUDED
#define PROTOTIPADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO_MISIONES "misiones.dat"
#define ARCHIVO_NAVES "Naves"
#define ARCHIVO_ASTRONAUTAS "astronautas.dat"
#define MAX_TRIPULANTES 15
#define MAX_MEDIO 30
#define MAX_LARGO 60
#define TIPODENAVE_LETRASMAX 50
#define ESTADO_LETRASMAX 50
//estructuras
typedef struct
{
    int id;
    int idNave;//Mas de una nave de cada tipo
    int estado;//1- Listo 2- En vuelo 3- Retornada 4- Cancelada 5- Fallida
    char destino[MAX_MEDIO];
    char cargamento[MAX_LARGO];
    int tripulantes;
    int idTripulantes[MAX_TRIPULANTES];
    char detalleMision[MAX_LARGO];
} mision;

typedef struct
{
    int ID;
    char TipoDeNave[TIPODENAVE_LETRASMAX];
    int CantVuelos;
    int HorasVuelos;
    char Estado[ESTADO_LETRASMAX];
} Nave;

typedef struct
{
    int ID;
    char nombre[MAX_MEDIO];
    char apellido[MAX_MEDIO];
    char apodo[MAX_MEDIO];
    int edad;
    char nacionalidad[MAX_MEDIO];
    char especialidad[MAX_LARGO];
    int horasDEvuelvoHechas;
    int misionesHechas;
    int horasACUMULADASestacion;
    int estado;
} astronauta;









void presentacion();
int menuPRINCIPAL();
int seleccionMENUprincipal();
//Astronautas,prototipados generales
void MenuAstronautas();
int seleccionMENUastronautas();
//FUNCIONES DE ASTRONAUTAS
int cargarDatosASTRONAUTAS();
void modificarDatos();
void recorrerARCHI();
void mostrasDATOS();
void mostrarOPCIONESmodicadoASTRONAUTAS();
void consultarUnAstronauta();
//NAVES, EL MENU
void menuNAVES();
//FUNCIONES DE NAVES
Nave CrearNaves();
void ingresarTipoNave(Nave*dato);
int CrearArregloNaves(Nave arreglo[],int dimension);
int ContarTotaldeNaves();
void AnadirArregloArchivo(int validos,Nave arregloDeNaves[]);
void MostrarNave(Nave dato);
int IngresarPosicion();
void MostrarRegistroPorId(int IdEspecifico);
void MostrarArchivo();
void DarDebajaNave(int IdEspecifico);
void ModificarNave(Nave*dato);
void ModificarPorId(int IdEspecifico);

//MENU MISIONES
void MenuMisiones();
void seleccionMENUmisiones();
//prototipado de misiones
int buscarNaveID(int dato);
int buscarTripulanteID(int dato);
void altaMision();
int cargarTripulantes(mision m);
int buscarNaveID(int);
int buscarTripulanteID(int);
void mostrarTipoNave(int);
void mostrarEstadoMision(int);
int buscarTipoNave(int idNave);
void listarMisiones();
void mostrarTripulantes(mision m, int tripulantes);
int buscarMisionID(int dato);
void modificarUnaMision(int pos);
void misionInicioNaves(int id);
void misionFallaNaves(int id);
void agregarHorasVueloNaves(int horasVuelo, int horasEstacion, int id);
int buscarNavePos(int dato);
void misionFallaAstronautas(int tripulantes[MAX_TRIPULANTES], int tripulantesValidos);
void agregarHorasVueloAstronautas(int horasVuelo, int horasEstacion, int tripulantes[MAX_TRIPULANTES], int tripulantesValidos);
int buscarTripulantePos(int dato);
void modificarMisiones();



#endif // PROTOTIPADOS_H_INCLUDED
