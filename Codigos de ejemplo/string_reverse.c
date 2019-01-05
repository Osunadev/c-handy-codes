// Invierte una cadena 
//Ejemplo de uso: stringReverse(fraseRev, frase, strlen(frase));

void stringReverse(char *destino, char* fuente, int size) {
	int i,j=0;

	// i controla el indice del arreglo fuente
	for (i=size-1; i>=0; i--) {
		destino[j++] = fuente[i];
	}
	destino[j] = '\0'; //Agregando el fin de linea
}