#include <stdio.h>
#include <string.h>

typedef struct{
    float vector_dato[100];
}datos;

void lectura_2(char documento[]){

    char fila1[100];
    char temp;
    int i,j,filas=0,columnas=0,lomg;
    char letrasep[10];

    int imprimir;

    datos bloc[100];

    FILE *archivo;
    archivo=fopen(documento,"r");

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{
        //Número de filas
        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        //Almaceno la primera fila con un salto de línea desde el principio del archivo
        fseek(archivo,0,SEEK_SET);
        fscanf(archivo,"%[^\n]\n",&fila1);
        //Identifico la longitud del título
        lomg=strlen(fila1);

        //Bucle que depende del numero de separadores de la fila1
        //para contar el número de columnas del archivo
        for(i=0;i<=lomg;i++){
            if(fila1[i]==','){
                columnas++;
                strcpy(letrasep,"%f,"); //Además identifica el separador y lo usa
                                        //para almacenar los datos en los vectores
                                        //dependiendo del mismo separador
            }
            else if(fila1[i]=='\t'){
                columnas++;
                strcpy(letrasep,"%f\t");
            }
            else if(fila1[i]==';'){
                columnas++;
                strcpy(letrasep,"%f;");
            }
        }

        //Correspondiente a la última columna
        columnas++;

        //bucle de almacenaje que consta de un vector de estructuras
        //donde, para cada fila del archivo, el dato de cada columna
        //se dirige a un espacio del vector de esta estructura
        for(i=0;i<filas;i++){
            for(j=0;j<columnas;j++){
                fscanf(archivo,letrasep,
                        &bloc[i].vector_dato[j]);
            }
        }

        fclose(archivo);
    }

    printf("columnas: %i\nfilas: %i\n\n",columnas,filas);

    for(i=0;i<lomg;i++){
        if(fila1[i]==','){
            printf(" ");
        }
        else{
            printf("%c",fila1[i]);
        }
    }

    printf("\n");

    for(i=0;i<filas-1;i++){
        imprimir=0;
        for(j=0;j<columnas;j++){
            printf("%.0f ",bloc[i].vector_dato[j]);
            imprimir++;
            if(imprimir==columnas){
                printf("\n");
            }
        }
    }

    return 0;
}
