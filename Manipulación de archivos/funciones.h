#include <stdio.h>
#include <string.h>

typedef struct
{
    char filai[2000];
}lines;

typedef struct
{
    double num[50];
}lin;

typedef struct
{
    char tec[6];
}energia;


//Funcion que lee el archivo original y lo copia en un archivo auxiliar
//entrega un entero que es el número de filas del archivo elegido
int lectura(char documento[],int inicio){

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
    if(inicio==1){
        escritura=fopen("archivo_auxiliar.csv","w");

        for(i=0;i<filas;i++){
            fprintf(escritura,"%s\n",almacenaje[i].filai);
        }
        fclose(escritura);
    }

    return filas;
}


//Muestra el archivo auxiliar por filas en la terminal
void mostrar_doc(int booleano){

    //uso de la funcion lectura para el numero de filas del archivo
    int i,filas=lectura("archivo_auxiliar.csv",0);

    lines almacenaje[100];

    FILE *archivo;
    if(booleano==0){
        archivo=fopen("archivo_auxiliar.csv","r");
    }
    else if(booleano==1){
        archivo=fopen("archivo_sustituto.txt","r");
    }

    if(archivo==NULL){
        printf("No se ha encontrado el archivo\n");
        return -1;
    }
    else{
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    for(i=0;i<filas;i++){
        printf("%s\n",almacenaje[i].filai);
    }

}

//Funcion que almacena en una cadena de caracteres el dato de una columna y fila específica
//Las variables de las que depende son: fila y columna seleccionadas, tipo de separador decimal,
//localización de la fila de fechas (siguiendo el modelo de archivo) y texto de sustitución
//Dependiendo de la variable 'elección' realizará 3 tareas que se explicarán más adelante
int seleccion_dato(int n_fila, int n_columna,char decimal,int fila_fecha,int eleccion,char texto_sust[],int booleano){

    FILE *sust;

    char columna[200],columna1[200],fila1[2000];
    int i,k,m,pos=0,pos_impar,pos_impar_posterior,columnas=0,lomg;
    int filas=lectura("archivo_auxiliar.csv",0);

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

        fscanf(archivo,"%[^\n]\n",&fila1);
        lomg=strlen(fila1);

        //cuenta el número de columnas-1 en el archivo dependiendo del número
        //de separadores que contiene la fila1 y lo identifica y almacena en un caracter
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

        //Almacena cada fila en el vector de estructuras
        fseek(archivo,0,SEEK_SET);
        for(i=0;i<=filas;i++){
            fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
        }

        fclose(archivo);
    }

    //Para localizar el dato deseado se hace uso del numero de separadores o columnas
    //Para almacenar el dato en sí hace falta la "posición" del separador siguiente en la cadena de caracteres
    //Para ello se hace uso de una variable 'pos'
    //Según el modelo de archivo, las filas de datos vienen tras una fila de fechas, se diferencian dos casos
    //Uno en el que el separador y el separador decimal son ',', y otro en el que no son iguales

    j=n_fila-1;
    select_pos=n_columna;

    i=0;
    k=0;
    while(almacenaje[j].filai[i]!='\0'){

        if(almacenaje[j].filai[i]==separador[0]){
            pos++;

            //Si la fila seleccionada está antes de la fila de fechas se almacena simplemente por el numero de separadores,
            //ya que no hay números con decimales. Se resta 1 en el if debido a que la fila uno se almacena en el espacio cero del vector de estructuras
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
            }//Si el separador y el separador decimal no son iguales los datos se almacenan normalmente
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
            }//El contador de separadores no aplica para la última columna al no haber un separador posterior, por lo que se hace uso de '\0' como condición
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
            }//Si el separador y el separador decimal son ',', entonces se almacenan las posiciones
            //correspondientes a los separadores en un vector, esto se realiza identificando las variables 'pos' que son impares,
            //ya que, para el primer separador, tomaría el valor uno, y para el separador decimal, tomaría el valor 2
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
                    }//condición para la última columna
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

    //Para el almacenaje de lo datos donde los dos separadores son ',' se hace uso del vector_impar
    //que almacena las posiciones correspondientes a los separadores
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
        }//Condición para la última fila
        else if(j>fila_fecha-1 && select_pos==columnas+1){
            pos_impar=vector_impar[columnas-1]+1;

            while(almacenaje[j].filai[pos_impar]!='\0'){
                columna[m]=almacenaje[j].filai[pos_impar];
                pos_impar++;
                m++;
            }
        }
    }


    //Almacenaje para la primera fila
    i=0;
    while(almacenaje[j].filai[i]!=separador[0]){
        columna1[i]=almacenaje[j].filai[i];
        i++;
    }

    //Variables para la opción de sustitución
    int fila_sust,columna_sust;

    //La variable 'elección' ofrece tres opciones:

    //Imprimir el dato almacenado junto al título de su energía correspondiente
    if(eleccion==1){
        printf("%s: %s",columna1,columna);
    }//Sustituir un dato
    else if(eleccion==2){
        fila_sust=n_fila;
        columna_sust=n_columna;
        sustitucion(almacenaje[fila_sust-1].filai,texto_sust,columna_sust+1,separador,fila_sust,booleano);
    }//Imprimir en un archivo los datos de una columna entera o de una fila entera (Esta opción solo está disponible para la función 'desicion' que se explicará más adelante)
    else if(eleccion=3){
        sust=fopen("archivo_vectores.txt","a+");
        fprintf(sust,"%s\n",columna);
        fclose(sust);
    }


    //Debido a que, en un princio, se desconoce la longitud de la cadena de caracteres a almacenar, se hace un "borrado" cada vez que se almacena una segunda vez
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

    //Al quedar almacenado, esta cadena de caracteres se pule eliminando los espacios sobrantes al cambiar de longitud a la cadena
    int h=0;
    int largo=strlen(columna);
    i=0;
    while(columna[h]!='\0'){
        if(columna[h]==' '){
            for(i=h;i<largo;i++){
                columna[i]=columna[i+1];
            }
            largo--;
        }
        h++;
    }

    h=0;
    int largo2=strlen(columna1);
    i=0;
    while(columna1[h]!='\0'){
        if(columna1[h]==' '){
            for(i=h;i<largo2;i++){
                columna1[i]=columna1[i+1];
            }
            largo--;
        }
        h++;
    }

    //Esta función también se usa para que entregue el número de columnas del archivo
    return columnas;
}

