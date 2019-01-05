#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*	Prototipos de Funciones"	*/
double falsaPosicion(double interA, double interB, double err_min);
double evalFunc(double num);

int main(int argc, char *argv[])
{

    double error, intervaloA, intervaloB, raiz;

    printf("Intervalo A (izquierdo): ");
    scanf("%lf", &intervaloA);
    fflush(stdin);

    printf("Intervalo B (derecho): ");
    scanf("%lf", &intervaloB);
    fflush(stdin);

    printf("Error ideal: ");
    scanf("%lf", &error);
    fflush(stdin);

    raiz = falsaPosicion(intervaloA, intervaloB, error);
    if (raiz == 1)
        printf("\nVerifique los intervalos proporcionados!");
    else
        printf("Raiz en el intervalo [%f , %f]: %f", intervaloA, intervaloB, raiz);

    return 0;
}

// InterA siempre es el menor e interB siempre es el mayor
double falsaPosicion(double interA, double interB, double err_min)
{

    int iter = 0;
    double xs, xsV, eval, ea, xs_anterior = 0;

    if ((evalFunc(interA) * evalFunc(interB)) > 0)
    {

        printf("\n\t No se encuentra ninguna raiz en el intervalo [%.2f - %.2f]\n", interA, interB);
        return 1;
    }
    else
    {
        //e^x-3x^2
        printf("#  a\t\t b\t\t Xs\t\t f(a)\t\t f(b)\t\t ea\t\t \n");

        do
        {

            // Evaluacion de la funcion con el intervalo a y el valor de la raiz aproximada xs
            xs = (interB) - ((evalFunc(interB) * (interA - interB)) / (evalFunc(interA) - evalFunc(interB)));

            // Imprimiendo los valores del intervalo en la tabla
            printf("%d  %f \t%f \t%f \t%f \t%f", ++iter, interA, interB, xs, evalFunc(interA), evalFunc(interB));
            eval = (evalFunc(interA) * evalFunc(xs));

            if (eval < 0)
                interB = xs;
            else if (eval > 0)
                interA = xs;
            ea = fabs(((xs - xs_anterior) / xs) * 100);

            printf("\t%f % \n", ea);
            xs_anterior = xs;

            // Verificando que en la proxima iteracion no se vaya a pasar del error minimo
            xsV = (interB) - ((evalFunc(interB) * (interA - interB)) / (evalFunc(interA) - evalFunc(interB)));
            if (eval < 0)
                interB = xsV;
            else if (eval > 0)
                interA = xsV;

            ea = fabs(((xsV - xs_anterior) / xsV) * 100);
            if (ea < 0)
                ea = ea * (-1);
            // Terminando verificacion

        } while (ea > err_min); //El valor de ea se toma como el de la proxima iteracion, debido a que verificamos antes que no se
                                // excediera el error minimo
    }

    return xs;
}

double evalFunc(double num)
{
    return (pow(num, 3) + 4 * pow(num, 2) - 10);
}
