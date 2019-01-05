#include<stdio.h>
#include"cad.h"

int main()
{
    char nombre[]="Omar Alonso Osuna Angulo";
    char firstname[5]={'\0'};
    char lastname[7]={'\0'};
    char multiuso[50];
    char materia[]="Programacion Estructurada";
    
    printf("\nMi nombre es %s y tiene %d letras.\n", nombre, s_strlen(nombre)-3);

    s_memset(multiuso,'\0',50);

    s_strcpy(multiuso,"Espero pasar con 100 ");

    s_strcat(multiuso,materia);

    puts(multiuso);

    s_strncpy(firstname,nombre,4);
    printf("firstname: %s\n",firstname);
    s_memcpy(lastname,nombre+12,6);
    printf("lastname: %s\n",lastname);

    if(s_strstr(nombre,firstname)!= NULL) puts("firstname si esta en la cadena nombre");

    if(s_memcmp(nombre+12,lastname,6)==0) printf("\nLa cadena nombre contiene lastname: %s\n",lastname);

    if(s_memchr(firstname,'O',s_strlen(firstname))!=NULL) printf("firstname tiene por lo menos una O\n");

    s_memset(multiuso,'\0',50);

    s_strcpy(multiuso,"OMAR");

    puts("usando s_strcmpi");
    if(s_strcmpi(multiuso,firstname)==0) printf("%s es igual a %s\n",multiuso,firstname);
        else printf("%s no es igual a %s\n",multiuso,firstname);
    
    puts("usando s_strcmp");
    if(s_strcmp(multiuso,firstname)==0) printf("%s es igual a %s\n",multiuso,firstname);
        else printf("%s no es igual a %s\n",multiuso,firstname);
        
    return 0;
}
