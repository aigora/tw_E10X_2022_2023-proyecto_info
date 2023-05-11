#include <stdio.h>
#include <string.h>

typedef struct{
    char filai[2000]
}lines;

void lectura(char documento[],int n_fila, int n_columna,char decimal,int fila_fecha){

    char temp[2000],columna[200],columna1[200],fila1[2000];
    int i,k,m,filas=0,pos=0,pos_impar,pos_impar_posterior,columnas=0,lomg;

    int j,select_pos;

    char separador[0];

    int vector_impar[100];

    lines almacenaje[100];

    FILE *archivo;
    archivo=fopen(documento,"r");

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{

        //Determinación de filas
        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        //Almaceno la primera fila
        fseek(archivo,0,SEEK_SET);
        fscanf(archivo,"%[^\n]\n",&fila1);
        lomg=strlen(fila1);

       //Determinación del numero de columnas
        for(i=0;i<lomg;i++){
            if(fila1[i]==','){
                columnas++;
                strcpy(separador,",");
            }
            else if(fila1[i]==';'){
                columnas++;
                strcpy(separador,";");
            }
            else if(fila1[i]=='\t'){
                columnas++;
                strcpy(separador,"\t");
            }
        }

        //Almacenaje de cada fila en cada cadena de caracteres
        //de cada espacio del vector de estructuras
        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    //Fila seleccionada por el usuario
    j=n_fila-1;
    //Columna seleccionada por el usuario
    select_pos=n_columna;

    //Almacenaje de los datos de la posición seleccionada.
    //Dependiendo si el separador de los decimales y del archivo
    //son la coma o no
    i=0;
    k=0;
    while(almacenaje[j].filai[i]!='\0'){

        if(almacenaje[j].filai[i]==separador[0]){
            pos++;

            if(j<=fila_fecha-1 && select_pos<=columnas){
                if(pos==select_pos-1){
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!=separador[0]){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            //Ultima columna
            else if(j<=fila_fecha-1 && select_pos==columnas+1){
                if(pos==columnas){
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!='\0'){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            else if(j>fila_fecha-1 && select_pos<=columnas && decimal=='.'){
                if(pos==select_pos-1){
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!=separador[0]){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            //Ultima columna
            else if(j>fila_fecha-1 && select_pos==columnas+1 && decimal=='.'){
                if(pos==columnas){
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!='\0'){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            else if(j>fila_fecha-1 && decimal==','){
                if(separador[0]==','){
                    if(pos%2!=0){
                        vector_impar[k]=i;
                        k++;
                    }
                }
                else if(separador[0]==';' || separador[0]=='\t'){
                    if(select_pos<=columnas){
                        if(pos==select_pos-1){
                            k=i+1;
                            m=0;
                            while(almacenaje[j].filai[k]!=separador[0]){
                                columna[m]=almacenaje[j].filai[k];
                                k++;
                                m++;
                            }
                        }
                    }
                    else if(select_pos==columnas+1){
                        if(pos==columnas){
                            k=i+1;
                            m=0;
                            while(almacenaje[j].filai[k]!='\0'){
                                columna[m]=almacenaje[j].filai[k];
                                k++;
                                m++;
                            }
                        }
                    }

                }
            }


        }
        i++;
    }


    if(separador[0]==',' && decimal==','){
        if(j>fila_fecha-1 && select_pos<=columnas){
            pos_impar=vector_impar[select_pos-2]+1;
            pos_impar_posterior=vector_impar[select_pos-1];
            m=0;
            while(pos_impar!=pos_impar_posterior){
                columna[m]=almacenaje[j].filai[pos_impar];
                pos_impar++;
                m++;
            }
        }
        else if(j>fila_fecha-1 && select_pos==columnas+1){
            pos_impar=vector_impar[columnas-1]+1;
            while(almacenaje[j].filai[pos_impar]!='\0'){
                columna[m]=almacenaje[j].filai[pos_impar];
                pos_impar++;
                m++;
            }
        }
    }


    i=0;
    while(almacenaje[j].filai[i]!=separador[0]){
        columna1[i]=almacenaje[j].filai[i];
        i++;
    }


    printf("%s: %s",columna1,columna);

    return 0;
}
