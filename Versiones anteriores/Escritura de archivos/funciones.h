#include <stdio.h>
#include <string.h>

typedef struct{
    char filai[2000]
}lines;


int lectura(char documento[]){

    char temp[2000];
    int i,filas=0;


    lines almacenaje[100];

    FILE *archivo;
    archivo=fopen(documento,"r");

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{

        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    FILE *escritura;
    escritura=fopen("archivo_auxiliar.csv","w");

    for(i=0;i<filas;i++){
        fprintf(escritura,"%s\n",almacenaje[i].filai);
    }

    fclose(escritura);

    return filas;
}

void mostrar_doc(){

    int i,filas=0;
    char temp[1000];

    lines almacenaje[100];

    FILE *archivo;
    archivo=fopen("archivo_auxiliar.csv","r");

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{

        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    for(i=0;i<filas;i++){
        printf("%s\n",almacenaje[i].filai);
    }

}


int seleccion_dato(int n_fila, int n_columna,char decimal,int fila_fecha,int eleccion,int fila_sust,int columna_sust,char texto_sust[]){

    FILE *sust;

    char temp[2000],columna[200],columna1[200],fila1[2000];
    int i,k,m,filas=0,pos=0,pos_impar,pos_impar_posterior,columnas=0,lomg;

    int pos_sustitucion;

    int j,select_pos;

    char separador[0];

    int vector_impar[100];

    lines almacenaje[100];

    FILE *archivo;
    archivo=fopen("archivo_auxiliar.csv","r");

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{

        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        fseek(archivo,0,SEEK_SET);
        fscanf(archivo,"%[^\n]\n",&fila1);
        lomg=strlen(fila1);

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


        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    j=n_fila-1;
    select_pos=n_columna;

    i=0;
    k=0;
    while(almacenaje[j].filai[i]!='\0'){

        if(almacenaje[j].filai[i]==separador[0]){
            pos++;

            if(j<=fila_fecha-1 && select_pos<=columnas){
                if(pos==select_pos-1){
                    pos_sustitucion=i;
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!=separador[0]){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            else if(j<=fila_fecha-1 && select_pos==columnas+1){
                if(pos==columnas){
                    pos_sustitucion=i;
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
                    pos_sustitucion=i;
                    k=i+1;
                    m=0;
                    while(almacenaje[j].filai[k]!=separador[0]){
                        columna[m]=almacenaje[j].filai[k];
                        k++;
                        m++;
                    }
                }
            }
            else if(j>fila_fecha-1 && select_pos==columnas+1 && decimal=='.'){
                if(pos==columnas){
                    pos_sustitucion=i;
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
                            pos_sustitucion=i;
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
                            pos_sustitucion=i;
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

            pos_sustitucion=vector_impar[select_pos-2];
            while(pos_impar!=pos_impar_posterior){
                columna[m]=almacenaje[j].filai[pos_impar];
                pos_impar++;
                m++;
            }
        }
        else if(j>fila_fecha-1 && select_pos==columnas+1){
            pos_impar=vector_impar[columnas-1]+1;

            pos_sustitucion=vector_impar[columnas-1];
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


    if(eleccion==1){
        printf("%s: %s",columna1,columna);
    }
    else if(eleccion==2){
        sust=fopen("archivo_vectores.txt","a+");
        fprintf(sust,"%s\n",columna);
        fclose(sust);
    }
    else if(eleccion=3){
        sustitucion(almacenaje[fila_sust-1].filai,texto_sust,columna_sust+1,separador,fila_sust);
    }


    i=0;
    while(columna[i]!='\0'){
        columna[i]=' ';
        i++;
    }

    i=0;
    while(columna1[i]!='\0'){
        columna1[i]=' ';
        i++;
    }


    return columnas;
}

void desicion(int fila, int columna, char decimal,int fila_fecha, int seleccion){

    int i;
    int filas=lectura("archivo_auxiliar.csv");
    int columnas=seleccion_dato(1,1,decimal,fila_fecha,0,0,0,'x')+1;

    remove("archivo_vectores.txt");

    switch(seleccion){
        case 1:
            for(i=fila_fecha+1;i<filas+1;i++){
                seleccion_dato(i,columna,decimal,fila_fecha,2,0,0,'x');
            }
        break;
        case 2:
            for(i=2;i<columnas+1;i++){
                seleccion_dato(fila,i,decimal,fila_fecha,2,0,0,'x');
            }
        break;
        default:
        break;
    }

}

void sustitucion(char texto[],char texto_sust[],int columna,char separador[],int fila_dest){

    int i,m,k,lon,lon2,contador=0,pos,pos_posterior;

    lon=strlen(texto);
    lon2=strlen(texto_sust);

    for(i=0;texto[i]!='\0';i++){
        if(texto[i]==separador[0]){
            contador++;
            if(contador==columna-1){
                pos=i;
            }
            if(contador==columna){
                pos_posterior=i;
            }
        }
    }

    char tex1[pos],tex2[lon-pos_posterior];
    char sustituto[lon+lon2-pos_posterior+pos];


    for(i=0;i!=pos;i++){
        tex1[i]=texto[i];
    }

    m=0;
    for(i=pos_posterior+1;i!=lon;i++){
        tex2[m]=texto[i];
        m++;
    }

    for(i=0;i<strlen(tex1);i++){
        sustituto[i]=tex1[i];
    }
    m=pos;
    for(i=0;i<strlen(texto_sust);i++){
        sustituto[m]=texto_sust[i];
        m++;
    }
    m=pos+strlen(texto_sust);
    for(i=0;i<strlen(tex2);i++){
        sustituto[m]=tex2[i];
        m++;
    }

    k=lon+lon2-pos_posterior+pos-1;
    for(i=k;sustituto[i]!='\0';i++){
        sustituto[i]=' ';
    }

    char temp[1000];
    int filas;

    lines almacenaje[100];

    FILE *archivo;
    archivo=fopen("archivo_auxiliar.csv","r+");

        while(fscanf(archivo,"%[^\n]\n",&temp)!=EOF){
            filas++;
        }

        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

    fclose(archivo);

    FILE *archivo2;
    archivo2=fopen("archivo_sustituido.txt","w");

        for(i=0;i<=filas;i++){

            if(i==fila_dest){
                fprintf(archivo2,"%s\n",sustituto);
            }
            else{
                fprintf(archivo2,"%s\n",almacenaje[i].filai);
            }
        }

    fclose(archivo2);

    printf("%s",sustituto);

}
