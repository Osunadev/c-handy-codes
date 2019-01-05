
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int condicionDiagonal(double ** sis, int size);
void capturaCoeficientes(double ** sis, int size);
void valoresIniciales(double *var, int size);
void printSistema(double ** sis, int size);
int solucionRaices(double ** sis, double *var, int size);
int verifAnterior (double *var, double *varAnt, int size);

int main() {

    int i,j,tam,condicion,iter = 0, count = 0;
    double eval;
    double ** sistema;//Coeficientes del sistema de ecuaciones

    printf("\nTamanyo de la matriz: ");
    scanf("%d",&tam);
    double variables[tam]; //variables a utilizar para guardar los valores de a,b,c,...
    double variablesAnter[tam];
    //Reservando espacio para nuestro sistema
    sistema = malloc(tam*sizeof(double *));
    for (i=0; i<tam; i++) {
        *(sistema+i) = malloc((tam+1)*sizeof(double)); //tam+1 debido al termino independiente
    }

    capturaCoeficientes(sistema,tam);
    valoresIniciales(&variables[0],tam);
    
    condicion = condicionDiagonal(sistema,tam);

    if (!condicion) {
        printf("No se ha cumplido la condicion. Ingrese un sistema de ecuaciones apto para este metodo.\n");
        return 1;
    }

    else if(condicion) {
        printf("\nSi se cumple con la condicion\n");
        printSistema(sistema,tam);

    do {
        for (i=0; i<tam; i++) {
            eval = sistema[i][tam]; //sistema[i][tam] porque el indice tam le corresponde al termino ind.
            for (j=0; j<tam; j++) {
                //Si los indices no le corresponden a los coeficientes de la diagonal
                if(j!=i) {
                    eval  += (-1*sistema[i][j])*variables[j]; //Multiplicando por los valores dados
                }
            }
            eval /= sistema[i][i]; //Se divide por el coeficiente de la diagonal
            variables[i] = eval; //Asignando la evaluacion a la variable que le corresponda
        }

        printf("\n%d)Iteracion \n",iter+1);
        
        for (i=0; i<tam; i++) {
            printf("%f \t", variables[i]);
            if (iter>0) variablesAnter[i] = variables[i];
        }

        if (iter>0 && verifAnterior(&variables[0],&variablesAnter[0],tam)) count++;
        
        if (count == 8) break;

        iter++;

    } while(!solucionRaices(sistema,&variables[0],tam));
    
    }

    printf("\nNumero de iteraciones: %d\n", iter);
    for (i=0; i<tam; i++) {
        printf("\nIncognita del termino %d: %f\n", i+1, variables[i] );
    }

    free(sistema);

    return 0;
}

int condicionDiagonal(double ** sis, int size) {
//Regresa 0 si la condicion no se cumple y 1 si si se cumple
    int i,j, cond=1, mayor=0, suma=0;

    for (i=0; i<size; i++) {
        mayor = abs(sis[i][i]);
        for (j=0; j<size; j++) {
            // si j no es igual al indice de la diagonal
            if (j!=i) suma += abs(sis[i][j]);
        } 

        if (suma > mayor) return 0; //La condicion es falsa
        suma = 0;
   }
    return cond;
}

void capturaCoeficientes(double ** sis, int size) {
    int i,j;
    for(i=0; i<size; i++) {
        printf("\nEcuacion %d) \n",i+1);
        for(j=0; j<size; j++) {
            printf("Coeficiente termino %d: ",j+1);
            scanf(" %lf", &sis[i][j]);
        }
        printf("Termino independiente: ");
        scanf(" %lf", &sis[i][size]); //Si tenemos un sistema de 4x4, el coeficiente del 
        //ultimo termino de cada ecuacion llegaria a un indice de size-1, por eso el ter ind es size

    }
}

void valoresIniciales(double *var, int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("\nValor inicial de la variable de la incognita del termino %d: ", i+1);
        scanf(" %lf", var+i);
    }
}

void printSistema (double ** sis, int size) {
    int i,j;
    printf("\n");
    for(i=0; i<size; i++) {
        printf("Ecuacion %d) \n",i+1);
        for(j=0; j<size; j++) {
            printf("%.4f ",sis[i][j]);
        }
        printf("= %.4f \n",sis[i][size]);
    }
}

int solucionRaices(double ** sis, double *var, int size) {
    int i,j,sol = 1;
    double suma = 0;

    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            suma += sis[i][j]*(*(var+j));
        }
        //Si la evaluacion no es igual al termino ind.
        if (suma != sis[i][size]) { return 0; }
            else suma = 0;
    }
    return sol;
}

int verifAnterior (double *var, double *varAnt, int size) {
    int i,verif = 0;

    for (i=0; i<size; i++) {
        if ( (*(var+i) - *(varAnt+i)) == 0) {verif++;}
    }

    if (verif == size) return 1; //1 si se verifica que son iguales los numeros anteriores y actuales
        else return 0;
}
