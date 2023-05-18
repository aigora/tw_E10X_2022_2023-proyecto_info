#include <stdio.h>
#include "lectura.h"
#include "lectura_2.h"



//float mx() Calculo de la energia maxima de cada tecnologia
//float mn() Calculo de la energia minima de cada tecnologia
//float pro()  Calculo de la media de cada tecnologia
//float rel()  Calculo del valor relativo de cada tecnologia respecto al total
//void f_estadistica()  Fichero con el maximo, minimo y promedio de cada tecnologia
//void f_nuevo()  En el caso de querer usar un fichero adjunto nuevo




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
