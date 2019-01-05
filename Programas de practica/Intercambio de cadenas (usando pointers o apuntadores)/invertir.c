#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    char c; //Variable que usaremos para guardar caracteres de manera temporal
    FILE *ftxt1,*ftxt2; //Dos archivos de texto
    
    if(argc<2)
    {
        printf("\nIntroduzca mas parametros por consola\n");
        printf("Ej: invertir.exe nombre_archivo.txt \n  o bien: invertir.exe nombre_archivo.txt nombre_destino.txt\n");
        exit(-1);
    }

    /* Si solo se ingresa un nombre de un archivo de texto */
    if(argc==2)
    {
        ftxt1 = fopen(argv[1],"rt");
        /* Si no se puede crear el flujo y el apuntador toma valor de NULL */
        if(!ftxt1)
        {
            printf("Error al abrir flujo de archivo.");
            exit(-1);
        }

        while(!feof(ftxt1))
        {
            c = fgetc(ftxt1);  //Se guarda caracter del archivo en una variable char
            
            if(c>='a' && c<='z') printf("%c",(c-32)); //Se le resta -32 a una letra para que su equivalencia en ascii sea Mayuscula
                else if(c>='A' && c<='Z') printf("%c",(c+32)); //Se le suma +32 a una letra para que su equivalencia en ascii sea Minuscula
                    else printf("%c",c);

        }

        fclose(ftxt1); //Se cierra el flujo del archivo 1
    }

    /* Si se ingresan dos nombres de archivos de texto */
    if(argc==3)
    {
        
        ftxt1 = fopen(argv[1],"rt"); //Archivo fuente al cual se le extraera su contenido
        ftxt2 = fopen(argv[2],"w"); //Como el archivo ya existe se le borrara su contenido y se le copiara el contenido del archivo fuente
        
        if(!ftxt1 || !ftxt2)
        {
            printf("Error al abrir flujo de archivo.");
            exit(-1);
        }

        //c = fgetc(ftxt1); guarda caracter del archivo fuente en una variable char
        while(((c=fgetc(ftxt1))!=EOF)) //Mientras el caracter al que se apunta no sea EOF
        {
        if(c>='a' && c<='z') fputc((c-=32),ftxt2); //Se le agreagara el caracter 'c' al archivo con el flujo ftxt2
            else if(c>='A' && c<='Z') fputc((c+=32),ftxt2); 
                else fputc(c,ftxt2); 
        
            printf("%c",c);
        }

        fclose(ftxt1);
        fclose(ftxt2);
    }
    return 0;
}