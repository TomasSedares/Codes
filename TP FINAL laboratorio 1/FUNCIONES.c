#include <stdio.h>
#include <stdlib.h>//librerias para que funcione cada funcion
#include "PROTOTIPADOS.h" //incluira sus prototipados
#include <string.h>
#include <stdlib.h>

const char LaNave[50]="Naves";

const char Starship[50]="Starship";
const char Falcon9[50]="Falcon 9";
const char FalconHeavy[50]="Falcon Heavy";

const char Mantenimiento[50]="Mantenimiento";
const char Lista[50]="Lista para su uso";
const char EnMision[50]="Actualmente en mision";
const char DeBaja[50]="De baja";

void presentacion()
{
    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("|                      TP FINAL                         |\n");
    printf("|                         DE                            |\n");
    printf("|                     LABORATORIO                       |\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|  HECHO POR:                                           |\n");
    printf("|                                                       |\n");
    printf("|      1.TOMAS SEDARES                                  |\n");
    printf("|      2.JULIAN AUTERI                                  |\n");
    printf("|      3.JUAN ZABALA                                    |\n");
    printf(" ------------------------------------------------------- \n");

    printf("\n");

    system("pause");
    system("cls");

    menuPRINCIPAL();
}

int menuPRINCIPAL()
{
    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("|                   MENU PRINCIPAL                      |\n");
    printf("|                                                       |\n");
    printf("|              1.Astronautas     2.Naves                |\n");
    printf("|                                                       |\n");
    printf("|                3.Misiones     4.Salir                 |\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf(" ------------------------------------------------------- \n");

    int flag=seleccionMENUprincipal();
    return flag;
}

int seleccionMENUprincipal()
{
    int seleccion;

    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("               Seleccione una opcion: ");
    scanf("%i",&seleccion);
    printf("|                                                       |\n");
    printf(" ------------------------------------------------------- \n");

    system("cls");

    switch(seleccion)
    {
        case 1:
            MenuAstronautas();
            break;

        case 2:
            menuNAVES();
            break;

        case 3:
            MenuMisiones();
            break;
        case 4:
            system("cls");
            printf("\n\n                Programa finalizado\n\n");
            system("pause");
            break;

        default:
            printf("opcion invalida");

            system("pause");
            system("cls");

            menuPRINCIPAL();
            break;
    }
    return seleccion;
}

void MenuAstronautas()
{
    int continuar;
    do{
        system("cls");
        printf(" ------------------------------------------------------- \n");
        printf("|                                                       |\n");
        printf("|                  MENU ASTRONAUTAS                     |\n");
        printf("|                                                       |\n");
        printf("|                  1.Carga de datos                     |\n");
        printf("|               2.Modificacion de datos                 |\n");
        printf("|                 3.Ver datos cargados                  |\n");
        printf("|                 4.Consultar por ID                    |\n");
        printf("|                                                       |\n");
        printf("|                                                       |\n");
        printf("|              5.Volver al menu principal               |\n");
        printf(" ------------------------------------------------------- \n");

        continuar=seleccionMENUastronautas();

    }while(continuar!=4);

}

int seleccionMENUastronautas()
{
    int seleccion;

    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("               Seleccione una opcion: ");
    scanf("%i",&seleccion);
    printf("|                                                       |\n");
    printf(" ------------------------------------------------------- \n");

    system("cls");

    switch(seleccion)
    {
        case 1:
            cargarDatosASTRONAUTAS();
            break;

        case 2:
            modificarDatos();
            break;

        case 3:
            recorrerARCHI();
            break;

        case 4:
            consultarUnAstronauta();
        case 5:
            menuPRINCIPAL();
            break;

        default:
            printf("eleccion invalida");
            seleccionMENUastronautas();
            break;
    }
    return seleccion;
}
//FUNCIONES DE ASTRONAUTAS
void consultarUnAstronauta(){
    int id;
    do{
        printf("\nID a buscar:");
        fflush(stdin);
        scanf("%i",&id);
        if(buscarTripulanteID(id)==0){
            printf("-Error. No existe el ID.");
        }
    }while(buscarTripulanteID(id)==0);
    FILE *archivo=fopen(ARCHIVO_ASTRONAUTAS,"rb");
    astronauta a;
    if(archivo!=NULL){
        fseek(archivo,sizeof(a)*(id-1),0);
        fread(&a,sizeof(a),1,archivo);
        mostrasDATOS(a);
        system("pause");
        system("cls");
        fclose(archivo);
    }
}

int cargarDatosASTRONAUTAS()
{
    astronauta nuevo;
    int edad;
    int horasVuelos;
    int cantMisiones;
    int horasEstacion;
    char respuesta;
    int total=0;


    FILE *archi;

    archi=fopen("astronautas.dat","ab");

    if(archi!=NULL);
    {
        fseek(archi,0,2);
        total=(ftell(archi)/sizeof(astronauta))+1;
        do
        {
            printf("---------------------------------------------------------------------\n\n");

            nuevo.ID=total;
            total++;
            printf("ingrese el nombre del astronauta: ");
            fflush(stdin);
            gets(nuevo.nombre);
            printf("ingrese el apellido: ");
            fflush(stdin);
            gets(nuevo.apellido);
            printf("ingrese el apodo: ");
            fflush(stdin);
            gets(nuevo.apodo);

            do
            {
                printf("ingrese la edad: ");
                scanf("%i",&edad);

                if(edad<25 && edad>0)
                {
                    printf("el astronauta es demasiado joven para ser ingresado");
                }
                else if(edad<0)
                {
                    printf("la edad ingresada no es valida");
                }
            }while(edad<26);

            nuevo.edad=edad;

            printf("ingrese nacionalidad del astronauta: ");
            fflush(stdin);
            gets(nuevo.nacionalidad);
            printf("ingrese la especialidad: ");
            fflush(stdin);
            gets(nuevo.especialidad);
            printf("ingrese las horas totales de vuelo: ");
            do
            {
                scanf("%i",&horasVuelos);

                if(horasVuelos<0)
                {
                    printf("las horas de vuelo no son validas");
                }
            }while(horasVuelos<0);

            nuevo.horasDEvuelvoHechas=horasVuelos;

            printf("ingrese la cantidad de mision que ha realizado: ");
            do
            {
                scanf("%i",&cantMisiones);

                if(cantMisiones<0)
                {
                    printf("la cantidad de misiones hechas ingresada no es valida");
                }
            }while(cantMisiones<0);

            nuevo.misionesHechas=cantMisiones;

            printf("ingrese horas acumuladas en la estacion: ");
            do
            {
                scanf("%i",&horasEstacion);

                if(horasEstacion<0)
                {
                    printf("la cantidad de horas ingresada no es valida");
                }
            }while(horasEstacion<0);

            nuevo.horasACUMULADASestacion=horasEstacion;
            printf("ingrese el estado. 1-activo  2-retirado: ");
            scanf("%i",&nuevo.estado);

            printf("---------------------------------------------------------------------\n\n");

            fwrite(&nuevo,sizeof(astronauta),1,archi);

            printf(".................................................");
            printf("           seguir cargando? s/n: ");
            printf(".................................................");
            fflush(stdin);
            scanf("%c",&respuesta);
        }while(respuesta == 's');
    }
    fclose(archi);

    return total;
}

void modificarDatos()
{
    int respuesta;

    astronauta nuevo;

    FILE *archi;

    archi=fopen(ARCHIVO_ASTRONAUTAS,"r+b");

    if(archi!=NULL){

        recorrerARCHI();

        printf("ingrese el registro que quiere modificar: ");
        scanf("%i",&respuesta);

        system("cls");

        fseek(archi,sizeof(astronauta)*(respuesta),0);
        fread(&nuevo,sizeof(astronauta),1,archi);

        system("pause");
        system("cls");

        mostrarOPCIONESmodicadoASTRONAUTAS();

        printf("que dato quieres moridicar?");
        scanf("%i",&respuesta);

        switch(respuesta)
        {
            case 1:
                printf("------------------------------------");
                printf(" ingrese el nombre del astronauta: ");
                printf("------------------------------------");
                fflush(stdin);
                gets(nuevo.nombre);
                break;

            case 2:
                printf("-----------------------");
                printf(" ingrese el apellido: ");
                printf("-----------------------");
                fflush(stdin);
                gets(nuevo.apellido);
                break;

            case 3:
                printf("--------------------");
                printf(" ingrese el apodo: ");
                printf("---------------------");
                fflush(stdin);
                gets(nuevo.apodo);
                break;

            case 4:
                printf("-------------------");
                printf(" ingrese la edad: ");
                printf("-------------------");
                scanf("%i",&nuevo.edad);
                break;

            case 5:
                printf("---------------------------------------");
                printf(" ingrese nacionalidad del astronauta: ");
                printf("---------------------------------------");
                fflush(stdin);
                gets(nuevo.nacionalidad);
                break;

            case 6:
                printf("---------------------------");
                printf(" ingrese la especialidad: ");
                printf("---------------------------");
                fflush(stdin);
                gets(nuevo.especialidad);
                break;

            case 7:
                printf("--------------------------------------");
                printf(" ingrese las horas totales de vuelo: ");
                printf("--------------------------------------");
                scanf("%i",&nuevo.horasDEvuelvoHechas);
                break;


            case 8:
                printf("--------------------------------------------------");
                printf(" ingrese la cantidad de mision que ha realizado: ");
                printf("--------------------------------------------------");
                scanf("%i",&nuevo.misionesHechas);
                break;

            case 9:
                printf("-------------------------------------------");
                printf(" ingrese horas acumuladas en la estacion: ");
                printf("-------------------------------------------");
                scanf("%i",&nuevo.horasACUMULADASestacion);
                break;

            case 10:
                printf("-------------------------------------------");
                printf(" ingrese el estado. 1-activo  2-retirado: ");
                printf("-------------------------------------------");
                scanf("%i",&nuevo.estado);
                break;

            default:
                system("cls");
                printf("la opcion elegida no existe\n");
                modificarDatos();
                break;
        }
        fseek(archi,sizeof(astronauta)*(respuesta),0);
        fwrite(&nuevo,sizeof(astronauta),1,archi);
        fclose(archi);
    }
}

void recorrerARCHI()
{
    int i=0;
    astronauta nuevo;

    FILE *archi;

    archi=fopen(ARCHIVO_ASTRONAUTAS,"rb");

    while(fread(&nuevo,sizeof(astronauta),1,archi)>0)
    {
        mostrasDATOS(nuevo);
    }
    system("pause");
}

void mostrasDATOS(astronauta nuevo)
{
    printf("------------------------------------------------------------------------------------");
    printf("id: %i\n",nuevo.ID);
    printf("nombre del astronauta: %s\n",nuevo.nombre);
    printf("apellido: %s\n",nuevo.apellido);
    printf("apodo: %s\n",nuevo.apodo);
    printf("edad: %i\n",nuevo.edad);
    printf("nacionalidad: %s\n",nuevo.nacionalidad);
    printf("especialidad: %s\n",nuevo.especialidad);
    printf("horas totales de vuelo: %i\n",nuevo.horasDEvuelvoHechas);
    printf("cantidad de misiones que ha realizado: %i\n",nuevo.misionesHechas);
    printf("horas acumuladas en la estacion: %i\n",nuevo.horasACUMULADASestacion);
    printf("estado: 1-activo  2-retirado: %i\n",nuevo.estado);
    printf("------------------------------------------------------------------------------------");

    printf("\n");
}

void mostrarOPCIONESmodicadoASTRONAUTAS()
{
    printf("1.nombre del astronauta\n");
    printf("2.apellido\n");
    printf("3.apodo\n");
    printf("4.edad\n");
    printf("5.nacionalidad\n");
    printf("6.especialidad\n");
    printf("7.horas totales de vuelo\n");
    printf("8.cantidad de misiones que ha realizado\n");
    printf("9.horas acumuladas en la estacion\n");
    printf("10.estado:\n");
}
//NAVES, EL MENU
void menuNAVES()
{
    Nave arregloDeNave[MAX_MEDIO];
    int IDnaveEspecifica;
    int opcion;
    int validosNaves;
    char seguir='s';

    while(seguir=='s')
    {
        Nave arregloDeNave[MAX_MEDIO];
        int IDnaveEspecifica;
        int opcion;
        int validosNaves;
        char seguir='s';

        while(seguir=='s')
        {
            system("cls");
            printf(" ========================================================= \n");
            printf("|                        NAVES                            |\n");
            printf("|                                                         |\n");
            printf("|                 Ingrese una opcion:                     |\n");
            printf("|                                                         |\n");
            printf("|                       1.Alta                            |\n");
            printf("|                                                         |\n");
            printf("|                       2.Baja                            |\n");
            printf("|                                                         |\n");
            printf("|                    3.Modificacion                       |\n");
            printf("|                                                         |\n");
            printf("|                      4.Consulta                         |\n");
            printf("|                                                         |\n");
            printf("|                      5.Listado                          |\n");
            printf("|                                                         |\n");
            printf("|               6.Volver al menu principal                |\n");
            printf(" ========================================================= \n");

            scanf("%d",&opcion);
            system("cls");
            switch(opcion)
            {
            case 1:

                validosNaves=CrearArregloNaves(arregloDeNave,MAX_MEDIO);
                AnadirArregloArchivo(validosNaves,arregloDeNave);
                system("cls");

                break;
            case 2:
                printf(" -------------------------------------------------------------------- \n");
                printf("|        Ingrese el ID de la nave que quiera dar de baja             |\n");
                printf(" ------------------------------------------------------------------- \n");

                IDnaveEspecifica=IngresarPosicion();
                DarDebajaNave(IDnaveEspecifica);
                system("pause");
                break;
            case 3:
                printf(" ----------------------------------------------------------------- \n");
                printf("|        Ingrese el ID de la nave que desea modificar             |\n");
                printf(" ----------------------------------------------------------------- \n");

                IDnaveEspecifica=IngresarPosicion();
                ModificarPorId(IDnaveEspecifica);
                system("pause");
                break;
            case 4:
                printf(" ------------------------------------------------------------------------ \n");
                printf("|        Ingrese el ID de la nave y se mostrara por pantalla             |\n");
                printf(" ------------------------------------------------------------------------ \n");
                IDnaveEspecifica=IngresarPosicion();
                MostrarRegistroPorId(IDnaveEspecifica);
                system("pause");
                break;
            case 5:
                printf("        ---------REGISTRO TOTAL DE NAVES---------\n");
                MostrarArchivo();
                system("pause");
                break;
            case 6:
                seguir='n';
                menuPRINCIPAL();
                break;
            default:
                printf(" ------------------------------------------------ \n");
                printf("|        no se eligio ninguna opcion             |\n");
                printf(" ------------------------------------------------ \n");
                system("pause");
                break;
            }
        }
    }
}

//FUNCIONES DE NAVES
Nave CrearNaves() //crear una nave especifica
{
    Nave nueva;
    ingresarTipoNave(&nueva);
    system("cls");
    do
    {
        printf(" -------------------------------------------------------  \n");
        printf("|          Ingrese la cantidad de vuelos:               |\n");
        printf(" -------------------------------------------------------- \n");

        scanf("%d",&nueva.CantVuelos);
        system("cls");
        if(nueva.CantVuelos<0)
        {
            printf(" ----------------------------------------------------------------------- \n");
            printf("|          Vuelos ingresados invalido, ingrese nuevamente               |\n");
            printf(" ----------------------------------------------------------------------- \n");
        }
    }
    while(nueva.CantVuelos<0);
    do
    {
        printf(" ----------------------------------------------------- \n");
        printf("|          Ingrese las horas de vuelos:               |\n");
        printf(" ----------------------------------------------------- \n");
        scanf("%d",&nueva.HorasVuelos);
        system("cls");
        if(nueva.HorasVuelos<0)
        {
            printf(" ----------------------------------------------------------------------- \n");
            printf("|          Horas de vuelos invalido,ingrese nuevamente                  |\n");
            printf(" ----------------------------------------------------------------------- \n");
        }
    }
    while(nueva.HorasVuelos<0);
    strcpy(nueva.Estado,Lista);  //cada nave nueva automaticamente estara en estado de lista


    return nueva;
}
void ingresarTipoNave(Nave*dato)  //multiples opciones para que el usuario no se quivoque escribiendo el tipo de nave
{
    int opcion;
    do
    {

    printf(" --------------------------------------------------------- \n");
    printf("|               Ingrese el Tipo de nave:                  |\n");
    printf("|                                                         |\n");
    printf("|                   0.Starship                            |\n");
    printf("|                                                         |\n");
    printf("|                   1.Falcon 9                            |\n");
    printf("|                                                         |\n");
    printf("|                  2.Falcon Heavy                         |\n");
    printf("|                                                         |\n");
    printf(" --------------------------------------------------------- \n");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
        case 0:
            strcpy((*dato).TipoDeNave,Starship);
            break;
        case 1:
            strcpy((*dato).TipoDeNave,Falcon9);
            break;
        case 2:
            strcpy((*dato).TipoDeNave,FalconHeavy);
            break;
        default:
        printf(" ------------------------------------------------------------------- \n");
        printf("|              la opcion no existe, intente denuevo                 |\n");
        printf(" ------------------------------------------------------------------- \n");
        system("pause");
        system("cls");
            break;
        }
        }while(opcion<0||opcion>2);

}
int CrearArregloNaves(Nave arreglo[],int dimension) //crear un arreglo de naves
{
    char seguir='s';
    int i=0;
    while(seguir=='s'&&i<dimension)
    {
        arreglo[i]=CrearNaves();
        printf(" ------------------------------------------------------------------ \n");
        printf("|          desea continuar agregando naves? (s/n)                  |\n");
        printf(" ------------------------------------------------------------------ \n");

        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");

        i++;
    }
    if(i==dimension)
    {
        printf(" ------------------------------------------------------------------- \n");
        printf("|       HA ALCANZADO LA CANTIDAD MAXIMA DE NAVES QUE PUEDE CREAR    |\n");
        printf(" ------------------------------------------------------------------- \n");
    }

    return i;

}
int ContarTotaldeNaves()
{
    int total=-1;
    FILE*buffer=fopen(LaNave,"rb");
    if(buffer!=NULL)
    {
        fseek(buffer,0,2);
        total=ftell(buffer)/sizeof(Nave);
        fclose(buffer);
    }


   return total;

}
void AnadirArregloArchivo(int validos,Nave arregloDeNaves[])  //poner en el archivo las naves cargadas en el arreglo
{
    int total;
    char seguir='s';
    Nave datoNuevo;
    FILE*buffer=fopen(LaNave,"ab");

  if(buffer!=NULL)
  {
    total=ContarTotaldeNaves()+1; //le sumo un 1 para que la posicion que empieza se inicie como 1 y asi en todos los registros no contamos el 0
    for(int i=0;i<validos;i++)          //ingreso el ID de la nave en el archivo a partir del tamaño que hay asignado
    {
    datoNuevo=arregloDeNaves[i];
    datoNuevo.ID=total;
    fwrite(&datoNuevo,sizeof(Nave),1,buffer);
    total++;
    }
    fclose(buffer);
  }
  else
  {

    printf(" ------------------------------------------------------- \n");
    printf("|          ERRROR, EL ARCHIVO NO SE PUDO CREAR           |\n");
    printf(" ------------------------------------------------------- \n");

  }



}
void MostrarNave(Nave dato)   //mostrar Dato especifico de nave
{
    printf("===========================================================\n");
    printf("                                                        \n");
    printf("                 ID:%d                           \n",dato.ID);
    printf("                                                        \n");
    printf("             Tipo de Nave:%s                      \n",dato.TipoDeNave);
    printf("                                                        \n");
    printf("             Horas de vuelos:%d                    \n",dato.HorasVuelos);
    printf("                                                        \n");
    printf("             Estado De la Nave:%s                  \n",dato.Estado);
    printf("                                                        \n");
    printf("===========================================================\n");
}
int IngresarPosicion()  //funcion que ingresa el dato
{
    int dato;
    scanf("%d",&dato);
    system("cls");

    return dato;
}
void MostrarRegistroPorId(int IdEspecifico)
{
  FILE*buffer=fopen(LaNave,"rb");
  Nave dato;
  int total;
  if(buffer!=NULL)
  {
    total=ContarTotaldeNaves();
    if(IdEspecifico<1||IdEspecifico>total)
    {

        printf(" ------------------------------------------------------------------------ \n");
        printf("|          el ID ingresado no se encuentra en el archivo                 |\n");
        printf(" ------------------------------------------------------------------------ \n");


    }
    else
    {
        fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);
        fread(&dato,sizeof(Nave),1,buffer);
        MostrarNave(dato);


    }







  }
  else
  {
    printf(" ------------------------------------------------------- \n");
    printf("|          ERRROR, EL ARCHIVO NO EXISTE                  |\n");
    printf(" ------------------------------------------------------- \n");

  }





}
void MostrarArchivo()
{
  FILE*buffer=fopen(LaNave,"rb");
  Nave dato;
  if(buffer!=NULL)
  {

       while(!feof(buffer))
       {
           fread(&dato,sizeof(Nave),1,buffer);
            if(!feof(buffer))
            {
            MostrarNave(dato);
            }






       }


    fclose(buffer);
  }
  else
  {
    printf(" ------------------------------------------------------- \n");
    printf("|          ERRROR, EL ARCHIVO NO EXISTE                 |\n");
    printf(" ------------------------------------------------------- \n");


  }




}

