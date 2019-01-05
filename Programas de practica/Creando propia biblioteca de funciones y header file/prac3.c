/* Practica 3

El objetivo de este programa es el poder brindarle al usuario un par de herramientas para que
pueda reforzar operaciones con numeros.

Este programa incluye 5 diferentes modalidades a elegir (reversa, digitos, suma, perfecto, amigos),
y para poder seleccionar aquella opcion que se desee, es necesario mandar valores por terminal debido
a que existen parametros por valor en el main.

En concreto, esta son las tareas que realiza el programa:

1. Si la opción es “reversa​” el programa deberá recibir un número entero para
escribirlo en reversa.

2. Si la opción es “digitos​” el programa deberá recibir un número entero para imprimir
el número de dígitos de éste.

3. Si la opción es “suma​” el programa deberá recibir un número entero para imprimir la
suma de sus dígitos.

4. Si la opción es “perfecto​” el programa deberá recibir un número entero para
imprimir si es un número perfecto o no. Un número perfecto es un entero que es igual
a la suma de los divisores propios menores que él mismo. Así, 6 es un número
perfecto, porque sus divisores propios son 1, 2 y 3; y 6 = 1 + 2 + 3.

5. Si la opción es “amigos​” el programa deberá recibir dos números enteros para
imprimir si son amigos. Dos números amigos son dos enteros positivos tales que la
suma de los divisores propios de uno de ellos es igual al otro (la unidad se considera
divisor propio, pero no lo es el mismo número).

Creado por: Omar Osuna.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"numfunc.h"

// Prototipos de funciones
void detener_pantalla(char *mensaje);
void msg_error();

int main(int arc, char* argv[])
{
    int numero = 0;

    if (arc < 3) {

        msg_error();
        detener_pantalla("\n\t Presione Enter para salir e intentelo de nuevo");
        
        return 1;
    }
    else {

        numero=atoi(argv[2]);

        if(strcmp("reversa",argv[1]) == 0)
            printf("El numero %d al reves es igual a %d", numero, reversa(numero));

        else if(strcmp("digitos",argv[1]) == 0)
            printf("El numero %d tiene %d digitos", numero, digitos(numero));

        else if(strcmp("suma",argv[1]) == 0)
            printf("La suma de los digitos del numero %d es %d", numero, suma(numero));

        else if(strcmp("perfecto",argv[1]) == 0){

            if (perfecto(numero) == 1) 
                printf("El numero %d si es un numero perfecto", numero);

            else
                printf("El numero %d no es un numero perfecto", numero);
        }

        else if(strcmp("amigos",argv[1]) == 0) {
            int a = 0, b = 0;

            a = atoi(argv[2]);
            b = atoi(argv[3]);

            amigos(a,b);
        }

        else {
            msg_error();
            detener_pantalla("\n\t Presione Enter para salir e intentelo de nuevo");
            return 1;
        }
    }

    detener_pantalla("\n\t Presione Enter para salir");
    
    return 0;
}

void detener_pantalla(char *mensaje) {
    printf(" \n %s \n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

void msg_error() {
    printf("\n\r El programa debe recibir dos parametros");
    printf("\n\r 1) Opcion de numero a elegir: reversa, digitos, suma, perfecto, amigos");
    printf("\n\r 2) Introducir numero o numeros deseados acorde a la modalidad elegida");

    printf("\n\n\r Ej. Introduciendo una modalidad y un solo numero: prac3.exe reversa 234");
    printf("\n\n\r Ej. Introduciendo una modalidad y dos numeros (solo valido con el modo amigos): prac3.exe amigos 7 8");

}
