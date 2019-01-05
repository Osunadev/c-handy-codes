#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	double a;  //x^3
	double b;  //x^2
	double c;  //x
    double d; //Termino ind.
} Cubica;

typedef struct {
	double a;
	double b;
	double c;
} Cuadratica;

double Biseccion (double interA, double interB, Cubica funct, double err_min);
double evalCuadratica(Cuadratica funct, double num);
double evalCubica(Cubica funct, double num);

int main(int argc, char * argv[]) {

    Cubica funct;
    double error, intervaloA, intervaloB, raiz;

    if (argc < 5) {

        printf("Introduzca los coeficientes de su ecuacion cuadratica para poder empezar. \n");
        printf("\nEjemplo (Para la ecuacion 2x^2 - 4.33x + 12):\tbiseccion.exe 2 -4.33 12");

        return 1;

    } else {

        funct.a = atof(argv[1]);
        funct.b = atof(argv[2]);
        funct.c = atof(argv[3]);
        funct.d = atof(argv[4]);

        printf("Intervalo A (izquierdo): ");
        scanf("%lf", &intervaloA);
        fflush(stdin);

        printf("Intervalo B (derecho): ");
        scanf("%lf", &intervaloB);
        fflush(stdin);

        printf("Error ideal: ");
        scanf("%lf", &error);
        fflush(stdin);

        raiz =  Biseccion(intervaloA, intervaloB, funct, error);
        if (raiz == 1) printf("\nVerifique los intervalos proporcionados!");
            else printf("Raiz en el intervalo [%f , %f]: %f", intervaloA, intervaloB, raiz);

        return 0;
    }
}

double Biseccion (double interA, double interB, Cubica funct, double err_min) {

	int iter = 0;
	double xs, eval, ea, xs_anterior = 0, xsV;

	if ( (evalCubica(funct, interA)*evalCubica(funct, interB)) > 0) {
		printf("\n\t No se encuentra una sola raiz en el intervalo [%.2f - %.2f]\n", interA, interB);
		return 1;
	} else {
	    printf(" a\t\t b\t\t Xs\t\t f(a)\t\t ea\t\t \n");
	 do {
		// Evaluacion de la funcion con el intervalo a y el valor de la raiz aproximada xs
		xs = (interA+interB)/2;
		// Imprimiendo los valores del intervalo en la tabla
        printf(" %f \t%f \t%f \t%f", interA, interB, xs, evalCubica(funct, interA) );
		eval = ( evalCubica(funct, interA) * evalCubica(funct, xs) );

		if ( eval < 0) interB = xs;
            else if( eval > 0) interA = xs;
		iter++;
		ea = ((xs - xs_anterior)/xs)*100;
		if (ea < 0) ea = ea*(-1);

        printf("\t%f % \n", ea);
		xs_anterior = xs;

        // Verificando que en la proxima iteracion no se vaya a pasar del error minimo
        xsV = (interA+interB)/2;
        eval = ( evalCubica(funct, interA) * evalCubica(funct, xsV) );
        ea = ((xsV - xs_anterior)/xsV)*100;
            if (ea < 0) ea = ea*(-1);
        // Terminando verificacion
	 } while(ea >= err_min);  //El valor de ea se toma como el de la proxima iteracion, debido a que verificamos antes que no se
	 // excediera el error minimo

     printf("\n\t Numero de iteraciones realizadas: %d\n\n", iter);
	}
			 return xs;
}

double evalCubica (Cubica func, double num) {
  return ((func.a)*pow(num,3) + (func.b)*pow(num,2) + (func.c)*num + func.d);
}

double evalCuadratica(Cuadratica funct, double num) {
	return (funct.a)*(num*num)+(funct.b)*(num)+funct.c;
}
