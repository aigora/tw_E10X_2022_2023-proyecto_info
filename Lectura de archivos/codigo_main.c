#include <stdio.h>
#include "lectura.h"
#include "lectura_2.h"

int main(){

    //Se deben introducir los parámetros de:
    //nombre de archivo seleccionado
    //numero de fila del archivo que se quiere leer
    //numero de columna del archivo que se quiere leer
    //tipo de separador decimal
    //fila del archivo correspondiente a "fecha" del texto_modelo1
    lectura("generacion_por_tecnologias_21_22_puntos.csv",6,2,'.',5);

    return 0;
}
