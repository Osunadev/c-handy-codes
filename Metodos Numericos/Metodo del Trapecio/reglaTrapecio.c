#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void trapecio();
void trapecioMultiple();
void menu();
char menuFunciones();
void setIntervalo(double *a, double *b);
double formulaTrapecio(double a, double b, double (*funcion) (double));
double formulaTrapecioMultiple(double a, double b, double (*funcion) (double), int segmento);
//Comienzan las funciones
double FuncionA (double num);
double FuncionB (double num);
double FuncionC (double num);
double FuncionD (double num);
double FuncionE (double num);
double FuncionF (double num);

int main() {

	menu();
	return 0;
}

void trapecio() {
	double a,b;
	char resp = menuFunciones();
	double (*funcion)(double);//apuntador a funcion

	setIntervalo(&a,&b);

	switch(resp) {
		case 'a': funcion = FuncionA;	 break;
		case 'b': funcion = FuncionB;	 break;
		case 'c': funcion = FuncionC;	 break;
		case 'd': funcion = FuncionD;	 break;
		case 'e': break;
		case 'f': break;
	}
	
	printf("Intervalo [%f,%f] Valor de la integral de f(x) = %f\n", a,b,formulaTrapecio(a,b,funcion));

	free(funcion);

}

void trapecioMultiple() {
	double a,b;
	int n;
	char resp = menuFunciones();
	double (*funcion)(double);//apuntador a funcion

	setIntervalo(&a,&b);

	printf("Introduzca el numero de segmentos (un numero par): ");
	scanf("%d", &n);

	switch(resp) {
		case 'a': funcion = FuncionA;	 break;
		case 'b': funcion = FuncionB;	 break;
		case 'c': funcion = FuncionC;	 break;
		case 'd': funcion = FuncionD;	 break;
		case 'e': funcion = FuncionE;	 break;
		case 'f': funcion = FuncionF; 	 break;
	}
	
	printf("Intervalo [%f,%f] Valor de la integral de f(x) = %f\n", a,b,formulaTrapecioMultiple(a,b,funcion,n));

	free(funcion);

}

void menu() {
	int opc;
	
	printf("1) Metodo de la regla del Trapecio\n");
	printf("2) Metodo de la regla del Trapecio de aplicacion multiple\n");
	printf("Hola, bienvenido al menu de seleccion, por favor elija el metodo a usar : ");

	scanf(" %d", &opc);
	printf("\n");
	switch(opc) {
		case 1: trapecio();
				break;
		case 2: trapecioMultiple();
				break;

	}
}

char menuFunciones() {
	char opc;

	printf("a) f(x) = 0.2 + 25x - 200x^2 + 675x^3 - 900x^4 + 400x^5\n");
	printf("b) f(x) = e^x\n");
	printf("c) f(x) = 1/(1+x^2)\n");
	printf("d) f(x) = Log (x)\n");
	printf("e) f(x) = sen(x^2)\n");
	printf("f) f(x) = (1+x^2)^1/2\n");
	printf("Elija la funcion: ");

	scanf(" %c", &opc);
	printf("\n");
	return opc;
}

void setIntervalo(double *a, double *b) {
	printf("Intervalo inferior a de la funcion: ");
	scanf("%lf", a);
	printf("Intervalo superior b de la funcion: ");
	scanf("%lf", b);
}

double formulaTrapecio(double a, double b, double (*funcion) (double)) {
	return ((funcion(a)+funcion(b))/2.0)*(b-a);
}

double formulaTrapecioMultiple(double a, double b, double (*funcion) (double), int segmento) {
	double intervalo_n = (b-a)/segmento;
	double sumatoria = 0; //sumatoria corresponde al termino del medio de la formula
	for (double i=a+intervalo_n; i<b; i+=intervalo_n) {
		sumatoria += funcion(i);
	}

	return ((funcion(a)+2*sumatoria+funcion(b))/(2*segmento))*(b-a);

}

//Comienzan las funciones
double FuncionA (double num) {
	return 0.2+25*num-200*pow(num,2)+675*pow(num,3)-900*pow(num,4)+400*pow(num,5);
}

double FuncionB (double num) {
	return exp(num);
}

double FuncionC (double num) {
	return (1/(1+pow(num,2)));
}

double FuncionD (double num) {
	return log10(num);
}
//Funcion obtenida referente al sig video : https://www.youtube.com/watch?v=v0iIhdP9oxE
double FuncionE (double num) {
	return sin(num*num);
}
// Funcion obtenida del sig video : https://www.youtube.com/watch?v=EMjhj_Hj9pE
double FuncionF (double num) {
	return sqrt(1+num*num);
}