void DarDebajaNave(int IdEspecifico)
{
    FILE*buffer=fopen(LaNave,"r+b");
    Nave dato;
    int total;
    if(buffer!=NULL)
    {

        total=ContarTotaldeNaves();
        if(IdEspecifico<1||IdEspecifico>total) //validar tamaño
        {
            printf(" ---------------------------------------------------- \n");
            printf("|          el ID ingresado no existe                 |\n");
            printf(" ---------------------------------------------------- \n");

        }
        else
        {
            fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);
            fread(&dato,sizeof(Nave),1,buffer);


            if(strcmp(dato.Estado,Lista)==0)
            {
                fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);
                strcpy(dato.Estado,DeBaja);
                fwrite(&dato,sizeof(Nave),1,buffer);
            printf(" ----------------------------------------------------------\n");
            printf("|         la nave se dio de baja exitosamente              |\n");
            printf(" ---------------------------------------------------------- \n");

            }
            else if(strcmp(dato.Estado,Mantenimiento)==0)
            {
                printf(" ---------------------------------------------------------------------------------------- \n");
                printf("|         la nave no se pudo dar de baja debido a que esta en mantenimiento              |\n");
                printf(" ---------------------------------------------------------------------------------------- \n");

            }
            else if(strcmp(dato.Estado,EnMision)==0)
            {
                            printf(" ---------------------------------------------------------------------------------------- \n");
                            printf("|         la nave no se puede dar de baja debido a que esta en una mision                |\n");
                            printf(" ---------------------------------------------------------------------------------------- \n");

            }
            else if(strcmp(dato.Estado,DeBaja)==0)
            {

                printf(" --------------------------------------------- \n");
                printf("|        la nave ya estaba de baja            |\n");
                printf(" --------------------------------------------- \n");


            }



        }

        fclose(buffer);














    }
    else
    {

        printf(" --------------------------------------------------\n");
        printf("|        ERROR, EL ARCHIVO NO EXISTE              |\n");
        printf(" --------------------------------------------------\n");


    }











}

