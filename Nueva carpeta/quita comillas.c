#include <stdio.h>
#include <string.h>

typedef struct{
    char filai[200];
}lineas;

int main(){
    FILE *archivo;
    archivo=fopen("archivo_vectores.txt","r");

    int i,j,h,largo,filas=24;

    lineas datos[filas];


    for(i=0;i<filas;i++){
        fscanf(archivo,"%[^\n]\n",datos[i].filai);
    }


    for(j=0;j<filas;j++){
        largo=strlen(datos[j].filai);
        h=0;
        while(datos[j].filai[h]!='\0'){
            if(datos[j].filai[h]=='"'){
                for(i=h;i<largo;i++){
                    datos[j].filai[i]=datos[j].filai[i+1];
                }
                largo--;
            }

            if(datos[j].filai[h]==','){
                datos[j].filai[h]='.';
            }
            h++;
        }
    }

    FILE *vectores;
    vectores=fopen("archivo_vectores_sin_comillas.txt","w");
    for(i=0;i<filas;i++){
        fprintf(vectores,"%s\n",datos[i].filai);
    }
    fclose(vectores);

    return 0;
}
