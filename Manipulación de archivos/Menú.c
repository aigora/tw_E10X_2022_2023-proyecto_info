#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

int main(){

    int nmenu,eleccion,fil,col,fil_fecha;
    char texto[50],texto_sust[50],sep_decimal,textos;
    int i, n, x, y, filas;
    char texto_ora[300];

    printf("\t \t Red Electrica\n\n");
    printf("Elija una de las opciones:\n\n");

    printf("1.Introduccion\n");
    printf("2.Informacion\n");
    printf("3.Lectura y escritura de datos\n");
    printf("4.Oficinas principales\n");
    printf("5.Calculos estadisticos\n");
    printf("6.Salir\n");
    printf("\n\nPresiona solamente numeros: ");

    scanf("%i", &n);

    switch(n)
    {
    case 1:
        system("cls");
        FILE *archivo = fopen("primer_texto.txt", "r");
        if(archivo == NULL)
        {
            printf("Ups....\n");
            printf("Hubo un error. Intente de nuevo.");
            return 0;
        }

        while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
        {
            printf("%s", texto_ora);
        }
        fclose(archivo);

        printf("\n\n");

        return main();
    break;
    case 2:
        system("cls");

        printf("¿Que quieres saber?\n\n");
        printf("1) La historia de la empresa\n");
        printf("2) Negocio electrico en Espania e internacional\n");

        printf("\n\nPresiona solamente numeros: ");

        scanf("%i", &n);

        switch(n)
        {
        case 1:
            system("cls");

            archivo = fopen("segundo_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

            return 0;
            }

            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");

            return main();


        break;
        case 2:
            system("cls");

            archivo = fopen("tercer_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 0;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            printf("\n\n");

            return main();
        break;
        default:
            system("cls");
            return main();
        break;
        }
    break;
    case 3:
        system("cls");
        printf("Esta parte tiene diferentes opciones a elegir, escoga una de ellas:\n\n\n");
        printf("1-Leer un archivo\n\n");
        printf("2-Mostrar el archivo en pantalla\n\n");
        printf("3-Mostrar un dato en especifico en pantalla\n\n");
        printf("4-Editar o sustituir un dato\n\n");
        printf("5-Editar o sustituir mas de un dato\n\n");
        printf("6-Mostrar la primera columna (titulos) y una columna entera de datos en específico\n\n");
        printf("7-Mostrar el archivo con la sustitucion en pantalla\n\n");
        printf("8-Seleccionar una columna entera de datos para funciones estadisticas\n\n");
        printf("9-Seleccionar una fila entera de datos para funciones estadisticas\n\n");
        printf("10-Volver al menu principal\n\n");
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
                printf("Ingrese la fila y la columna del dato deseado y la fila correspondiente a las fechas del modelo de archivo: ");
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
                seleccion_dato(fil,col,sep_decimal,fil_fecha,2,texto_sust,0);
                system("cls");
                return main();
            break;
            case 5:
                system("cls");
                printf("Ingrese la fila y la columna del dato deseado y la fila corresponde a las fechas del modelo de archivo: ");
                scanf("%i %i %i",&fil,&col,&fil_fecha);
                printf("Ingrese el tipo de separador decimal: \n");
                fflush(stdin);
                scanf("%c",&sep_decimal);
                printf("Ingrese el texto nuevo con los separadores al inicio y al final de este y sin espacios: ");
                scanf("%s",texto_sust);
                seleccion_dato(fil,col,sep_decimal,fil_fecha,2,texto_sust,1);
                system("cls");
                return main();
            break;
            case 6:
                system("cls");
                printf("Seleccione la columna de datos y la fila corresponde a las fechas del modelo de archivo: ");
                scanf("%i %i",&col,&fil_fecha);
                printf("Ingrese el tipo de separador decimal: \n");
                fflush(stdin);
                scanf("%c",&sep_decimal);
                system("cls");
                filas=lectura("archivo_auxiliar.csv",0);
                for(i=fil_fecha;i<=filas;i++){
                   seleccion_dato(i,col,sep_decimal,fil_fecha,1,"texto basura",0);
                   printf("\n");
                }

                printf("\n\n");
                return main();
            break;
            case 7:
                system("cls");
                mostrar_doc(1);
                printf("\n\n");
                return main();
            break;
            case 8:
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
            case 9:
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
            case 10:
                system("cls");
                return main();
            break;
            default:
                system("cls");
                return main();
            break;
        }

    break;
    case 4:
        system("cls");
        do
        {
            printf("Tenemos varias oficinas. Dinos si tu ciudad se encuentra dentro o fuera de Espania.\n");
            printf("1) Dentro de Espania\n");
            printf("2) Fuera de Espania\n");
            scanf("%i", &x);

            switch (x)
            {
            case 1:
                system("cls");
                printf("\t\tPrincipales ciudades:\n\n");
                FILE *archivo = fopen("cuarto_texto.txt", "r");
                if(archivo == NULL)
                {
                    printf("Ups....\n");
                    printf("Hubo un error. Intente de nuevo.");

                    return ;
                }

                while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
                {
                    printf("%s", texto_ora);
                }
                fclose(archivo);

                printf("\n\n");
                return main();
            break;
            case 2:
                system("cls");
                printf("........Estamos trabajando en ello........\n");
                printf("\n\n");
                return main();
            break;
            default:
                printf("ERROR!!!. Solo puedes elegir entre las dos opciones.");
                printf("\n\n");
            break;
            }
        }
        while (x>=3 || x<=0);

    break;  //REVISAR SI LAS FUNCIONES ESTADÍSTICAS OPERAN DE MANERA CORRECTA
    case 5:
            system("cls");
            printf("\n\n En esta parte podemos ver algunos calculos estadisticos de los diferentes campos en estos ultimos anios: \n");
            printf("(como por ejemplo: maximos, minimos y valor relativo)\n");
            printf("OBS: Estos dato estan divididos por filas y empieza por la fila 6 hasta el 23, donde estan ubicados los diferentes tipos en los ultimos 24 meses\n.");
            printf("Elije que fila quieres saber:\n");
            //    La funcion estadistica necesita 2 enteros que tendran que cumplir las condiciones especificadas en while.
            //    Esos 2 enteros hacen referencia a las filas en las que se calcula para cada una su
            //    valor maximo, su minimo ,su promedio y su valor relativo (en el caso de poder realizarlo).El primer entero selecciona la fila de arranque
            //    y tiene que ser 6 o mayor sin superar el 23.
            //    El segundo entero selecciona la ultima fila a calcular es decir que pone un limite a los calculos. Tiene que ser de valor 6 o mayor
            //    sin superar el 23 y no puede ser menor que el primer entero.
            //fflush(stdin);
            lectura("generacion_por_tecnologias_21_22_puntos.csv",1);
            do
            {
                scanf("%i %i",&x,&y);
            }
            while((x<6 || x>23) || (y<6 || y>23) || (x>y));
            estadistica(6,23);
    break;
    case 6:
        system("cls");
            printf("¿Seguro que quieres salir?\n");
            printf("\t1-Si\n\t2-Volver al menu principal\n");
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
        printf("\n\n");
        break;

    }

    return 0;
}
