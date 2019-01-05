/*
 Practica #7 - Estructuras FIFO Dinamicas

 - Alumno: Osuna Angulo Omar Alonso (12346437)

 - Competencia:  Generar aplicaciones de software en las que se aplique adecuadamente el principio FIFO y el concepto de
memoria dinámica para solucionar problemas de manejo de información, de manera responsable y eficiente.

 - Descripcion de la Practica:

	Una compañía dedicada a la venta de celulares desea agradecer su preferencia a sus clientes haciéndoles regalos que van desde
	recargas desde 50 pesos hasta el celular que el cliente escoja del inventario. Los clientes se han registrado a través de una página
	y se ha generado una lista a partir del registro. La compañía le ha pedido que diseñe e implemente una aplicación basada en el
	principio FIFO para seleccionar al cliente ganador. El algoritmo que debe implementar es el siguiente:
	Utilizando un número K aleatorio, se recorre K clientes, el K-ésimo cliente será eliminado de la cola con un premio de consolación
	de $50 TA. Este proceso se repite las veces que sea necesario, en cada vuelta completa el premio de consolación se incrementa
	en $50, hasta que queda solo el cliente ganador.

	Por ejemplo, si los clientes son y K es 2.
	Julio Justin Link Bryan Arjona Pica Chabelo Alondra Nereo Kelly Lorena

	Si K=2, el primer cliente eliminado es Justin y la cola quedaría:
	Julio Link Bryan Arjona Pica Chabelo Alondra Nereo Kelly Lorena

	A partir de Link se cuentan K clientes y el siguiente seleccionado es Bryan
	Julio Link Bryan Arjona Pica Chabelo Alondra Nereo Kelly Lorena

	Eliminando a Bryan la lista queda así:
	Julio Link Arjona Pica Chabelo Alondra Nereo Kelly Lorena

	A partir de Arjona se cuentan K clientes y el siguiente seleccionado es Pica
	Julio Link Arjona Pica Chabelo Alondra Nereo Kelly Lorena

	Eliminando a Pica la lista queda así:
	Julio Link Arjona Chabelo Alondra Nereo Kelly Lorena

	A partir de Chabelo se cuentan K clientes y el siguiente seleccionado es Alondra
	Julio Link Arjona Chabelo Alondra Nereo Kelly Lorena

	Eliminando a Alondra la lista queda así:
	Julio Link Arjona Chabelo Nereo Kelly Lorena

	A partir de Nereo se cuentan K clientes y el siguiente seleccionado es Kelly
	Julio Link Arjona Chabelo Nereo Kelly Lorena

	Eliminando a Kelly la lista queda así:
	Julio Link Arjona Chabelo Nereo Lorena

	A partir de Lorena se cuentan K clientes y el siguiente seleccionado es Julio
	Julio Link Arjona Chabelo Nereo Lorena

	Eliminando a Julio la lista queda así:
	Link Arjona Chabelo Nereo Lorena

	A partir de Link se cuentan K clientes y el siguiente seleccionado es Arjona
	Link Arjona Chabelo Nereo Lorena

	Eliminando a Arjona la lista queda así:
	Link Chabelo Nereo Lorena

	A partir de Chabelo se cuentan K clientes y el siguiente seleccionado es Nereo
	Link Chabelo Nereo Lorena

	Eliminando a Nereo la lista queda así:
	Link Chabelo Lorena

	A partir de Lorena se cuentan K clientes y el siguiente seleccionado es Link
	Link Chabelo Lorena

	Eliminando a Link la lista queda así:
	Chabelo Lorena

	A partir de Chabelo se cuentan K clientes y el siguiente seleccionado es Lorena
	Chabelo Lorena

	Eliminando a Lorena la lista queda así:
	Chabelo

							El ganador es Chabelo!
					Se pide que su programa tenga las siguientes opciones:
					1) Agregar cliente a la lista.
					2) Hacer sorteo

    Requisitos:

    * La opción hacer sorteo debe mostrar el orden de eliminación.
	* Puede utilizar y modificar todas las funciones vistas en clase.
	* Si se terminan los clientes antes de completar K, debe continuar el conteo con el primer cliente.
	* No se pide que utilice listas dobles ni circulares.
	* La opción hacer sorteo debe mostrar el nombre de los cliente eliminados
	* Los clientes serán ingresados por el usuario.
	* El valor de K es un número aleatorio entre 1 y 5
	* El valor de K puede variar en cada sorteo.
	* Una vez que inicia el sorteo no puede agregar clientes.
	* La cantidad de clientes es ilimitada
	* Lenguaje C o Java.
	* Debe utilizar una cola dinámica

 - Fecha de Entrega: Viernes 26 de Octubre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define clearScr() system("cls")

struct nodo {
    char cliente[50];
    struct nodo *sig;
};

// Prototipos de funcioens
void menuOpc(char nombre_bienvenida[], char op1[], char op2[]);
void agregarNodo(struct nodo **frente, struct nodo **fin, char dato[50]);
void removerNodo(struct nodo **frente);
void iniciarSorteo(struct nodo **frente, struct nodo **fin);
int generarNumAleatorio(int min, int max);
void anexarNodoFin(struct nodo **fin, struct nodo **frente);
void display(struct nodo *frente);

int main() {

	struct nodo *frente = NULL, *fin = NULL;
	char opc, nombreAux[50];

		clearScr();
	do {
		menuOpc("Sorteo de tiempo aire", "Agregar cliente a la lista", "Hacer sorteo");
		scanf("%c",&opc);
		switch(opc) {
			case '1':
					clearScr();	
					fflush(stdin);
					printf("Nombre del cliente: ");
					gets(nombreAux);
					agregarNodo(&frente,&fin,nombreAux);
				break;
			case '2':
					if(frente != NULL)
						iniciarSorteo(&frente,&fin);
					else
						printf("La lista de clientes esta vacia!\n");
					getchar();
				break;
		}
	} while (opc != '3');

	return 0;
}

void agregarNodo(struct nodo **frente, struct nodo **fin, char dato[50]) {
	struct nodo *temp = malloc(sizeof(struct nodo));

	memset(temp->cliente,'\0',sizeof(temp->cliente)); //asegurando el fin de cadena
	strcpy(temp->cliente, dato);
	temp->sig = NULL;		

	if (*frente == NULL) {	// si es el primer nodo a crear
		*frente = temp;
		*fin = temp;	
	} else {
		(*fin)->sig = temp;
		*fin = temp; // se reasigna al nuevo valor del nuevo nodo
	}
}

void anexarNodoFin(struct nodo **fin, struct nodo **frente) {
	struct nodo *aux = *frente; // para que no se pierda nuestro frente

	*frente = (*frente)->sig; // avanzando al siguiente nodo

	aux->sig = NULL;
	(*fin)->sig = aux;	// anexando el nodo frente a nuestro fin
	*fin = aux;
}

void removerNodo(struct nodo **frente) {
	struct nodo *temp;
	temp = *frente;
	*frente = (*frente)->sig;

	free(temp);	//liberando el nodo a remover de la cola
}

int generarNumAleatorio(int min, int max) {
	return (rand() % (max - min +1)) + min;
}

void display(struct nodo *frente) {
    struct nodo *temp;
    temp = frente;
    while (temp != NULL) {
        printf("%s   ", temp->cliente);
        temp = temp->sig;
    }
}

void menuOpc(char nombre_bienvenida[], char op1[], char op2[]) {
	printf("\nBienvenido a %s\n", nombre_bienvenida);
    printf("1) %s\n", op1);
    printf("2) %s\n", op2);
    printf("3) Salir");
    printf("\nSeleccione la opcion: ");
}

void iniciarSorteo(struct nodo **frente, struct nodo **fin) {
	int random, i,cont = 1;
	clearScr();
	printf("\n\tClientes iniciales del sorteo: ");
	display(*frente);
	printf("\n");
	random = generarNumAleatorio(1,5);

	do {
		printf("Ronda %d)\n",cont++);
		for (i=0; i<random; i++) {
			if (*frente != *fin) {
				if(i == random-1) {
					printf("\t\t* Cliente removido: %s\n", (*frente)->cliente);
					removerNodo(frente);
				}
				else
					anexarNodoFin(fin,frente);

				display(*frente);
				printf("\n");
				if(*frente == *fin) // si en este punto se llega a tener solo 1 nodo - el ganador
					printf("\n\t\t\tEl ganador es: %s\n\n", (*frente)->cliente);
			}
		} 
		printf("\n");
	} while (*frente != *fin);
	removerNodo(frente);	// Remover el nodo del cliente ganador
}