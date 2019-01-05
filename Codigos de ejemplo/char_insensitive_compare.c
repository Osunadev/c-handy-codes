// Si el resultado es 1, significa que son iguales
// Ejemplo de uso: igualdad = chariCompare(charAux[0],charAux[1]);

int chariCompare(char a, char b) {
	if (toupper(a) == toupper(b)) return 1;
		else return 0;
}

// Valores de retorno posibles:
// 1 - Si los dos caracteres son iguales
// 0 - Si los dos caracteres son diferentes