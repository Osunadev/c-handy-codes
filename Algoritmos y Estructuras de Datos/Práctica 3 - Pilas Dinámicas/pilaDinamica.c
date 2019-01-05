/*
 Practica #3 - No.3 Estructuras LIFO Dinámicas
 
 - Alumno: Osuna Angulo Omar Alonso (12346437)
 
 - Competencia: Aplicar	eficientemente el principio LIFO para generar soluciones creativas a problemas de	
 				ingeniería, optimizando	el uso	de los recursos de manera responsable, preservando la	integridad de los datos.	
 
 - Descripcion de la Practica: 
    
	Un	método	simple	para	encriptar	mensajes,	aunque	no	muy	eficiente,	consiste	en	colocar	paréntesis	de	manera	arbitraria	
	dentro	de	la	frase	original,	y	todo	lo	que	esté	dentro	de	un	par	de	paréntesis,	escribirlo	al	revés,	por	ejemplo, 
	la	frase	“Ingeniería	en	Computación”	se	puede	encriptar	como	“Ingenier(ai)	en	C(upmo)tación”.	
		
	Diseñe	e	implemente	un	algoritmo	basado	en	el	principio	LIFO,	que	lea	de	teclado	una	frase	ya	encriptada	y	obtenga	
	el	mensaje	desencriptado.	Si	el	usuario	introduce	la	frase	“Algorit(som)	y	Estruc(sarut)	de	Datos”	el	programa	debe 
	mostrar	las	operaciones	(push pop)	que	está realizando:

	-----------------------------------------------------------------------------------------------------------------------------------------
	Algorit																
	(	
	***push	s	
	***push	o	
	***push	m	
	)	
	pop()	
	Algoritm
	pop()	
	Algoritmo	
	pop()	
	Algoritmos		
	Algoritmos	y	Estruc
	(	
	***push	s	
	***push	a	
	***push	r	
	***push	u	
	***push	t	
	)	
	Pop()	
	Algoritmos	y	Estruct
	Pop()	
	Algoritmos	y	Estructu
	Pop()	
	Algoritmos	y	Estructur
	Pop()	
	Algoritmos	y	Estructura
	Pop()	
	Algoritmos	y	Estructuras
	Algoritmos	y	Estructuras	de	Dato
	-----------------------------------------------------------------------------------------------------------------------------------------
	la	frase	desencriptada	es:	“Algoritmos	y	Estructuras	de	Datos”.

 - Requisitos:
 
	• El programa debe	mostrar	el estadode	la pila	durante	el proceso	de evaluación del mensajes	
	• EL mensaje que introduzca	el usuario	debe estar YA encriptado. No se	pide que elabore la	función	de encriptación.	
	• La frase	debe ser evaluada una vez que haya sido capturada.	
	• El tamaño del	mensaje	debe ser ilimitado.	
	• El lenguaje de programación a utilizar es	C.	
	• Evite	utilizar variables globales.	
	• El programa debe organizado en	funciones.	
	• Debe respetar el	principio LIFO.	
	• Push y pop solo hacen	las	operaciones	de	meter y sacar datos	de	la pila.	
 
 - Fecha de Entrega: Viernes 28 de Septiembre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nodo {
	char ch;
	struct nodo *ant;
};

// Prototipos de funciones
char *cadenaEntrada(FILE *, unsigned int );
void push(struct nodo **tope, char valor);
char pop(struct nodo **tope);
int numParentesis(char *mensaje, int longitud);
void desencriptarMsg(char *msg, int msg_len, char *msg_desencriptado, struct nodo **cima);
void printAvanceDesencriptado(char *cadena, int limite);
void vaciarPila(char *cadena_destino, int *index_actual, struct nodo **cima);


int main () {

	struct nodo *tope = NULL; //Nodo inicial nulo
	char *msg, *msg_desencriptado; //Apuntadores para los mensajes
	int msg_len, msg_len_desencriptado; // Se guarda la longitud del mensaje

	printf("\nIntroduzca mensaje encriptado: ");
	msg = cadenaEntrada(stdin,20); // Leemos la cadena de entrada. El 20 es por el tamanyo inicial esperado
	
	if (msg == NULL) printf("No se introdujo ningun mensaje. Al menos introduzca 1 caracter.\n");
	else {
		msg_len = strlen(msg); // Longitud del mensaje leido

		msg_len_desencriptado = msg_len-numParentesis(msg, msg_len); // Longitud a ocupar el mensaje desencriptado

		printf("Mensaje Encriptado: %s\n\n", msg);
		printf("\nLongitud del mensaje original: %d\n", msg_len);
		printf("Longitud del mensaje desencriptado: %d\n\n", msg_len_desencriptado);

		// Reservando espacio para almacenar justamente la cadena desencriptada, quitando los parentesis
		msg_desencriptado = (char *) malloc((sizeof(char)*msg_len_desencriptado)+1); // +1 por el fin de cadena
		
		printf("\nProceso de desencriptado: \n");

		desencriptarMsg(msg,msg_len,msg_desencriptado,&tope);
		
		printf("%s\n",msg_desencriptado );
		
		free(tope); // Liberando la memoria reservada
		free(msg_desencriptado);
		free(msg);
	}

	return 0;
}

void desencriptarMsg(char *msg, int msg_len, char *msg_desencriptado, struct nodo **cima) {
	int index_msg=0, cont=1, index_desencript=0;

	do {
		if (msg[index_msg] != '(') {
			msg_desencriptado[index_desencript++] = msg[index_msg++];

			if (msg[index_msg] == '(' || index_desencript==strlen(msg_desencriptado-1))
				//Si el siguiente caracter es un parentesis o si se llega al final de la cadena desencriptada
				printAvanceDesencriptado(msg_desencriptado, index_desencript-1); 
		}
		else {
			printf("(\n");

			while(msg[index_msg+cont] != ')') {
				printf("***push %c\n", msg[index_msg+cont]);
				push(cima,msg[index_msg+(cont++)]);
			}

			printf(")\n");
			if (cont>1) vaciarPila(msg_desencriptado,&index_desencript,cima); //index_msg es en que posicion se continuara
			// Vaciamos la pila al mensaje desencriptado
			index_msg += cont+1; //Se da un nuevo valor a index_msg para que se recorra despues de los parentesis
			cont = 1; //Reiniciando el cont
		}

	} while(index_msg!=msg_len);
	
	msg_desencriptado[index_desencript] = '\0'; //Agregando el fin de cadena
}

void printAvanceDesencriptado(char *cadena, int limite) {
	int i;
	for (i=0; i<=limite; i++) {
		printf("%c", cadena[i]);
	}
	printf("\n");
}

void vaciarPila(char *cadena_destino, int *index_actual, struct nodo **cima) {
	while(*cima != NULL) {
		printf("pop()\n");
		cadena_destino[*index_actual] = pop(cima);
		printAvanceDesencriptado(cadena_destino,*index_actual);
		(*index_actual)++; //Se incrementa en una unidad el indice actual
		
	}
}

int numParentesis(char *mensaje, int longitud) {
	int i, cont = 0;
	for (i=0; i<longitud; i++) {
		if (mensaje[i] == '(' || mensaje[i] == ')') {
			cont++;
		}
	}

	return cont;
}

void push(struct nodo **cima, char valor) {
	struct nodo *aux = (struct nodo*) malloc(sizeof(struct nodo)); // Reservando memoria para un nuevo nodo;
	aux->ch = valor;
	if (*cima == NULL) aux->ant = NULL; // En el caso de que sea el primer nodo creado
	else { aux->ant = *cima; }
	*cima = aux;

}

char pop(struct nodo** cima) {
	struct nodo *aux = *cima;
	char ch = (*cima)->ch; // variable aux para guardar el caracter del cima
	*cima = (*cima)->ant;

	free(aux); // liberando el espacio de cima que fue guardado en una variable aux

	return ch;
}

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