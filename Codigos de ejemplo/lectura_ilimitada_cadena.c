// Ejemplo de uso: 	msg = cadenaEntrada(stdin,20); // Leemos la cadena de entrada. El 20 es por el tamanyo inicial esperado

// Se utiliza para leer la entrada por teclado FILE *fp (stdin)
char *cadenaEntrada(FILE *fp, unsigned int size) {
	char *cad; // Apuntador para nuestra cad dinamica
	int ch; // Aux para guardar el caracter leido
	unsigned int longitud = 0; // La longitud de la cadena dinamica

	cad = (char *) malloc(sizeof(char) * size); // Se reserva un espacio inicial/provisional para la cadena dinamica
	if (cad == NULL) return NULL; // Si no se pudo reservar memoria, malloc nos regresa NULL (En realidad NULL es un valor de tipo (void *))

	// Se seguira leyendo caracter por caracter hasta llegar al EOF o hasta llegar al caracter vacio (fin de la cadena)
	//EOF es un valor que retorna getc cuando se ha llegado al End Of File
	while (EOF!=(ch = getc(fp)) && ch != '\n') {
		cad[longitud++] = ch;
		// Si se llego al limite reservado, se reserva mas memoria
		if (longitud == size) {
			cad = realloc(cad, sizeof(char)*(size*=2));
			// Si no se pudo reservar la memoria
			if (cad == NULL) return cad;
		}
	}

	cad[longitud] = '\0'; //Agregando el caracter vacio
	// Ajustando la memoria reservada solamente a la ocupada por la cadena
	if (!longitud) {
		free(cad);
		return NULL; //No se introdujo ningun caracter
	}

	return realloc (cad, sizeof(char) * longitud); //Ajustando el espacio del arreglo dinamico a solamente lo necesario
}

// Valores de retorno posibles:
// NULL - Si no introducimos ningun caracter
// char * - Si capturamos una cadena de por lo menos 1 caracter