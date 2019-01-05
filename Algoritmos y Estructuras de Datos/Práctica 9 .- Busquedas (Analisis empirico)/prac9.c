/*
 Práctica No. 9 Análisis de Algoritmos Empírico en búsquedas recursivas.

 - Alumno: Osuna Angulo Omar Alonso (12346437)

 - Competencia:  Clasificar los algoritmo de búsqueda según su desempeño en escenarios de prueba con distintos parámetros,
  para ser la selección del método más adecuado para la solución de problemas de manejo de información.

 - Descripcion de la Practica:

	Búsqueda Binaria

		Este método requiere que el arreglo este previamente ordenado. La búsqueda binaria funciona de la
		siguiente manera:

		- Calcular el centro de la lista, con la fórmula (izquierdo+derecho)/2. Izquierdo y derecho son las
		posiciones del elemento menor y mayor del vector.
		- Encontrar el elemento central del arreglo, la llave se compara con el centro si es igual aquí
		termina la búsqueda.
		- Si no es igual determinar si la llave se encuentra en el lado izquierdo o derecho de la lista.
		- Redefinir el inicio o el final según donde ese haya ubicado la llave. Si la llave es mayor que el
		centro entonces izquierdo=centro+1. Si la llave es menor que el centro entonces derecho=centro-1
		- Repetir desde el primer paso hasta encontrar el dato o hasta que ya no sea posible dividir más.
		- Si la llave no fue encontrada regresar -1.

	Búsqueda Interpolada

		Si los datos están distribuidos de forma uniforme, este método puede ser más eficiente que la búsqueda
		binaria. Básicamente el algoritmo es el mismo que el de la búsqueda binaria. La diferencia radica en
		que en la búsqueda interpolada no se busca el dato en el centro del arreglo, sino que se calcula su
		posición aproximada con la siguiente fórmula:

				pos = i+( ((j-i)*(x-array[i])) / (array[j]-array[i]) )

		Implemente la búsqueda binaria e interpolada para tamaño N,

		Utilizando inicialmente un arreglo tipo int de 20 posiciones elabore una tabla con los siguientes datos:

		a) El tiempo para el peor de los casos
		b) El tiempo para el mejor de los casos
		c) El tiempo para cualquier otro caso
		d) La cantidad de iteraciones realizadas en ambas búsquedas para cada caso
		e) ¿Qué pasa al cambiar el tipo de datos del vector de int a float?

		f) ¿Qué pasa al aumentar el tamaño de N?
		g) ¿Qué pasa si el elemento NO está en el arreglo

		Determine nuevamente los incisos a-g pero con la búsqueda interpolada.
		h) ¿Se puede utilizar la búsqueda binaria para cadenas? ¿Si o no, por qué?
		i) ¿Se puede utilizar la búsqueda interpolada para cadenas? ¿Si o no, por qué?

    Requisitos:

    *  No se pide que capture las datos, inicialice los arreglos con los valores necesarios.
 	*	Las funciones deben presentar en todo momento en pantalla los datos sobre los que se está realizando la búsqueda.
 	*	Lenguaje libre.
	
	Elabore un reporte que incluyelos resultados obtenidos y las conclusiones.

 - Fecha de Entrega: Viernes 23 de Noviembre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/

#include<stdio.h>
#include<time.h>

// prototipos de funcion
int binarySearchInt(int array[], int key, int left, int right, int *iter);
int binarySearchFloat(float array[], float key, int left, int right, int *iter);

int interpolationSearchInt(int array[], int key, int left, int right, int *iter);
int interpolationSearchFloat(float array[], float key, int left, int right, int *iter);

void printSearchIntervalInt(int array[], int l, int r, int pos, int key);
void printSearchIntervalFloat(float array[], int l, int r, int pos, float key);

int main() {

	int arrayNumInt[20] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
	float arrayNumFloat[20] = {2.1,4.1,6.1,8.1,10.1,12.1,14.1,16.1,18.1,20.1,22.1,24.1,26.1,28.1,30.1,32.1,34.1,36.1,38.1,40.1};

	int arrayIntInterpolacion[20] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40000000};	// arreglo para probar el peor caso de la busqueda interpolada
	float arrayFloatInterpolacion[20] = {2.2,4.2,6.2,8.2,10.2,12.2,14.2,16.2,18.2,20.2,22.2,24.2,26.2,28.2,30.2,32.2,34.2,36.2,38.2,40000000.2};	// arreglo para probar el peor caso de la busqueda interpolada

	clock_t beginClock, endClock;
	double cpu_time;
	int iter = 0;

	// Analisis empirico del algoritmo Binary Search

	printf("***********************************************************************\n\n\nPor busqueda binaria: \n");

	//Utilizando numeros enteros

	beginClock = clock();
	binarySearchInt(arrayNumInt,40,0,19,&iter);				// probando con el peor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion peor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchInt(arrayNumInt,20,0,19,&iter);				// probando con el mejor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion mejor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchInt(arrayNumInt,10,0,19,&iter);				// probando cualquier otro caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion cualquier otro caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchInt(arrayNumInt,41,0,19,&iter);				// probando si el elemento no esta en el arreglo
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion en el caso de que el elemento no este en el arreglo: %f segundos\n\n", cpu_time);


	// Utilizando numeros flotantes

	iter = 0;

	beginClock = clock();
	binarySearchFloat(arrayNumFloat,40.1,0,19,&iter);				// probando con el peor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion peor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchFloat(arrayNumFloat,20.1,0,19,&iter);				// probando con el mejor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion mejor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchFloat(arrayNumFloat,10.1,0,19,&iter);				// probando cualquier otro caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion cualquier otro caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	binarySearchFloat(arrayNumFloat,41,0,19,&iter);				// probando si el elemento no esta en el arreglo
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion en el caso de que el elemento no este en el arreglo: %f segundos\n\n", cpu_time);

	/**********************************************************************************************/


	// Analisis Empirico del algoritmo interpolation search

	printf("***********************************************************************\n\n\nPor busqueda por interpolacion: \n");
	
	// Utilizando numeros enteros

	iter = 0;

	beginClock = clock();
	interpolationSearchInt(arrayIntInterpolacion,38,0,19,&iter);				// probando con el peor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion peor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchInt(arrayNumInt,20,0,19,&iter);				// probando con el mejor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion mejor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchInt(arrayNumInt,10,0,19,&iter);				// probando cualquier otro caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion cualquier otro caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchInt(arrayNumInt,41,0,19,&iter);				// probando si el elemento no esta en el arreglo
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion en el caso de que el elemento no este en el arreglo: %f segundos\n\n", cpu_time);


	// Utilizando numeros flotantes

	iter = 0;

	beginClock = clock();
	interpolationSearchFloat(arrayFloatInterpolacion,38.2,0,19,&iter);		// probando con el peor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion peor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchFloat(arrayNumFloat,20.1,0,19,&iter);				// probando con el mejor caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion mejor caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchFloat(arrayNumFloat,10.1,0,19,&iter);				// probando cualquier otro caso
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion cualquier otro caso: %f segundos\n\n", cpu_time);

	iter = 0;

	beginClock = clock();
	interpolationSearchFloat(arrayNumFloat,41,0,19,&iter);				// probando si el elemento no esta en el arreglo
	endClock = clock();
	cpu_time = (double) (endClock - beginClock) / CLOCKS_PER_SEC;
	printf("\t\tTiempo de ejecucion en el caso de que el elemento no este en el arreglo: %f segundos\n\n", cpu_time);

	return 0;
}

