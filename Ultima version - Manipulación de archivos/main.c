#include <stdio.h>
#include "funciones.h"

int main(){

    //lee un archivo y lo copia en uno nuevo (archivo_auxiliar).
    //necesita el nombre del archivo. Ejemplo:
    //lectura("generacion_por_tecnologias_21_22.csv",1);

    //muestra el documento entero
    //mostrar_doc();

    //sustituye un dato y lo imprime en el archivo. necesita una fila, columna y texto
    //variables: Fila elegida, columna elegida, tipo de separador decimal, fila de fecha,
    //elección mostrar una generación de energía con una columna (1); necesita las primera cuatro variables,
    //sustituir (2); necesita que las dos primeras variables sean la fila de sustitución y la columna de sustitución respectivamente,
    //también necesita el texto nuevo teniendo sus separadores inciales y finales

    //mostrar dato:
    //seleccion_dato(6,2,',',5,1,";texto basura;");

    //sustitución (solo funciona para archivos con punto como separador decimal y no se puede sustituir ni la primera ni la última fila de datos):
    //seleccion_dato(9,3,',',5,2,",texto nuevo,");

    //muestra la primera columna y otra a eleccion hasta la ultima fila
    //necesita las primeras cuatro variables y la fila de fecha
    //int i, filas=lectura("generacion_por_tecnologias_21_22.csv",0);
    //for(i=5;i<=filas;i++){
    //   seleccion_dato(i,2,',',5,1,"texto basura");
    //   printf("\n");
    //}


    //funcion desicion, variables; fila de datos, columna de datos, tipo de separador decimal, fila de fecha,
    //seleccion sobre almacenar los datos de una fila (1) o una columna (2).

    //almacena una fila en un documento para su uso en funciones estadísticas
    //desicion(0,2,'.',5,1);

    //almacena una columna en un documento para su uso en funciones estadísticas
    //desicion(6,0,'.',5,2);

    return 0;
}
