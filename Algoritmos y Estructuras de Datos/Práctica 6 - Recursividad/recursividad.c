/*
 Practica #6 - Recursividad

 - Alumno: Osuna Angulo Omar Alonso (12346437)

 - Competencia:  Diseñar soluciones creativas donde se aplique apropiadamente el concepto de
	recursividad a problemas reales.

 - Descripcion de la Practica:

	Una hembra canina no esterilizada tendrá en su primer año fértil dos celos y como producto al menos 16
	cachorros. Supongamos que de los 16, la mitad, o sea 8,serán hembraslas cuales no estarán esterilizadas.
	Transcurrido un año, la hembra original tendrá otros 16 cachorros y sus 8 primeras descendientes
	repetirán el patrón y tendrán cada una otros 16 cachorros, haciendo un total de (8 x 16 =128) + 16=144.
	al cabo de 5 años los descendientes de los descendientes habrán procreado 74899 caninos. Esta
	progresión se verifica en la siguiente relación:

	1 año: 16
	2 año: 16 +128 =144
	3 año: 16+128+ 1024 = 1168
	4 año: 16+128+1024+8192=9360
	5 año: 16+128+1024+8192+65536=74896
				Tabla 1.

    Requisitos:

   Diseñe e implemente un programa basado en funciones recursivas que calculen la cantidad de perros que nacerán
	en un período determinado. El usuario debe proporcionar el tamaño de la camada y la cantidad de años que se
	desea calcular. En la tabla 1, la cantidad de cachorros es 16 y la proyección se realizó a 5 años.

	* No se aceptarán prácticas sin recursividad.
 	* Lenguaje C/Java
 	* El usuario debe proporcionar el tamaño de la camada.

 - Fecha de Entrega: Viernes 19 de Octubre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/

#include<stdio.h>

int nacimientoCachorros(int hembrasEnCelo, int aumentoCanino, int tamCamada, int anyoProyeccion);
void printCachorros(int numCachorros);

int main() {
	int tamCamada;	//Numero de cachorros que nacen por 1 hembra
	int anyoSeguimiento;

	printf("Introduzca tamanyo de la camada: ");
	scanf("%d",&tamCamada);
	printf("Numero de anyos a calcular: ");
	scanf("%d",&anyoSeguimiento);

	int nacimientos = nacimientoCachorros(1,0,tamCamada,anyoSeguimiento);	// se inicia con una sola hembra y con 0 cachorros nacidos
	printf("\nNacimientos para el anyo 5: %d", nacimientos);

	return 0;
}

int nacimientoCachorros(int hembrasEnCelo, int aumentoCanino, int tamCamada, int anyoProyeccion) {
	int cachorrosNacidos = hembrasEnCelo*tamCamada;	// cachorros nacidos en el anyo determinado
	aumentoCanino += cachorrosNacidos;

	if (!anyoProyeccion) //Si el año de proyeccion llega a 0
		return 0;

	printCachorros(aumentoCanino);
	return cachorrosNacidos + nacimientoCachorros(cachorrosNacidos/2,aumentoCanino,tamCamada,--anyoProyeccion);
}

void printCachorros(int numCachorros) {
	static int i = 0;	// static para que se utilice una sola declaracion de i en todas las llamadas de printCachorros
	printf("Anyo %d) %d\n",++i,numCachorros);
}