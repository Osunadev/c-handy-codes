/*
 Practica #5 - Estructuras FIFO Estaticas

 - Alumno: Osuna Angulo Omar Alonso (12346437)

 - Competencia:  Implementar soluciones de software utilizando eficientemente el
 	principio FIFO en las estructuras estáticas

 - Descripcion de la Practica:

	Un dispositivo reproductor de canciones tiene capacidad para una cantidad limitada de
	canciones, se le pide implementar un programa basado en el principio FIFO para administrar
	las canciones de la lista. Se desea que la aplicación cuente con las siguientes opciones:

		1) Agregar una canción a la lista
		2) Remover  canción
		3) Reproducir lista completa.
		4) Salida

	Por cada canción se registra la siguiente información:  
		* Intérprete   
		* Título  
		* Duración.

    Requisitos:

   * Por cada opción debe haber al menos una función.
  	* La cantidad de canciones está limitada por el programador
  	* Las canciones se agregan solo al final de la lista.
  	* Las canciones se pueden remover solo del inicio de la lista.
  	* La reproducción de una lista debe simular que la canción se está ejecutando.
  	* La reproducción de la canción se puede simular presentando el título en pantalla
  	  y el tiempo transcurrido.
  	* Durante la simulación debe mostrarse el tiempo que dura y el tiempo que ha transcurrido.
  	* Durante la simulación no debe estar activa ninguna otra operación.
  	* El programa puede ser en cualquier lenguaje C o Java.
  	* Envíe mensajes adecuados cuando se requiera, por ejemplo:” No hay canciones”, “NO hay
  	  espacio en la lista”

 - Fecha de Entrega: Viernes 12 de Octubre de 2018.
 - Materia: Algoritmos y Estructuras de Datos.
*/

#include <stdio.h>
#include <time.h>

#define MAX_SONGS 30
#define clearScr() system("cls")

struct cancion {
    char interprete[30];
    char titulo [30];
    int duracion; // en s
};

struct cola {
    int final;
    struct cancion listaCanciones[MAX_SONGS];
};

// Prototipos de funciones
void menuOpc(char op1[], char op2[], char op3[]);
void agregarCancion(struct cola *reproductor);
void removerCancion(struct cola *reproductor);
void reproducirListaCompleta(struct cola *reproductor);
void capturaInfoCancion(struct cola *reproductor);
int llena(struct cola temp);
int vacia(struct cola temp);
struct cancion removerElemento(struct cola *reproductor);
void playSong(struct cancion, int numCancion);
void delay(int ms);

int main()
{
    struct cola reproductor;
    reproductor.final = 0; // Inicializando mi final en 0
    char op;
    printf("\t\t\nBienvenido al reproductor de canciones\n");

    do {
        menuOpc("Agregar cancion a la lista","Remover Cancion", "Reproducir lista completa");
        scanf(" %c", &op);

        switch (op) {
            case '1': agregarCancion(&reproductor);
                break;
            case '2': removerCancion(&reproductor);
                break;
            case '3':reproducirListaCompleta(&reproductor);
                break;
        }
        fflush(stdin); // Limpiando el buffer de entrada
        if (op != '4') {
            printf("\nPresione ENTER para continuar...\n");
            getchar();
        }
        clearScr();
    } while(op!='4');
    return 0;
}

void agregarCancion(struct cola *reproductor) {
    if(!llena(*reproductor)) {
        capturaInfoCancion(reproductor);
        reproductor->final++;
    }
    else
        printf("Al reproductor no le caben mas canciones. Su limite es de %d canciones.\n", MAX_SONGS);
}

void removerCancion(struct cola *reproductor) {
    if(!vacia(*reproductor)) {
    	struct cancion song = removerElemento(reproductor);
        reproductor->final--;
        printf("\nLa cancion: %s interpretada por %s ha sido eliminada\n",
        	song.titulo, song.interprete);
    }
    else
        printf("\n\t\tEl reproductor esta vacio, no hay canciones a remover.\n\n");
}

void reproducirListaCompleta(struct cola *reproductor) {
    if (vacia(*reproductor)) printf("\n\t\tEl reproductor no tiene canciones, esta vacio.\n\n");
    else {
	    int i;
	    clearScr();
	    for(i=0; i<reproductor->final; i++) {
	      playSong(reproductor->listaCanciones[i],i+1);
	    }
	    printf("\n\t\t Todas las canciones han sido reproducidas.\n");
    }
}

void capturaInfoCancion(struct cola *reproductor) {
    printf("\nEsta a punto de registrar una cancion, llene los siguientes campos:\n");
    getchar();

    printf("\n\t\ta) Nombre del interprete: ");
    gets(reproductor->listaCanciones[reproductor->final].interprete);
    printf("\n\t\tb) Titulo de la cancion: ");
    gets(reproductor->listaCanciones[reproductor->final].titulo);
    printf("\n\t\tc) Duracion de la cancion (en segundos): ");
    scanf("%d", &(reproductor->listaCanciones[reproductor->final].duracion));
}

struct cancion removerElemento(struct cola *reproductor) {
    struct cancion temp = reproductor->listaCanciones[0];
    int i;

    for (i=0; i<reproductor->final; i++) {
        reproductor->listaCanciones[i] = reproductor->listaCanciones[i+1];
    }
    return temp;
}

int llena(struct cola temp) {
    return ((temp.final == MAX_SONGS) ? 1 : 0);
}

int vacia(struct cola temp) {
    return ((temp.final == 0) ? 1 : 0);
}

void menuOpc(char op1[], char op2[], char op3[]) {
    printf("\n1) %s\n", op1);
    printf("2) %s\n", op2);
    printf("3) %s\n", op3);
    printf("4) Salir del programa\n");
    printf("\nSeleccione la opcion: ");
}

void playSong(struct cancion song, int numCancion) {
    int i;
	for (i=0; i<= song.duracion; i++) {
		printf("\nCancion %d: %s\n",numCancion,song.titulo);
	    printf("\t Interprete: %s\n",song.interprete);
		printf("\t Reproduccion: %ds : %ds\n",i,song.duracion);
        delay(1000); //Delay de 1000ms
		clearScr(); //Limpiando la pantalla
	}
}

void delay(int ms) {
    // Iniciando el reloj
    clock_t start_time = clock();
    while(clock() < start_time + ms) {}
}
