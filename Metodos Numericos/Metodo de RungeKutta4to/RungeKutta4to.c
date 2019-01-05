#include <stdio.h>

double evalEcDiferencial (double , double);

int main() {
    double x, y, interA, interB, tamPaso, iter;
    double k1=0, k2=0, k3=0, k4=0;
    int i = 0;


    printf("\nIntroduzca la y inicial: ");
    scanf(" %lf", &y);
    printf("\nIntroduzca el valor del intervalo izquierdo (a): ");
    scanf(" %lf", &interA);
    printf("\nIntroduzca el valor del intervalo derecho (b): ");
    scanf(" %lf", &interB);
    printf("\nIngrese el tamanyo de paso (h): ");
    scanf(" %lf", &tamPaso);

    iter = ((interB - interA)/tamPaso)+1;
    x = interA;
    printf("X \t\tY \t\tK1 \t\tK2 \t\tK3 \t\tK4\n");

    do {
        if (i == 0) printf("%d) %f\t%f\t%f\t%f\t%f\t%f\n", i+1, x, y, k1, k2, k3, k4);

        k1 = tamPaso*evalEcDiferencial(x,y);
        k2 = tamPaso*evalEcDiferencial(x+tamPaso/2,y+k1/2);
        k3 = tamPaso*evalEcDiferencial(x+tamPaso/2,y+k2/2);
        k4 = tamPaso*evalEcDiferencial(x+tamPaso, y+k3);

        y = y + (k1+2*k2+2*k3+k4)/6;
        i++;

        printf("%d) %f\t%f\t%f\t%f\t%f\t%f\n", i+1, x, y, k1, k2, k3, k4);

        x += tamPaso;

    } while (i!= iter);

    return 0;
}

double evalEcDiferencial (double x, double y) {
    return 2*x*y;
}
