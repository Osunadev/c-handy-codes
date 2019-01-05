#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Header{

    unsigned char id[2];
    unsigned char size[4];          // Tamanyo del archivo BMP
    unsigned char unused1[2];
    unsigned char unused2[2];
    unsigned char offset[4]; /*     Offset donde el arreglo de pixeles (bitmap data)
    puede ser encontrado. El bitmapdata es una clase que permite trabajar con
    los pixeles de un objeto Bitmap*/

    /*DIB Header*/
    unsigned char sizeDIB[4];       // Numero de bytes en el header DIB
    unsigned char ancho[4];         // Ancho de la img en px
    unsigned char altura[4];        // Altura de la img en px
    unsigned char colorplanes[2];
    unsigned char bpp[2];           // Numero de bits por px*/
    unsigned char BI_RGB[4];
    unsigned char rawBM[4];         // Tamanyo de bitmap data raw
    unsigned char Presolution1[4];
    unsigned char Presolution2[4];
    unsigned char colors[4];
    unsigned char favcolors[4];
  };


int main(int argc, char *argv[])
{
    FILE *imagen;
    struct Header headerinfo;
    unsigned char hex[8];
    unsigned char hexsize[9];

    long size_img,ancho,altura;

  if(argc>1)
  {
    imagen = fopen(argv[1], "rb");

    if (!imagen)
    {
      puts("No se pudo abrir la imagen bmp");
      exit(-1);
    }
    else
    {
      fread(&headerinfo, sizeof(struct Header), 1, imagen);

      if (headerinfo.id[0] =='B' && headerinfo.id[1]=='M') //Verificando que nuestro archivo sea bmp
      {
        /* TAMANO DE LA IMAGEN*/
        //Usamos sprintf para que el output del printf lo guarde en un arreglo
        sprintf(hex,"%x%x%x%x", headerinfo.size[3], headerinfo.size[2], headerinfo.size[1], headerinfo.size[0]);
        //memset para que el arreglo hexnum empiece con caracteres vacios
        memset(hexsize,'\0',9);
        strncpy(hexsize,hex,8);
        size_img = strtol(hexsize, NULL, 16);

        memset(hex,'\0',8);
        /* ALTURA DE LA IMAGEN */
        sprintf(hex,"%x%x%x%x", headerinfo.altura[3], headerinfo.altura[2], headerinfo.altura[1], headerinfo.altura[0]);

        memset(hexsize,'\0',9);
        strncpy(hexsize,hex,8);
        altura = strtol(hexsize, NULL, 16);

        memset(hex,'\0',8);
        /* ANCHURA DE LA IMAGEN */
        sprintf(hex,"%x%x%x%x", headerinfo.ancho[3], headerinfo.ancho[2], headerinfo.ancho[1], headerinfo.ancho[0]);

        memset(hexsize,'\0',9);
        strncpy(hexsize,hex,8);
        ancho = strtol(hexsize, NULL, 16);

        printf("\nID: %c%c",headerinfo.id[0],headerinfo.id[1]);
        printf("\nNombre de la imagen: %s",argv[1]);
        printf("\nTamano de la imagen: %ld ", size_img);
        if ( (size_img/1024)>1 ) printf("- %d Kb", size_img/1024);

        printf("\nAncho de la imagen: %ld pixeles\nAltura de la imagen: %ld pixeles\n",ancho,altura);
      }
    
    }    

      free(imagen);
  }
  else {
    puts("Error de utilizacion del programa.");
    puts("Ej. p11.exe imagen.bmp");
  }

  return 0;
}
