#include<stdio.h>
#include"cad.h"

/*Copia la cantidad de caracteres especificados hacia otra cadena y regresa
la direccion de la cadena destino.*/
void * s_memcpy(void *destino, const void * fuente, int num)
{
    int i;

    for(i=0; i<num; i++)
    {
        *(unsigned char*) (destino+i) = *(unsigned char*) (fuente+i);
    }

    return destino;
}

/*Compara dos bloques de memoria acotados por un numero de bytes (num).
Regresa un 0 si str1 = str2, regresa > 0 si str1 > str2 y regresa
< 0 si str1 < str2. */
//Como un strcmp pero indicando el numero de elementos a comparar.
int s_memcmp(const void * str1, const void * str2, int num)
{
    int i = 0;
    int s1 = 0;
    int s2 = 0;

    for(i=0; i<num; i++)
    {
        s1 += *(char *) (str1+i);
        s2 += *(char *) (str2+i);
    }
    return (s1-s2);
}

/* Asigna un valor especificado a un bloque de memoria acotado por
un determinado numero de bytes.*/
void * s_memset(void *ptr, int valor, int nbytes)
{
  int i;

  for(i=0; i<nbytes; i++)
  {
    *(unsigned char*) (ptr+i) = (unsigned char) valor;
  }

  return ptr;
}


/*Busca la primera ocurrencia de un caracter en los primeros n bytes 
de la cadena especificada. La funcion regresa la direccion donde se
encontro la coincidencia, en caso que no se encuentre, regresa NULL.*/
void * s_memchr (void *fuente, int valor, int num) //Bien
{
    int i = 0;

    for(i=0; i<num; i++)
    {
        if(*(unsigned char*)(fuente+i) == valor)
        {   
            return (fuente+i);
        }
    }

    return NULL;
}

/*Copia una cadena fuente a una cadena destino y a la terminacion 
de la cadena se le anade el caracter vacio.*/
char * s_strcpy (char * destino, const char * fuente) //Bien
{
  int i, size_fuente = 0;

  /* Obteniendo el tamano de la cadena*/
  while (fuente[size_fuente++]!= '\0') //size++ tomando en cuenta el caracter vacio

  for(i=0; i<size_fuente; i++)
  {
    *(destino+i) = *(fuente+i);
  }

  *(destino+i) = '\0';/*Agregandole el caracter vacio*/

  return destino; //regresa la direccion de la cadena destino
}

/*Copia los primeros caracteres de fuente indicados (num) y copia en la
cadena destino. Si el numero de bytes indicados es mayor a la extension de 
la cadena fuente, se acompletara el numero de caracteres a pegar, con 
caracteres vacios*/
char * s_strncpy (char * destino, const char * fuente, int num)
{
   int i;

    for(i=0; i<num; i++)
    {
        if( *(fuente+i)!='\0' ) //Mientras no se encuentre con el caracter vacio
        {
            *(destino+i) = *(fuente+i);
        }
            else *(destino+i) = '\0';/*Agregandole el caracter vacio al resto de la cadena*/
    }

    return destino;
}

/*Concatenacion. Anade la cadena fuente al final de la cadena destino*/
char * s_strcat (char *destino, const char *fuente)
{
    int i,indx=0;
    int fin = s_strlen(destino);

    for(i=fin; i<(fin+s_strlen(fuente)); i++)
    {
        *(destino+i) = *(fuente+indx);
        indx++;
    }

    destino[i+1] = '\0';
    
    return destino;
}

/* Compara dos cadenas y regresa 0 si son iguales, > 0 si la primera es
mayor que la segunda y < 0 si la segunda es mayor que la primera.*/
int s_strcmp (const char * str1, const char * str2)
{
    int i,j;
    int s1 = 0;
    int s2 = 0;

    for(i=0; i<s_strlen(str1); i++) s1 += *(str1+i);
    for(j=0; j<s_strlen(str2); j++) s2 += *(str2+j);

    return (s1-s2);
}

/*Lo mismo que strcmp, pero no distinguiendo entre mayusculas y minusculas*/
int s_strcmpi (const char * str1, const char * str2) //Compara dos cadenas sin importar mayusculas o minusculas
{
    int i,j;
    int s1 = 0;
    int s2 = 0;

    for(i=0; i<s_strlen(str1); i++)
    {
        if( (*(str1+i))>64 && (*(str1+i))<91 ) //Si se encuentra en el intervalo de mayusculas
        {
            s1 += *(str1+i)+32; //La tomaremos como minuscula
        }
            else {
                s1 += *(str1+i);
            }
    }

    for(j=0; j<s_strlen(str2); j++)
    {
        if( (*(str2+j))>64 && (*(str2+j))<91 ) //Si se encuentra en el intervalo de mayusculas
        {
            s2 += *(str2+j)+32; //La tomaremos como minuscula
        }
            else {
                s2 += *(str2+j);
            }
    }

    return (s1-s2);
}

/*Busca la coincidencia de la cadena 2 en la cadena 1, si la hay, regresa la
direccion de inicio de la coincidencia en la cadena 1, si no, regresa NULL*/
char * s_strstr(char *str_base, const char *str_muest)
{
    int i;

    for(i=0; i<s_strlen(str_base); i++)
    {
        if( s_memcmp(str_base+i, str_muest, s_strlen(str_muest)) == 0) //Se encontro una coincidencia entre las dos cadenas
        {
            return (str_base+i); //Se devuelve la direccion en donde empieza la cadena de muestra
        }
    }

    return NULL;
}

/*Regresa la longitud de la cadena, sin tomar en cuenta el caracter vacio.
Regresa el size de la cadena y no el sizeof de la variable*/
int s_strlen(const char *str1) //Bien
{
    int size = 0;
    while (str1[size]!= '\0') size++;

    return (size);
}
