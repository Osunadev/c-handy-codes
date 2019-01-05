/* Sistema de ecuaciones 4x4 */
    // w - 2x + 2y - 3z = 15
    // 3w + 4x - y + z = -6
    // 2w - 3x + 2y - z = 17
    // w + x - 3y - 2z = -7
    // w=2, x=-2, y=3, z=-1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>

void capturaCoeficientes(double ** mat, double *indep, int size);

int main(int argc, int * argv[])
{   
    double **matriz;
    int i,j,k,l;
    int elem;
    double temp;

    printf("\nTamanyo de la matriz: ");
    scanf("%d",&elem);

    matriz = malloc(elem*sizeof(double *));
    for (i=0; i<elem; i++) {
        *(matriz+i) = malloc((elem)*sizeof(double)); 
    }
    double aumentada[elem];
    capturaCoeficientes(matriz,&aumentada[0],elem);

    //La matriz debe ser cuadrada
   for (i=0; i<elem; i++ ) {
   	    if (matriz[i][i]!=1) {
            temp = matriz[i][i];
            for(k=0; k<elem; k++) matriz[i][k] /= temp;
            aumentada[i] /= temp;
        }
        for (j=0; j<elem; j++) {
            if ( j == i) continue;
            //valor temporal del elemento que no es 0
                temp = matriz[j][i]*matriz[i][i];
            if(matriz[j][i] < 0) {
                // el elemento matriz[i][i] siempre sera 1
                for(l=0; l<elem; l++) {
                    matriz[j][l] += -1*temp*matriz[i][l];
                }
                    aumentada[j]+= -1*temp*aumentada[i];
            }
            else if (matriz[j][i] > 0) {
                for(l=0; l<elem; l++) {
                    matriz[j][l] -= temp*matriz[i][l];
                }
                    aumentada[j] -= temp*aumentada[i];
            }
        }
    } 
    // Imprimiendo matriz
    for (i=0; i<elem; i++) {
        for (j=0; j<elem; j++) {
            printf("%.0f\t", matriz[i][j]);
        }
        printf(" | %f\n",aumentada[i]);
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