//Esta función imprime una fila entera o una columna entera  en un archivo haciendo uso de la función de almacenaje de un dato
//Necesita las variables de localización del dato con la fila y la columna, el tipo de separador decimal, la fila correspondiente a las fechas
//y la tercera opción que solo esta disponible para esta función
void desicion(int fila, int columna, char decimal,int fila_fecha, int seleccion){

    int i;
    int filas=lectura("archivo_auxiliar.csv",0);
    int columnas=seleccion_dato(0,0,decimal,fila_fecha,0,"x",0)+1;

    remove("archivo_vectores.txt");

    switch(seleccion){
        case 1:
            for(i=fila_fecha+1;i<filas+1;i++){
                seleccion_dato(i,columna,decimal,fila_fecha,3,"x",0);
            }
        break;
        case 2:
            for(i=2;i<columnas+1;i++){
                seleccion_dato(fila,i,decimal,fila_fecha,3,"x",0);
            }
        break;
        default:
        break;
    }

}

//Esta función hace uso de una cadena de texto de una fila en específico, localiza la posición de los separadores anterior y posterior de la columna elegida
//y almacena en dos cadenas de caracteres todo el texto anterior al separador anterior y todo el texto posterior al separador posterior, en una tercera cadena de caracteres llamada 'sustituto'
//une el texto anterior, el texto a sustituir, y el texto posterior
void sustitucion(char texto[],char texto_sust[],int columna,char separador[],int fila_dest, int booleano){


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

    //Tras realizar la sustitución, imprime el archivo introduciendo la nueva cadena de caracteres en su fila correspondiente
    int filas=lectura("archivo_auxiliar.csv",0);

    lines almacenaje[100];

    FILE *archivo;
    if(booleano==0){
        archivo=fopen("archivo_auxiliar.csv","r");
    }
    else if(booleano==1){
        archivo=fopen("archivo_sustituto.txt","r");
    }

    fseek(archivo,0,SEEK_SET);
    for(i=0;i<=filas;i++){
        fscanf(archivo,"%[^\n]\n",&almacenaje[i].filai);
    }

    fclose(archivo);

    FILE *archivo2;
    archivo2=fopen("archivo_sustituto.txt","w");

        for(i=0;i<=filas;i++){
            if(i==fila_dest-1){
                fprintf(archivo2,"%s\n",sustituto);
            }
            else{
                fprintf(archivo2,"%s\n",almacenaje[i].filai);
            }
        }

    fclose(archivo2);
}









//Funcion cuya utilidad es hallar el valor maximo de una serie de datos, es decir, datos almacenados en un vector de tipo double
//La funcion devuelve un valor de tipo double y tiene como argumentos un vector de tipo double y un valor entero entregados en la funcion estadistica.

double MX(double v[],int n)
{
    int i;
    double mx;
    mx=v[0];
    for(i=0;i<n;i++)
    {
        if(v[i]>mx)
        {
            mx=v[i];
        }
    }
    return mx;
}





//Funcion cuya utilidad es hallar el valor minimo de una serie de datos, es decir, datos almacenados en un vector de tipo double.
//La funcion devuelve un valor de tipo double y tiene como argumentos un vector de tipo double y un valor entero entregados en la funcion estadistica.

double MN(double v[],int n)
{
    int i;
    double mn;
    mn=v[0];
    for(i=0;i<n;i++)
    {
        if(v[i]<mn)
        {
            mn=v[i];
        }
    }
    return mn;
}






//Funcion cuya utilidad es hallar el valor promedio de una serie de datos, es decir, datos almacenados en un vector de tipo double
//La funcion devuelve un valor de tipo double y tiene como argumentos un vector de tipo double y un valor entero entregados en la funcion estadistica.