int binarySearchInt(int array[], int key, int left, int right, int *iter) {
	int mid = (left+right)/2;
	
	printf("Iteracion: %d\n\n",++(*iter));
	if (left<=right) {
		printSearchIntervalInt(array,left,right,mid,key);

		if (array[mid] == key) return mid;

		if(array[mid]>key) return binarySearchInt(array,key,left,mid-1,iter);
		
		return binarySearchInt(array,key,mid+1,right,iter); // if array[mid]<key
	}

	return -1;	// si no se encontro la key
}

int binarySearchFloat(float array[], float key, int left, int right, int *iter) {
	int mid = (left+right)/2;
	
	printf("Iteracion: %d\n\n",++(*iter));
	if (left<=right) {
		printSearchIntervalFloat(array,left,right,mid,key);

		if (array[mid] == key) return mid;

		if(array[mid]>key) return binarySearchFloat(array,key,left,mid-1,iter);
		
		return binarySearchFloat(array,key,mid+1,right,iter); // if array[mid]<key
	}

	return -1;	// si no se encontro la key
}

int interpolationSearchInt(int array[], int key, int left, int right, int *iter) {
	int pos = left+( ((right-left)*(key-array[left])) / (array[right]-array[left]) );

	printf("Iteracion: %d\n\n",++(*iter));
	if (left<=right) {
		printSearchIntervalInt(array,left,right,pos,key);
		if (array[pos] == key) return pos;

		if(array[pos]>key) return binarySearchInt(array,key,left,pos-1,iter);
		
		return binarySearchInt(array,key,pos+1,right,iter); // if array[mid]<key
	}

	return -1;	// si no se encontro la key
}

int interpolationSearchFloat(float array[], float key, int left, int right, int *iter) {
	int pos = left+( ((right-left)*(key-array[left])) / (array[right]-array[left]) );

	printf("Iteracion: %d\n\n",++(*iter));
	if (left<=right) {
		printSearchIntervalFloat(array,left,right,pos,key);
		if (array[pos] == key) return pos;

		if(array[pos]>key) return binarySearchFloat(array,key,left,pos-1,iter);
		
		return binarySearchFloat(array,key,pos+1,right,iter); // if array[mid]<key
	}

	return -1;	// si no se encontro la key
}

void printSearchIntervalInt(int array[], int l, int r, int pos, int key) {
	int i;

	printf("Intervalo de busqueda: %d - %d\n", l,r);
	printf("Valor llave: %d\n", key);
	printf("Medio: array[%d] = %d\n", pos, array[pos]);
	for(i=l; i<=r; i++) {
		if(i == pos) 
			printf("{ %d }\t", array[i]);
		else
			printf("%d\t", array[i]);
	}

	printf("\n\n");
}

void printSearchIntervalFloat(float array[], int l, int r, int pos, float key) {
	int i;

	printf("Intervalo de busqueda: %d - %d\n", l,r);
	printf("Valor llave: %f\n", key);
	printf("Medio: array[%d] = %f\n", pos, array[pos]);
	for(i=l; i<=r; i++) {
		if(i == pos) 
			printf("{ %f }\t", array[i]);
		else
			printf("%f\t", array[i]);
	}

	printf("\n\n");
}