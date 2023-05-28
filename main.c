#include<stdio.h>
#include<string.h>


int main()
{
    int i, n;
    char texto_ora[300];
    do
        {
            printf("\t \t Red Electrica\n");
    printf("Elija una de las opciones:\n");
    printf("1.Introduccion\n");
    printf("2.informacion\n");
    printf("3.Datos en los ultimos años\n");
    printf("4.Oficinas principales\n");
    printf("5.Eaaa\n");
    scanf("%i", &n);

    switch(n)
    {
    case 1:
        {
            FILE *archivo = fopen("primer_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);

            break;
        }
    case 2:
        {
            printf("¿Que quieres saber?\n\n");
            printf("1) La historia de la empresa\n");
            printf("2) Negocio electrico en Espania e internacional\n");
            scanf("%i", &n);

            switch(n)
            {
            case 1:
                {
                    FILE *archivo = fopen("segundo_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);


                    break;
                }
            case 2:
                {
                    FILE *archivo = fopen("tercer_texto.txt", "r");
            if(archivo == NULL)
            {
                printf("Ups....\n");
                printf("Hubo un error. Intente de nuevo.");

                return 1;
            }
            while(fgets(texto_ora, sizeof(texto_ora),archivo) != NULL)
            {
                printf("%s", texto_ora);
            }
            fclose(archivo);


                    break;
                }
            }




            break;
        }
    case 3:
        {

            break;
        }
    case 4:
        {

            break;
        }
    case 5:
        {

            break;
        }
    }



        }
    while (n>=6 || n<=0);


    return 0;
}

