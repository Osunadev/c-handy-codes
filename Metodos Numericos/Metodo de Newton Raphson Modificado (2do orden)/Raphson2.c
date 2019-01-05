  // Funcion en cuestion: cos(x) - 3x + 5
  // Valores iniciales para asignar: 0,1, PI, PI/2
  // Error relativo porcentual ea < 0.10, 0.01, 0.001

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Prototipos de funciones
double newtonRaphsonMod (double , double);
double evalFunc (double);
double evalDeriv (double);
double evalBideriv (double);

int main() {
  double xInicial; // X0
  double err_min;

    printf("\n\t Introduzca el valor inicial (Xi): ");
    scanf("%lf", &xInicial);
    printf("\n\t Introduzca el error aproximado: ");
    scanf("%lf", &err_min);
    printf("\n La raiz mas cercana es: %f", newtonRaphsonMod(xInicial, err_min) );

  return 0;
}

double newtonRaphsonMod (double xIni, double err_min) {

    double x_actual, x_actualV, x_proxima, x_proximaV, eval, eval_derivada, eval_biderivada, ea;
    int cont = 0;
    x_proxima = xIni;
    // x_actualV y x_proximaV son variables usadas para la verificacion
    printf("#  Xi\t\tf(Xi)\t\tf'(Xi)\t\tf''(Xi)\t\tXi+1\t\t  ea\t\t\n");
    do {
        x_actual = x_proxima; // Para que al inicio del do-while se iguale x_actual a x_proxima y asi x_actual tenga el valor de xIni

        eval = evalFunc(x_actual);
        eval_derivada = evalDeriv(x_actual);
				eval_biderivada = evalBideriv(x_actual);
        x_proxima = x_actual - ((eval*eval_derivada)/(pow(eval_derivada,2)-eval*eval_biderivada));

        ea = fabs( ((x_proxima - x_actual)/x_proxima)*100 );
        printf("%d  %f\t%f\t%f\t%f\t%f\t%f\t\n", ++cont, x_actual, eval, eval_derivada, eval_biderivada, x_proxima, ea);

    // Verificando que en la proxima iteracion no se vaya a pasar del error minimo
        x_actualV = x_proxima;
				eval = evalFunc(x_actualV);
				eval_derivada = evalDeriv(x_actualV);
				eval_biderivada = evalBideriv(x_actualV);
				x_proximaV = x_actualV - ((eval*eval_derivada)/(pow(eval_derivada,2)-eval*eval_biderivada));
        ea = fabs( ((x_proximaV - x_actualV)/x_proximaV)*100 );
       // Terminando verificacion

    } while(ea > err_min);

    return x_proxima;
}

double evalFunc (double num) {
  return (pow(num, 3) + 4 * pow(num, 2) - 10);
}

double evalDeriv (double num) {
	return 3*pow(num,2)+8*num;
}

double evalBideriv (double num) {
	return 6*num+8;
}
