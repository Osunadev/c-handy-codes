// Remueve los espacios de una cadena
//Ejemplo de uso: removeSpaces(frase);

void removeSpaces(char *cadena) {
	int i, count = 0; // count es la variable para llevar la cuenta de los caracteres que no son espacios

	for (i =0; i<strlen(cadena); i++) 
		if (cadena[i] != ' ') cadena[count++] = cadena[i]; // Incrementa el numero de caracteres en count

	cadena[count] = '\0'; // Agregandole el caracter vacio
}
