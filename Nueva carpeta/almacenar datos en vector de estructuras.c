#include <stdio.h>
#include <string.h>

typedef struct{
    float vector;
}lineas;

int main(){
    int i,j,filas=17;

    FILE *archivo;
    //el nombre del archivo variará si los datos tienen comillas o no
    //archivo=fopen("archivo_vectores.txt","r");
    archivo=fopen("archivo_vectores_sin_comillas.txt","r");

    lineas datos[filas];

    if(archivo==NULL){
        printf("Error al abrir el archivo");
        return -1;
    }
    else{
        for(i=0;i<=filas-1;i++){
            fscanf(archivo,"%f",&datos[i].vector);
        }


        fclose(archivo);
    }

    for(j=0;j<=filas-1;j++){
        printf("%.2f",datos[j].vector);
        printf("\n");
    }


    return 0;
}
