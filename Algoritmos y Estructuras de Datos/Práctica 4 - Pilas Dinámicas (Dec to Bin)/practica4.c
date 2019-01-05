/*
 Practica #4 - Estructuras LIFO
 
 - Alumno: Osuna Angulo Omar Alonso (12346437)
 
 - Competencia: Aplicar	eficientemente	el	principio	LIFO	para	generar	soluciones	creativas	a	
problemas	 de	 ingeniería,	 optimizando	 el	 uso	 de	 los	 recursos	 de	 manera	 responsable,	
preservando	la	integridad	de	los	datos.	
 
 - Descripcion de la Practica: 
    
	La	conversión	de	un	número	en	base	decimal	a	base	binaria	se	lleva	a	cabo	dividiendo	el	
	número	entre	2	n	veces	hasta	que	ya	no	se	pueda	dividir,	el	número	en	binario	está formado	
	por	 todos	 los	 residuos	 de	 las	 divisiones,	 el	 dígito	 más	 significativo	 es	 el	 último	 residuo	
	obtenido	mientras	 que	 el	 dígito	menos	 significativo	 es	 el	 residuo	 de	 la	 primera	división
	realizada. Por	ejemplo,	si	el	usuario	desea	convertir	el	número	60	a	binario,	se	realizan	las	
	operaciones siguientes,	el	primer	0	es	el	último	dígito	del	resultado mientras	que	el	residuo	
	de	la	 última	 división	es	el	 primer	 dígito	 del	 resultado,	 de	manera que	el	equivalente	en	
	binario	de	60	es	111100.

			0 | 60
				0 | 30
					1 | 15
						1 | 7
							1 | 3
								1

Se	pide	que	implemente	un	programa	basado	en	el	principio	LIFO	que	lea	un	número	entero	
en	base	10	y	lo	convierta	a	una	cadena	que	contenga	su	equivalente	binario.

 - Requisitos:
 
	* No	debe	utilizar	funciones	para	invertir	cadenas.
	* Debe aplicar	el	principio	LIFO.
	* Puede	utilizar	memoria	dinámica	o	estática.
	* Debe	considerar	todo	el	rango	de	los	números	enteros.
	* El	lenguaje	puede	ser	C	o	Java.
	* Debe	implementar	las	funciones pop	y	push.
	* No	se	pide	que	muestre	las	divisiones	de	la	figura.
	* El	resultado	debe	quedar	en	una	variable,	no	solo	en	pantalla.	
 
 - Fecha de Entrega: Viernes 05 de Octubre 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/


#include<stdio.h>
#include<stdlib.h>

struct nodo {
	char digito_bin; //Se usa char porque no se ocupa mucho espacio de almacenamiento
	struct nodo *ant;
};

// Prototipos de funciones
void push(struct nodo **tope, char valor);
char pop(struct nodo **tope);
void menuOpc(char nombre_bienvenida[], char op1[]);

int main() {
	struct nodo *tope = NULL; //Nodo inicial nulo
	unsigned long long decimal; //Variable para el numero decimal. long long es de 8 bytes
	int sizeBinActual = 1, i = 0;
	char op; //variable para leer un caracter del menu

	do {
		menuOpc("conversor de decimal a binario", "Convertir numero decimal a binario");
		op = getchar();

		if(op == '1') {

			printf("\nIntroduzca numero decimal para ser convertido en binario: ");
			scanf("%llu", &decimal); //Leyendo el numero decimal de entrada
			printf("\n\t El numero %lld",decimal);

			do {
				push(&tope,(decimal%2)+'0'); // Se hace push del residuo. Se le suma '0' para que se represente como char
				decimal = decimal/2; //Haciendo la division
				sizeBinActual++;

			} while(decimal!=0);

			char bin[sizeBinActual+1];

			while (tope != NULL) {
				bin[i++] = pop(&tope);
			}

			bin[i] = '\0';

			printf(" en binario es: %s\n",bin);
			fflush(stdin); //Limpiando el buffer de entrada
			sizeBinActual = 1, i = 0; //Reiniciando valores
		}

	} while (op != '2'); // op == '2' es cuando se quiera salir del programa

	free(tope);

	return 0;
}

void push(struct nodo **cima, char valor) {
	struct nodo *aux = (struct nodo*) malloc(sizeof(struct nodo)); // Reservando memoria para un nuevo nodo;
	aux->digito_bin = valor;
	if (*cima == NULL) aux->ant = NULL; // En el caso de que sea el primer nodo creado
	else { aux->ant = *cima; }
	*cima = aux;

}

char pop(struct nodo** cima) {
	struct nodo *aux = *cima;
	char ch = (*cima)->digito_bin; // variable aux para guardar el caracter de cima
	*cima = (*cima)->ant;

	free(aux); // liberando el espacio de cima que fue guardado en una variable aux

	return ch;
}

void menuOpc(char nombre_bienvenida[], char op1[]) {
	printf("\nBienvenido a %s\n", nombre_bienvenida);
    printf("1) %s\n", op1);
    printf("2) Salir del programa\n");
    printf("\nSeleccione la opcion: ");
}