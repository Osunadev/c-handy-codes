#include <stdio.h>

void insertionSortLeft(int *array, int size);
void insertionSortRight(int *array, int size);

int main()
{
    int pruebaIzq[] = {12,14,4,73,11,75,24};
    int pruebaDer[] = {12,14,4,73,11,75,24};
    
    int size = sizeof(pruebaIzq)/sizeof(int);
    
    insertionSortLeft(pruebaIzq,size);
    insertionSortRight(pruebaDer,size);
    
    int i;
    
    printf("Prueba con la izq\n");
    for (i=0; i<size; i++) {
        printf("%d\t",pruebaIzq[i]);
    }
    
    printf("\nPrueba con la der\n");
    for (i=0; i<size; i++) {
        printf("%d\t",pruebaDer[i]);
    }
    return 0;
}

// Insercion directa por la izquierda

void insertionSortLeft(int *array, int size) {
	int i,j,key;

	for(i=1; i<size; i++){
		key = array[i];
		j = i-1;
		
		while(j>=0 && array[j]>key) {
			array[j+1] = array[j];
			j = j-1;
        }
		array[j+1] = key;
    }
}

// Insercion directa por la derecha

void insertionSortRight(int *array, int size) {
	int i,j,key;

	for(i=size-1; i>=0; i--){
		key = array[i];
		j = i+1;
		
		while(j<=size && array[j]>key) {
			array[j-1] = array[j];
			j = j+1;
        }
		array[j-1] = key;
    }

}