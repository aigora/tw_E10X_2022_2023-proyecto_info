#include <stdio.h>
#include<string.h>
#include "funciones.h"

int main(){

    int nmenu,eleccion,fil,col,fil_fecha;
    char texto[50],texto_sust[50],sep_decimal,textos;
    int i, n, x, y, filas;
    char texto_ora[300];

    _Bool booleano;

    booleano=0;

    do
        {
            printf("\t \t Red Electrica\n\n");
    printf("Elija una de las opciones:\n");

    printf("1.Introduccion\n");
    printf("2.informacion\n");
    printf("3.Datos en los ultimos anios\n");
    printf("4.Oficinas principales\n");
    printf("5.Calculos estadisticos\n");
    printf("6.Salir\n");

    scanf("%i", &n);

    switch(n)
    {
    case 1:
        {
            FILE *archivo = fopen("primer_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");

            break;
        }
    case 2:
        {
            printf("¿Que quieres saber?\n\n");
            printf("1) La historia de la empresa\n");
            printf("2) Negocio electrico en Espania e internacional\n");
            scanf("%i", &n);

            switch(n)
            {
            case 1:
                {
                    FILE *archivo = fopen("segundo_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");


                    break;
                }
            case 2:
                {
                    FILE *archivo = fopen("tercer_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");


                    break;
                }
            default:
                {
                    printf("\n\n.......ERROR........");
                    printf("\n\n");
                }
            }


            break;
        }
    case 3:
        {
            printf("1-Leer un archivo\n");
            printf("2-Mostrar el archivo en pantalla\n");
            printf("3-Mostrar un dato en especifico en pantalla\n");
            printf("4-Editar o sustituir un dato\n");
            printf("5-Mostrar la primera columna (titulos) y una columna entera de datos en específico\n");
            printf("6-Mostrar el archivo con la sustitucion en pantalla\n");
            printf("7-Seleccionar una columna entera de datos para funciones estadisticas\n");
            printf("8-Seleccionar una fila entera de datos para funciones estadisticas\n");
            printf("9-Salir\n");
            printf("\n\nPresiona solamente numeros: ");

            scanf("%i",&nmenu);

    switch(nmenu){
        case 1:
            system("cls");
            printf("Ingrese el nombre del archivo con su extension.\n");
            printf("Ejemplo: generacion_energia.csv\n\n");
            scanf("%s",texto);
            lectura(texto,1);

            system("cls");
            return main();
        break;
        case 2:
            system("cls");
            mostrar_doc(0);
            printf("\n\n");
            return main();
        break;
        case 3:
            system("cls");
            printf("Ingrese la fila y la columna del dato deseado y la fila corresponde a las fechas del modelo de archivo: ");
            scanf("%i %i %i",&fil,&col,&fil_fecha);
            printf("Ingrese el tipo de separador decimal: \n");
            fflush(stdin);
            scanf("%c",&sep_decimal);
            seleccion_dato(fil,col,sep_decimal,fil_fecha,1,";texto basura;",0);

            printf("\n\n");
            return main();
        break;
        case 4:
            system("cls");
            printf("Ingrese la fila y la columna del dato deseado y la fila corresponde a las fechas del modelo de archivo: ");
            scanf("%i %i %i",&fil,&col,&fil_fecha);
            printf("Ingrese el tipo de separador decimal: \n");
            fflush(stdin);
            scanf("%c",&sep_decimal);
            printf("Ingrese el texto nuevo con los separadores al inicio y al final de este y sin espacios: ");
            scanf("%s",texto_sust);
            seleccion_dato(fil,col,sep_decimal,fil_fecha,2,texto_sust,booleano);
            system("cls");
            return main();
        break;
        case 5:
            system("cls");
            printf("Seleccione la columna de datos y la fila corresponde a las fechas del modelo de archivo: ");
            scanf("%i %i",&col,&fil_fecha);
            printf("Ingrese el tipo de separador decimal: \n");
            fflush(stdin);
            scanf("%c",&sep_decimal);
            system("cls");
            for(i=5;i<=filas;i++){
               seleccion_dato(i,col,sep_decimal,fil_fecha,1,"texto basura",0);
               printf("\n");
            }

            printf("\n\n");
            return main();
        break;
        case 6:
            system("cls");
            mostrar_doc(1);
            printf("\n\n");
            return main();
        break;
        case 7:
            system("cls");
            printf("Seleccione la columna deseada y la fila corresponde a las fechas del modelo de archivo: ");
            scanf("%i %i",&col,&fil_fecha);
            printf("Ingrese el tipo de separador decimal: \n");
            fflush(stdin);
            scanf("%c",&sep_decimal);
            desicion(0,col,sep_decimal,fil_fecha,1);
            system("cls");
            return main();
        break;
        case 8:
            system("cls");
            printf("Seleccione la fila deseada y la fila corresponde a las fechas del modelo de archivo: ");
            scanf("%i %i",&fil,&fil_fecha);
            printf("Ingrese el tipo de separador decimal: \n");
            fflush(stdin);
            scanf("%c",&sep_decimal);
            desicion(fil,0,sep_decimal,fil_fecha,2);

            system("cls");
            return main();
        break;
        case 9:
            system("cls");
            printf("¿Seguro que quieres salir?\n");
            printf("\t1-Si\n\t2-Volver\n");
            scanf("%i",&nmenu);
            switch(nmenu){
                case 1:
                    return 0;
                break;
                case 2:
                    system("cls");
                    return main();
                break;
                default:
                break;
            }
        break;

        default:
            system("cls");
            return main();
        break;
    }


    //lee un archivo y lo copia en uno nuevo (archivo_auxiliar).
    //necesita el nombre del archivo. Ejemplo:
    //lectura("generacion_por_tecnologias_21_22_puntos.csv",1);



    //muestra el documento entero
    //mostrar_doc(booleano);



    //sustituye un dato y lo imprime en el archivo. necesita una fila, columna y texto
    //variables: Fila elegida, columna elegida, tipo de separador decimal, fila de fecha,
    //elección mostrar una generación de energía con una columna (1); necesita las primera cuatro variables,
    //sustituir (2); necesita que las dos primeras variables sean la fila de sustitución y la columna de sustitución respectivamente,
    //también necesita el texto nuevo teniendo sus separadores iniciales y finales
    //Hay que identificar el separador decimal

    //mostrar dato
    //seleccion_dato(6,2,'.',5,1,";texto basura;",0);

    //sustitución (solo funciona para archivos con punto como separador decimal y no se puede sustituir ni la primera ni la última fila de datos):
    //La variable 'booleano' deberá ser 0 si no ha habido cambios en el archivo, pero si se realiza una sustitución, deberá tomar el varlor 1

    //seleccion_dato(6,3,'.',5,2,",texto nuevo,",booleano);


    //muestra la primera columna y otra a eleccion hasta la ultima fila
    //necesita las primeras cuatro variables y la fila de fecha

    //int i, filas=lectura("generacion_por_tecnologias_21_22.csv",0);
    //for(i=5;i<=filas;i++){
    //   seleccion_dato(i,2,'.',5,1,"texto basura",0);
    //   printf("\n");
    //}

            break;
        }
    case 4:
        {
            do
            {

            printf("Tenemos varias oficinas. Dinos si tu ciudad se encuentra dentro o fuera de Espania.\n");
            printf("1) Dentro de Espania\n");
            printf("2) Fuera de Espania\n");
            scanf("%i", &x);

            switch (x)
            {
            case 1:
                {

                printf("\t\tPrincipales ciudades:\n\n");
                FILE *archivo = fopen("cuarto_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");
            break;

                }

            case 2:
                {
                printf("........Estamos trabajando en ello........\n");
                printf("\n\n");
                break;
                }
            default:
                {
                 printf("ERROR!!!. Solo puedes elegir entre las dos opciones.");
                 printf("\n\n");
                 break;
                }
            }
            }
            while (x>=3 || x<=0);

            break;
        }
    case 5:
        {
            printf("\n\n En esta parte podemos ver algunos calculos estadisticos de los diferentes campos en estos ultimos anios: \n");
            printf("(como por ejemplo: maximos, minimos y valor relativo)\n");
            printf("OBS: Estos dato estan divididos por filas y empieza por la fila 6 hasta el 23, donde estan ubicados los diferentes tipos en los ultimos 24 meses\n.");
            printf("Elije que fila quieres saber:\n");
            //    La funcion estadistica necesita 2 enteros que tendran que cumplir las condiciones especificadas en while.
            //Esos 2 enteros hacen referencia a las filas en las que se calcula para cada una su
//    valor maximo, su minimo ,su promedio y su valor relativo (en el caso de poder realizarlo).El primer entero selecciona la fila de arranque
//    y tiene que ser 6 o mayor sin superar el 23.
//    El segundo entero selecciona la ultima fila a calcular es decir que pone un limite a los calculos. Tiene que ser de valor 6 o mayor
//    sin superar el 23 y no puede ser menor que el primer entero.
      do
      {

          scanf("%i %i",&x,&y);
      }
      while((x>=6 && x<=23) && (y>=6 && y<=23) && (x<=y));
//    estadistica(x,y);
      //ejemplo para ver el uso de la funcion y eliminar al tener acabado el trabajo dejando el do-while de arriba
      estadistica(x,y);

            break;
        }
    default:
        {
            printf("\n\n");
            break;
        }


    }



        }
    while (n>=6 || n<=0);




//    desicion(6,0,'.',5,2);



    //funcion desicion, variables; fila de datos, columna de datos, tipo de separador decimal, fila de fecha,
    //seleccion sobre almacenar los datos de una fila (1) o una columna (2).

    //almacena una fila en un documento para su uso en funciones estadísticas
    //desicion(0,2,'.',5,1);

    //almacena una columna en un documento para su uso en funciones estadísticas
    //desicion(6,0,'.',5,2);

    return 0;
}
