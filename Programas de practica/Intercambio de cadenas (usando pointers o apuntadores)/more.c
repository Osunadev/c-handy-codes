#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    FILE* ftext; //apuntador al archivo de texto; apuntador a tipo FILE
    char c; //Donde se almacenara cada caracter
    int line = 0, lectura_inicio = 0;

    if(argc<2)
    {
        printf("Introduzca mas parametros por consola\n");
        printf("Ej: programa.exe archivo.txt");
        exit(-1);
    }

    ftext = fopen(argv[1],"rt"); //Leer texto
    
    if(!ftext) /* Tambien se puede expresar asi: if(ftext==NULL)*/
    {
        printf("No se pudo establecer el flujo con el archivo...\n");
        exit(-1);
    }
    
    while(!feof(ftext)) //Funcion que regresa 1 cuando llegamos al final del archivo (EOF: Usualmente -1, varia por sistema operativo)
    {
        c = fgetc(ftext); //Va recorriendo la posicion de su cursor hacia adelante hasta encontrar un caracter
        
        if(c=='\n') line++;
        
        printf("%c",c);
        
        if(line==15 && lectura_inicio == 0) 
        {
            printf("\nPresione enter para continuar con la lectura...\n");
            getchar();

            line = 0; /*Reiniciamos nuestro contador*/
            lectura_inicio++; //Aumentamos esta variable para que ya no pueda entrar a este if
        }

        if(line==10 && lectura_inicio == 1) //Se indica que ya se hizo la pausa del inicio con tolerancia de 15 lineas
        {
            printf("\nPresione enter para continuar con la lectura...\n");
            getchar();

            line = 0; /*Reiniciamos nuestro contador*/
        }
    }

    fclose(ftext);


    return 0;
}