void ModificarNave(Nave*dato)
{
    char seguir='s';
    int opcion;
    while(seguir=='s')
    {
        printf(" --------------------------------------------------------- \n");
        printf("|          Ingrese el dato que desea modificar:           |\n");
        printf("|                                                         |\n");
        printf("|                   0.TipoDeNave                          |\n");
        printf("|                                                         |\n");
        printf("|                   1.CantVuelos                          |\n");
        printf("|                                                         |\n");
        printf("|                   2.HorasVuelo                          |\n");
        printf("|                                                         |\n");
        printf("|                     3.Estado                            |\n");
        printf("|                                                         |\n");
        printf(" --------------------------------------------------------- \n");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
        case 0:
            if(strcmp((*dato).Estado,Mantenimiento)==0)
            {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|        no se puede cambiar los datos de una nave en mantenimiento             |\n");
                printf(" ------------------------------------------------------------------------------- \n");

            }
            else
            {
                ingresarTipoNave(dato);
            }
            break;

        case 1:

            if(strcmp((*dato).Estado,Mantenimiento)==0)
            {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|        no se puede cambiar los datos de una nave en mantenimiento             |\n");
                printf(" ------------------------------------------------------------------------------- \n");

            }

            else
            {






                do
                {
                    printf(" --------------------------------------------------- \n");
                    printf("|        Ingrese la cantidad de vuelos:             |\n");
                    printf(" --------------------------------------------------- \n");

                    scanf("%d",&(*dato).CantVuelos);
                    system("cls");

                    if((*dato).CantVuelos<0)
                    {
                        printf(" ------------------------------------------------------------------- \n");
                        printf("|        Vuelos ingresados invalido, ingrese nuevamente             |\n");
                        printf(" ------------------------------------------------------------------- \n");


                    }
                }
                while((*dato).CantVuelos<0);
            }
            break;

        case 2:

            if(strcmp((*dato).Estado,Mantenimiento)==0)
            {
                printf(" ------------------------------------------------------------------------------- \n");
                printf("|        no se puede cambiar los datos de una nave en mantenimiento             |\n");
                printf(" ------------------------------------------------------------------------------- \n");

            }
            else
            {
                do
                {

                    printf(" ------------------------------------------------- \n");
                    printf("         Ingrese las horas de vuelos: ");
                    printf(" ------------------------------------------------- \n");

                    scanf("%d",&(*dato).HorasVuelos);
                    system("cls");
                    if((*dato).HorasVuelos<0)
                    {
                        printf(" ----------------------------------------------------------------\n");
                        printf("|        horas de vuelos invalido,ingrese nuevamente             |\n");
                        printf(" ----------------------------------------------------------------\n");
                    }




                }
                while((*dato).HorasVuelos<0);
            }
            break;
        case 3:

            if(strcmp((*dato).Estado,Lista)==0)
            {
                printf(" ------------------------------------------------------------------------------------\n");
                printf("|        no se puede modificar el estado de una nave lista manualmente             |\n");
                printf(" ------------------------------------------------------------------------------------\n");


            }
            else
            {

                strcpy((*dato).Estado,Lista);
                printf(" ------------------------------------------------------------------------------------\n");
                printf("|        La nave ha sido modificada exitosamente de mantenimiento a lista             |\n");
                printf(" ------------------------------------------------------------------------------------\n");
            }

            break;
        default:

            printf(" --------------------------------------------------\n");
            printf("|        no se ingreso ninguna opcion             |\n");
            printf(" --------------------------------------------------\n");


            break;
        }
        printf(" -----------------------------------------------------------------------\n");
        printf("|        desea modificar algun otro dato de la nave? (s/n)             |\n");
        printf(" -----------------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");
    }








}
void ModificarPorId(int IdEspecifico)
{
    FILE*buffer=fopen(LaNave,"r+b");
    int total;
    Nave nueva;
    if(buffer!=NULL)
    {
        total=ContarTotaldeNaves();
        if(IdEspecifico<1||IdEspecifico>total)
        {

            printf(" -----------------------------------------------\n");
            printf("|        el ID ingresado no existe             |\n");
            printf(" -----------------------------------------------\n");

            fclose(buffer);


        }
        else
        {
            fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);
            fread(&nueva,sizeof(Nave),1,buffer);        //encuentra el id especifico

            if(strcmp(nueva.Estado,DeBaja)==0)
            {
            printf(" ------------------------------------------------------------------------------\n");
            printf("|        no se puede modificar una nave que ya no esta disponible             |\n");
            printf(" ------------------------------------------------------------------------------\n");


            }
            else if(strcmp(nueva.Estado,Mantenimiento)==0)
            {

                ModificarNave(&nueva);
                fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);  //va y lo modifica, pero con algunas condiciones
                fwrite(&nueva,sizeof(Nave),1,buffer);

            }
            else if(strcmp(nueva.Estado,EnMision)==0)
            {
               printf(" ------------------------------------------------------------------------------\n");
               printf("|        no se puede modificar una nave que ya tiene asignada una mision        |\n");
               printf(" ------------------------------------------------------------------------------\n");



            }
            else
            {
                ModificarNave(&nueva);
                fseek(buffer,sizeof(Nave)*(IdEspecifico-1),0);  //va y lo modifica
                fwrite(&nueva,sizeof(Nave),1,buffer);
               printf(" ----------------------------------------------------------------------------- \n");
               printf("|                      la nave se ha modificado exitosamente                  |\n");
               printf(" -----------------------------------------------------------------------------\n");
            }
            fclose(buffer);

        }

    }
    else
    {
         printf(" ----------------------------------------------- \n");
        printf("|        ERROR, el archivo no existe             |\n");
         printf(" ----------------------------------------------- \n");


    }





}