double PRO(double v[],int n)
{
    int i;
    double pro=0.0;
    for(i=0;i<n;i++)
    {
        pro=pro+v[i];
    }
    pro=pro/n;
    return pro;
}







//Esta funcion sirve para calcular el valor maximo, el minimo, el promedio y el valor relativo (siendo m igual a 23) de un fichero que se crea en la funcion limpiar y se lee en esta guardando los datos
//en vectores de estructuras para poder aplicar los calculos estadisticos que seran presentados en un fichero aparte "estadistica.txt" y en la pantalla (a parte en la pantalla se imprime los datos
//de cada tecnologia en columna). Esta funcion no devuelve nada (void) y como argumentos hay que introducir dos enteros que seran la fila de arranque y la fila de finalizacion respectivamente,
//señalizando las filas en las que se calculan esos valores estadisticos. El primer entero tiene que ser el 6 (el 6 marca la fila de hidraulica) o mayor sin superar el 23 y el segundo termino tiene que
//ser 6 o mayor sin superar al 23 y no puede ser menor que el primer termino, si el segundo termino es 23 se calcula el valor relativo de las filas contenidas y seleccionadas entre ambos enteros.
//Esta funcion hace llamada a la funcion desicion y la funcion limpiar, explicadas junto a su declaracion.


void estadistica(int n, int m)
{
    FILE *pf;
    FILE *estad;
    int i,j,k,l,filas=lectura("archivo_auxiliar.csv",0)+1;
    lin v1[filas];
    lin rel[filas];
    double mx[filas],mn[filas],pro[filas];
    energia tecno[18] = {
    {"Hidra"},
    {"Turbi"},
    {"Nucle"},
    {"Carbo"},
    {"Fuel "},
    {"Motor"},
    {"Turbi"},
    {"Turbi"},
    {"Ciclo"},
    {"Hidro"},
    {"Eolic"},
    {"Solar"},
    {"Solar"},
    {"Otras"},
    {"Cogen"},
    {"Nreno"},
    {"Renov"},
    {"Total"},
    };


    k=0;
    for(i=n;i<=m;i++)
    {
        desicion(i,0,'.',5,2);
        limpiar();
        pf=fopen("archivo_vectores_sin_comillas.txt","r");
        if(pf==NULL)
        {
            printf("Error");
        }
        for(j=0;j<filas;j++)
        {
            fscanf(pf,"%lf",&v1[k].num[j]);
        }
        k++;
    }
    for(i=0;i<=m-n;i++)
    {
        mx[i]=MX(v1[i].num,filas);
        mn[i]=MN(v1[i].num,filas);
        pro[i]=PRO(v1[i].num,filas);
    }
    k=0;
    if(m==23)
    {
        for(i=0;i<filas;i++)
        {
            for(j=0;j<m-n;j++)
            {
                rel[i].num[j]=(v1[j].num[i]/v1[m-n].num[i])*100;
            }
        }
    }


    estad=fopen("estadistica.txt","w");
    if(estad==NULL)
    {
        printf("Error al abrir fichero");
    }
    l=n-6;
    fprintf(estad,"\tMaximo\t\tMinimo\t\tPromedio\n");
    for(i=0;i<=m-n;i++)
    {
        fprintf(estad,"%s\t%f\t%f\t%f\n",tecno[l].tec,mx[i],mn[i],pro[i]);
        l++;
    }
    fprintf(estad,"\nValor relativo mensual:\n");
    for(i=0;i<filas;i++)
    {
        l=n-6;
        for(j=0;j<m-n;j++)
        {
            fprintf(estad,"%s\t%f\n",tecno[l].tec,rel[i].num[j]);
            l++;
        }
        fprintf(estad,"**********\n");
    }


    printf("---------------\n");
    for(j=0;j<=m-n;j++)
    {
        for(i=0;i<filas;i++)
        {
            printf("%f\n",v1[j].num[i]);
        }
        printf("---------------\n");
    }
    for(i=0;i<=m-n;i++)
    {
        printf("%f\t%f\t%f\n",mx[i],mn[i],pro[i]);
    }
    printf("\nValor relativo mensual:\n");
    for(i=0;i<filas;i++)
    {
        for(j=0;j<m-n;j++)
        {
            printf("%f\n",rel[i].num[j]);
        }
        printf("**********\n");
    }
}










//Esta funcion sirve para "limpiar" el fichero archivo_vectores creado anteriormente gracias a la funcion desicion de forma que en esta funcion se crea un fichero
//nuevo que contiene los valores de cada tecnologia en forma de columna quitando los caracteres que no sean numeros para poder asi guardar estos datos en un vector de estructuras.
//La funcion no tiene argumentos y no devuelve nada (void).

void limpiar()
{
    FILE *archivo;
    archivo=fopen("archivo_vectores.txt","r");

    int i,j,h,largo,filas=lectura("archivo_vectores.txt",0);
    lines datos[filas];

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
    fclose(archivo);
    fclose(vectores);
}











