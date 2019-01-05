  // Funcion en cuestion: x^3+4x^2-10
  // Valores iniciales para asignar: 0,3,4
  // Error relativo porcentual ea < 0.10, 0.01, 0.001
  
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definicion de estructuras
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

} Cuadratica; // Estructura para mi derivada

// Prototipos de funciones
double evalCubica(Cubica funcion, double num);
double evalCuadratica(Cuadratica func, double num);
double newtonRaphson (Cubica funct, Cuadratica deriv, double xIni, double err_min);

int main(int argc, char * argv[]) {
  Cubica funct;
  Cuadratica derivada = {3,8,0};
  double xInicial; // X0
  double err_min;

  if (argc < 5) {

      printf("Introduzca los coeficientes de su ecuacion cubica para poder empezar. \n");
      printf("\nEjemplo (Para la ecuacion 2x^3 - 10x^2 + 4.33x + 12):\traphson1.exe 2 -10 4.33 12");
      return 1;

  } else {
    funct.a = atof(argv[1]);
    funct.b = atof(argv[2]);
    funct.c = atof(argv[3]);
    funct.d = atof(argv[4]);

    printf("\n\t Introduzca el valor inicial (Xi): ");
    scanf("%lf", &xInicial);
    printf("\n\t Introduzca el error aproximado: ");
    scanf("%lf", &err_min);
    printf("\n La raiz mas cercana es: %f", newtonRaphson(funct, derivada, xInicial, err_min) );
  }

  return 0;
}

double newtonRaphson (Cubica funct, Cuadratica deriv, double xIni, double err_min) {

    double x_actual, x_actualV, x_proxima, x_proximaV, x_eval, x_evalDerivada, ea;
    int cont = 0;
    x_proxima = xIni;
    // x_actualV y x_proximaV son variables usadas para la verificacion
    printf("#  Xi\t\tf(Xi)\t\tf'(Xi)\t\tXi+1\t\t\ ea\t\t\n");
    do {
        x_actual = x_proxima; // Para que al inicio del do-while se iguale x_actual a x_proxima y asi x_actual tenga el valor de xIni

        x_eval = evalCubica(funct, x_actual);
        x_evalDerivada = evalCuadratica(deriv, x_actual);
        x_proxima = x_actual - (x_eval/x_evalDerivada);
        
        ea = fabs( ((x_proxima - x_actual)/x_proxima)*100 );
        printf("%d  %f\t%f\t%f\t%f\t%f\t\n", ++cont, x_actual, x_eval, x_evalDerivada, x_proxima, ea);

    // Verificando que en la proxima iteracion no se vaya a pasar del error minimo
        x_actualV = x_proxima;
        x_eval = evalCubica(funct, x_actualV);
        x_evalDerivada = evalCuadratica(deriv, x_actualV);
        x_proximaV = x_actualV - (x_eval/x_evalDerivada);
        ea = fabs( ((x_proximaV - x_actualV)/x_proximaV)*100 );
       // Terminando verificacion
        
    } while(ea > err_min);

    return x_proxima;
}

double evalCubica (Cubica func, double num) {
  return ((func.a)*pow(num,3) + (func.b)*pow(num,2) + (func.c)*num + func.d);
}

double evalCuadratica(Cuadratica func, double num) {
  return ((func.a)*pow(num,2) + (func.b)*num + func.c);
}
