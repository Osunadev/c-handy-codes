/*
 Practica #2 - Estructuras de Datos y el principio LIFO
 
 - Alumno: Osuna Angulo Omar Alonso (12346437)
 
 - Competencia: Implementar soluciones de software creativas utilizando eficientemente 
   las estructuras estáticas y el principio LIFO. 
 
 - Descripcion de la Practica: 
    
 
  Se pide diseñar e implementar un algoritmo basado en pilas estáticas que reciba una expresión dada por el usuario y evalúe si 
  la expresión se lee de igual manera de izquierda a derecha que de derecha a izquierda.  Por ejemplo, si la frase que proporciona 
  el usuario es: “La ruta natural”, el programa debe arrojar como resultado: 
 
 		Comparando L con l. 
 		Comparando a con a. 
 		Comparando r con r. 
 		Comparando u con u. 
 		Comparando t con t. 
 		Comparando a con a. 
 		Comparando n con a. 
 		Comparando a con a. 
 		Comparando t con t. 
 		Comparando u con u. 
 		Comparando r con r. 
 		Comparando a con a. 
 		Comparando l con L. 
 
	Todos los caracteres son iguales, la frase se lee igual en ambos sentidos. 

    Requisitos:
 
	* La frase debe empezar a evaluarse después de haber sido capturada. 
	* La frase proporcionada por el usuario puede incluir espacios, letras y números. 
	* Al comparar se deben considerar iguales las mayúsculas y las minúsculas. 
	* El algoritmo debe ignorar los espacios al evaluar la frase. 
	* La frase debe ser evaluada utilizando el principio LIFO. 
	* El programa debe presentar cada pareja de caracteres que se esté comparando durante el proceso de evaluación de la expresión. 
	* Las expresiones deben tener al menos un carácter. 
	* El tamaño máximo de la expresión será preestablecido por el programador, pero el usuario podrá introducir expresiones de menor tamaño. 
	* El lenguaje de programación a utilizar es libre, C o Java. 
	* El programa debe repetirse N veces, hasta que el usuario elija la opción de salida. 
 
 - Fecha de Entrega: Viernes 21 de Septiembre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototipos de funcion
void menuOpc();
char pop(int *tope, char* pila);
void push(int *tope, char* pila, char valor);
void stringReverse(char *destino, char* fuente, int size);
void removeSpaces(char *cadena);
int chariCompare(char a, char b);

int main() {

	char frase[50], fraseRev[50], charAux[2], opc;
	int i,tope = 0, topeRev = 0, igualdad, diferencia;

	do {
		menuOpc();
		opc = getchar();

		if (opc == '1') {
			getchar();
			printf("Frase/palabra palindorme a introducir: ");
			gets(frase);

			// si mi expresion tiene al menos 1 caracter
			if (strlen(frase) > 0) {

				removeSpaces(frase); // Removiendo los espacios vacios
				tope = strlen(frase) - 1; //Asignando al tope el indice de nuestro ultimo caracter

				stringReverse(fraseRev, frase, strlen(frase));
				topeRev = tope; //Asignando el mismo valor de tope debido a que son del mismo tamaño

				printf("\nComparando letra por letra la frase, al derecho y al reves\n\n");
				while (tope >= 0) {
					charAux[0] = pop(&tope,frase);
					charAux[1] = pop(&topeRev,fraseRev);
					
					// Si el resultado es 1, significa que son iguales
					igualdad = chariCompare(charAux[0],charAux[1]);
					if (!igualdad) diferencia = 1; //De esta manera sabre cuando son diferentes
					
					printf("Comparando '%c' con '%c': %s\n", charAux[0], charAux[1], (igualdad == 1) ? "Iguales" : "Diferentes");
				}
				
				printf("\n\t\t%s palabra/frase palindrome\n", (diferencia == 0) ? "Es una" : "No es una");
			}
			else printf("\n\t\tPor favor introduzca una frase valida con al menos 1 caracter.\n");
		}
        diferencia = 0; // Para que siempre se reinicie el estado de esta variable al empezar el ciclo
	} while (opc != '2');


	return 0;
}

void menuOpc(char op1[]) {
    printf("\nBienvenido al analizador de palabras palindromes\n");
    printf("1) Introduzca una palabra/frase para ser analizada\n");
    printf("2) Salir del programa");
    printf("\n\nSeleccionar opcion: ");
}

char pop(int *tope, char* pila) {
	(*tope)--;

	return pila[(*tope)+1];
}

void push(int *tope, char* pila, char valor) {
	(*tope)++;
	pila[*tope] = valor;
}

void stringReverse(char *destino, char* fuente, int size) {
	int i,j=0;

	// i controla el indice del arreglo fuente
	for (i=size-1; i>=0; i--) {
		destino[j++] = fuente[i];
	}
	destino[j] = '\0'; //Agregando el fin de linea
}

void removeSpaces(char *cadena) {
	int i, count = 0; // count es la variable para llevar la cuenta de los caracteres que no son espacios

	for (i =0; i<strlen(cadena); i++) 
		if (cadena[i] != ' ') cadena[count++] = cadena[i]; // Incrementa el numero de caracteres en count

	cadena[count] = '\0'; // Agregandole el caracter vacio
}

// Char insensitive compare
int chariCompare(char a, char b) {
	if (toupper(a) == toupper(b)) return 1;
		else return 0;
}