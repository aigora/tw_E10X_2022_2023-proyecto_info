#include <stdio.h>
#include "funciones.h"

int main(){

    _Bool booleano;

    booleano=0;

    //lee un archivo y lo copia en uno nuevo (archivo_auxiliar).
    //necesita el nombre del archivo. Ejemplo:
    lectura("generacion_por_tecnologias_21_22_puntos.csv",1);



    //muestra el documento entero
    mostrar_doc(booleano);



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



      estadistica(5);
//    int i,filas=lectura("generacion_por_tecnologias_21_22.csv",0);
//    //desicion(6,0,'.',5,2);
//    FILE *pf;
//    char v1[50];
//    float x;
//    pf = fopen("archivo_vectores.txt","r");
//    if(pf == NULL)
//    {
//        printf("Error\n");
//    }
//    printf("%i\n", filas);
//    for(i=0;i<=filas;i++){
//            fscanf(pf,"%s", &v1[i]);
//            printf("%s\n", v1);
//        }






//    desicion(6,0,'.',5,2);



    //funcion desicion, variables; fila de datos, columna de datos, tipo de separador decimal, fila de fecha,
    //seleccion sobre almacenar los datos de una fila (1) o una columna (2).

    //almacena una fila en un documento para su uso en funciones estadísticas
    //desicion(0,2,'.',5,1);

    //almacena una columna en un documento para su uso en funciones estadísticas
    //desicion(6,0,'.',5,2);

    return 0;
}
