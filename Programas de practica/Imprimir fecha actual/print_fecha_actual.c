#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>

int main()
{
    time_t tiempoactual; //Estructura de tiempo
    struct tm *timeinfo;
    char *buffer_fecha = malloc(sizeof(char)*20);

    //time_t time(time_t *seconds)
    time(&tiempoactual); 
    /* Regresa el tiempo desde (00:00:00 UTC, January 1, 1970), medido en
    segundos. 

    Si "time_t *seconds" no es NULL, el valor retornado de la funcion es guardado en
    la varible "time_t *seconds" (en este caso tiempoactual)*/

    //struct tm *localtime(const time_t *timer)
    timeinfo = localtime(&tiempoactual); 
    /* Utiliza el tiempo señalado por "time_t *timer" (en este caso tiempoactual) para completar
    un struct tm con los valores que representan la hora local correspondiente. 

    El valor de "const time_t *timer" se divide en la "struct tm *timeinfo" y se expresa en la zona horaria local*/

    //size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr)
    strftime (buffer_fecha, 20,"%d/%m/%y.",timeinfo);
    /* Formatea el tiempo presentado en la "struct tm *timeptr" de acuerdo a las claves de formato
    definidas en format y guarda en str (en este caso char *buffer_fecha)*/

    printf("%s", buffer_fecha);
}
