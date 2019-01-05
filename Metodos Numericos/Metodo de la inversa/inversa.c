
#include <stdio.h>
#include<math.h>
#include<stdlib.h>

void capturaCoeficientes(double ** mat, double *indep, int size);

int main(int argc, int * argv[])
{
    double ** matriz;
    int i,j,k,l;
    int elem;
    double temp, buffer = 0;
    
    printf("\nTamanyo de la matriz: ");
    scanf("%d",&elem);

    float identidad[elem][elem];

    matriz = malloc(elem*sizeof(double *));
    for (i=0; i<elem; i++) {
        *(matriz+i) = malloc((elem)*sizeof(double)); 
    }
    double ind[elem];
    capturaCoeficientes(matriz,&ind[0],elem);

    //Inicializando la matriz identidad
    for (i=0; i<elem; i++) {
    	for (j=0; j<elem; j++) {
    		if (i==j) identidad[i][j] = 1;
    			else identidad[i][j] = 0;
    	}
    }
    //La matriz debe ser cuadrada
   for (i=0; i<elem; i++ ) {
   	    if (matriz[i][i]!=1) {
            temp = matriz[i][i];
            for(k=0; k<elem; k++) {
                matriz[i][k] /= temp;
                identidad[i][k] /= temp;
            }   
        }
        for (j=0; j<elem; j++) {
            if ( j == i) continue;
            
            if(matriz[j][i] < 0) {
                temp = matriz[j][i]*matriz[i][i];
                for(l=0; l<elem; l++) {
                    matriz[j][l] += -1*temp*matriz[i][l];
                    identidad[j][l] += -1*temp*identidad[i][l];
                }
            }
            else if (matriz[j][i] > 0) {
                temp = matriz[j][i]*matriz[i][i];
                for(l=0; l<elem; l++) {
                    matriz[j][l] -= temp*matriz[i][l];
                    identidad[j][l] -= temp*identidad[i][l];
                }
            }
        }
    }
    
//Impresion matriz inversa 
    printf("\nMatriz Inversa %dX%d\n",elem,elem);
    for (i=0; i<elem; i++) {
    	for (j=0; j<elem; j++) {
    		printf("%f\t", identidad[i][j]);
    	}
    	printf("| %f\t", ind[i]);
    	printf("\n");
    }

    for (int i=0; i<elem; i++) {
        for (int j=0; j<elem; j++) {
            buffer += identidad[i][j]*ind[j];
        }
        printf("\nIncognita %d: %f",i+1,buffer);
        buffer = 0;
    }

    free(matriz);

    return 0;
}

void capturaCoeficientes(double ** mat, double * indep, int size) {
    int i,j;
    for(i=0; i<size; i++) {
        printf("\nEcuacion %d) \n",i+1);
        for(j=0; j<size; j++) {
            printf("Coeficiente termino %d: ",j+1);
            scanf(" %lf", &mat[i][j]);
        }
        printf("Termino independiente: ");
        scanf(" %lf", &indep[i]); //Si tenemos un sistema de 4x4, el coeficiente del 
        //ultimo termino de cada ecuacion llegaria a un indice de size-1, por eso el ter ind es size

    }
}