//MENU MISIONES
//----------------------------------------------------------------------------------------------------------------------------
void MenuMisiones()
{
    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("|                    MENU MISIONES                      |\n");
    printf("|                                                       |\n");
    printf("|                  1.Carga de datos                     |\n");
    printf("|               2.Modificacion de datos                 |\n");
    printf("|                 3.Ver datos cargados                  |\n");
    printf("|                                                       |\n");
    printf("|              4.Volver al menu principal               |\n");
    printf(" ------------------------------------------------------- \n");

    seleccionMENUmisiones();
}

void seleccionMENUmisiones()
{
    int seleccion;

    printf(" ------------------------------------------------------- \n");
    printf("|                                                       |\n");
    printf("               Seleccione una opcion: ");
    scanf("%i",&seleccion);
    printf("|                                                       |\n");
    printf(" ------------------------------------------------------- \n");

    system("cls");

    switch(seleccion)
    {
        case 1:
            altaMision();
            break;

        case 2:
            modificarMisiones();
            break;

        case 3:
            listarMisiones();
            break;

        case 4:
            menuPRINCIPAL();
            break;

        default:
            printf("eleccion invalida");
            seleccionMENUmisiones();
            break;
    }
}

int buscarNaveID(int dato){
    FILE *archivo=fopen(ARCHIVO_NAVES,"rb");
    Nave n;
    int flag = 0;
    if(archivo!=NULL){
        while(fread(&n,sizeof(n),1,archivo)>0){
            if(n.ID==dato){
                if(strcasecmp(n.Estado,Lista)!=0){
                    printf("-Error nave no lista-");
                }else{
                    flag=n.ID;
                }
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}

int buscarTripulanteID(int dato){
    FILE *archivo=fopen(ARCHIVO_ASTRONAUTAS,"rb");
    astronauta a;
    int flag = 0;
    if(archivo!=NULL){
        while(fread(&a,sizeof(a),1,archivo)>0){
            if(a.ID==dato){
                flag=a.ID;
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}

void altaMision(){
    FILE *archivo = fopen(ARCHIVO_MISIONES,"ab");
    mision m;
    if(archivo!=NULL){
        m.id = (ftell(archivo)/sizeof(mision))+1;
        printf("\n------------------------------\nMision: %i",m.id);

        do{
            printf("\nID de nave: ");
            fflush(stdin);
            scanf("%i",&m.idNave);
            if(buscarNaveID(m.idNave)==0){
                printf("\nError. No existe la nave ID:%i.\n",m.idNave);
            }else{
                mostrarTipoNave(m.idNave);
            }
        }while(buscarNaveID(m.idNave)==0);

        m.estado=1;
        printf("\nEstado: %i",m.estado);
        mostrarEstadoMision(m.estado);

        printf("\nDestino (\"EEI\" u otro): ");
        fflush(stdin);
        gets(m.destino);

        printf("\nCargamento: ");
        fflush(stdin);
        gets(m.cargamento);

        m.tripulantes = cargarTripulantes(m);
        printf("\nTripulantes: %i",m.tripulantes);

        printf("\nDetalle de mision: ");
        fflush(stdin);
        gets(m.detalleMision);

        fwrite(&m,sizeof(m),1,archivo);

        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
}

int cargarTripulantes(mision m){
    int tripulantes = 0;
    char continuar = 's';

    do{
        do{
            printf("\nID tripulante %i: ",tripulantes+1);
            fflush(stdin);
            scanf("%i",&m.idTripulantes[tripulantes]);

        }while(buscarTripulanteID(m.idTripulantes[tripulantes])==0);

        tripulantes++;

        printf("            Continuar ingresando (s/n): ");
        fflush(stdin);
        scanf("%c",&continuar);

    }while(continuar=='s'&&tripulantes<MAX_TRIPULANTES);

    return tripulantes;
}

void mostrarEstadoMision(int estado){
    switch(estado){
        case 1:
            printf("- Listo");
            break;
        case 2:
            printf("- En vuelo");
            break;
        case 3:
            printf("- Retornada");
            break;
        case 4:
            printf("- Cancelada");
            break;
        case 5:
            printf("- Fallida");
            break;
    }
}

void mostrarTipoNave(int idNave){
    int tipoNave = buscarTipoNave(idNave);
    switch(tipoNave){
        case 1:
            printf("Starship");
            break;
        case 2:
            printf("Falcon 9");
            break;
        case 3:
            printf("Falcon Heavy");
        default:
            printf("ERROR NAVE");
            break;
    }
}

int buscarTipoNave(int idNave){
    FILE *archivo=fopen(ARCHIVO_NAVES,"rb");
    Nave n;
    int flag = 0;
    if(archivo!=NULL){
        while(fread(&n,sizeof(n),1,archivo)>0){
            if(n.ID==idNave){
                flag=n.ID;
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}

void listarMisiones(){
 FILE *archivo = fopen(ARCHIVO_MISIONES,"rb");
 mision m;
 if(archivo!=NULL){
    while(fread(&m,sizeof(m),1,archivo)<0){
        printf("\n---------------------------------");
        printf("\nID mision: %i",m.id);
        printf("\nID nave: %i",m.idNave);
        printf("\nEstado: %i",m.estado);
        mostrarEstadoMision(m.estado);
        printf("\nDestino: %s",m.destino);
        printf("\nCargamento: %s",m.cargamento);
        printf("\nTripulantes: %i",m.tripulantes);
        mostrarTripulantes(m,m.tripulantes);
        printf("\nDetalle: %s",m.detalleMision);
        printf("\n---------------------------------");

    }

 }else{
        printf("\nError. El archivo no existe.");
    }
    fclose(archivo);
}

void mostrarTripulantes(mision m, int tripulantes){
    int i = 0;
    printf("\n- - - - - - - - - - - - - - - - -");
    for(i=0;i<tripulantes;i++){
        printf("ID tripulante %i: %i",i+1,m.idTripulantes[i]);
    }
    printf("\n- - - - - - - - - - - - - - - - -");
}

void modificarMisiones(){
    int idMision;
    printf("\n------------------------------\nCambiar estado de Mision\n\n------------------------------");
    char continuar = 's';
    do{
        do{
            printf("\nID mision: ");
            fflush(stdin);
            scanf("%i",&idMision);
            if(buscarMisionID(idMision)==0){
                printf("-Error. Mision no encontrada");
            }
        }while(buscarMisionID(idMision)==0);
        modificarUnaMision(idMision);
        printf("\n[s] para continuar cambiando misiones: ");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(continuar=='s');
}

int buscarTripulantePos(int dato){
    FILE *archivo=fopen(ARCHIVO_ASTRONAUTAS,"rb");
    astronauta a;
    int flag = -1;
    if(archivo!=NULL){
        while(fread(&a,sizeof(a),1,archivo)>0){
            if(a.ID==dato){
                flag=ftell(archivo)/sizeof(a);
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}

void agregarHorasVueloAstronautas(int horasVuelo, int horasEstacion, int tripulantes[MAX_TRIPULANTES], int tripulantesValidos){
    FILE *archivo=fopen(ARCHIVO_ASTRONAUTAS,"r+b");
    astronauta a;
    int i = 0;
    int posicion;
    for(i=0;i<tripulantesValidos;i++){
        posicion=buscarTripulantePos(tripulantes[i]);
        fseek(archivo,posicion+1,SEEK_SET);
        fread(&a,sizeof(a),-1,archivo);
        a.horasACUMULADASestacion=horasEstacion;
        a.horasDEvuelvoHechas=horasVuelo;
        a.misionesHechas++;
        fwrite(&a,sizeof(a),1,archivo);
    }
    fclose(archivo);
}

void misionFallaAstronautas(int tripulantes[MAX_TRIPULANTES], int tripulantesValidos){
    FILE *archivo=fopen(ARCHIVO_ASTRONAUTAS,"r+b");
    astronauta a;
    int i = 0;
    int posicion;
    for(i=0;i<tripulantesValidos;i++){
        posicion=buscarTripulantePos(tripulantes[i]);
        fseek(archivo,posicion+1,SEEK_SET);
        fread(&a,sizeof(a),-1,archivo);
        a.estado=2;
        fwrite(&a,sizeof(a),1,archivo);
    }
    fclose(archivo);
}

int buscarNavePos(int dato){
    FILE *archivo=fopen(ARCHIVO_NAVES,"rb");
    Nave n;
    int flag = 0;
    if(archivo!=NULL){
        while(fread(&n,sizeof(n),1,archivo)>0){
            if(n.ID==dato){
                flag=ftell(archivo)/sizeof(n);
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}

void agregarHorasVueloNaves(int horasVuelo, int horasEstacion, int id){
    FILE *archivo=fopen(ARCHIVO_NAVES,"r+b");
    Nave n;
    int posicion;
    posicion=buscarNavePos(id);
    fseek(archivo,posicion+1,SEEK_SET);
    fread(&n,sizeof(n),-1,archivo);
    n.CantVuelos++;
    n.HorasVuelos=horasVuelo+horasEstacion;
    strcpy(n.Estado,Mantenimiento);
    fwrite(&n,sizeof(n),1,archivo);
    fclose(archivo);
}

void misionFallaNaves(int id){
    FILE *archivo=fopen(ARCHIVO_NAVES,"r+b");
    Nave n;
    int posicion;
    posicion=buscarTripulantePos(id);
    fseek(archivo,posicion+1,SEEK_SET);
    fread(&n,sizeof(n),-1,archivo);
    strcpy(n.Estado,DeBaja);
    fwrite(&n,sizeof(n),1,archivo);
    fclose(archivo);
}

void misionInicioNaves(int id){
    FILE *archivo=fopen(ARCHIVO_NAVES,"r+b");
    Nave n;
    int posicion;
    posicion=buscarTripulantePos(id);
    fseek(archivo,posicion+1,SEEK_SET);
    fread(&n,sizeof(n),-1,archivo);
    strcpy(n.Estado,EnMision);
    fwrite(&n,sizeof(n),1,archivo);
    fclose(archivo);
}


void modificarUnaMision(int pos){
    FILE *archivo=fopen(ARCHIVO_MISIONES,"r+b");
    mision m;
    int dato;
    int horasV = 0, horasE = 0;
    if(archivo!=NULL){
        fseek(archivo,(sizeof(m)*pos)-1,SEEK_SET);
        fread(&m,sizeof(m),1,archivo);
        if(m.estado==1){
            do{
                printf("\nMision %i destino a %s:",m.id,m.destino);
                printf("\n[2]-En vuelo\n[4]-Cancelada\n-");
                fflush(stdin);
                scanf("%i",&dato);
                if(dato!=2&&dato!=4){
                    printf("-Error");
                }
            }while(dato!=2&&dato!=4);
            if(dato==2){
                misionInicioNaves(m.idNave);
            }
        }if(m.estado==2){
            do{
                printf("\nMision %i destino a %s:",m.id,m.destino);
                printf("\n[3]-Retornada\n[5]-Fallida\n-");
                fflush(stdin);
                scanf("%i",&dato);
                if(dato!=5&&dato!=3){
                    printf("-Error");
                }
            }while(dato!=5&&dato!=3);
            if(dato==3){
                printf("\nLa mision se da finalizada");
                do{
                    printf("\nIngresar horas en vuelo: ");
                fflush(stdin);
                scanf("%i",&horasV);
                }while(horasV<=0);
                do{
                    printf("\nIngresar horas (en caso de haber) en la Estacion Espacial Internacional: ");
                fflush(stdin);
                scanf("%i",&horasE);
                }while(horasE<0);
                agregarHorasVueloAstronautas(horasV,horasE,m.idTripulantes,m.tripulantes);
                agregarHorasVueloNaves(horasV,horasE,m.idNave);
            }else{
                misionFallaAstronautas(m.idTripulantes,m.tripulantes);
                misionFallaNaves(m.idNave);
            }
        }if(m.estado==3){
            printf("\nMision %i destino a %s: FINALIZADA",m.id,m.destino);
        }
        m.estado=dato;
        fseek(archivo,(sizeof(m)*pos)-1,SEEK_SET);
        fwrite(&m,sizeof(m),1,archivo);
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
}

int buscarMisionID(int dato){
    FILE *archivo=fopen(ARCHIVO_MISIONES,"rb");
    mision m;
    int flag = 0;
    if(archivo!=NULL){
        while(fread(&m,sizeof(m),1,archivo)>0){
            if(m.id==dato){
                flag=m.id;
            }
        }
        fclose(archivo);
    }else{
        printf("\nError. El archivo no existe.");
    }
    return flag;
}
