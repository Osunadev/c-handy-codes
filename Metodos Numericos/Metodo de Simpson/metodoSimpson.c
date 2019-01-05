
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void menu();
char menuFunciones();
void setIntervalo(double *a, double *b);

void simpson3_8();
void simpson1_3();
void simpson1_3Multiple();

double formulaSimpson3_8(double a, double b, double (*funcion) (double));
double formulaSimpson1_3(double a, double b, double (*funcion) (double));
double formulaSimpson1_3Multiple(double a, double b, double (*funcion) (double), int segmento);
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

void menu() {
	int opc;
	
	printf("1) Metodo de Simpson 1/3 \n");
	printf("2) Metodo de Simpson 1/3 de aplicacion multiple\n");
	printf("3) Metodo de Simpson 3/8\n");
	printf("Hola, bienvenido al menu de seleccion, por favor elija el metodo a usar : ");

	scanf(" %d", &opc);
	printf("\n");
	switch(opc) {
		case 1: simpson1_3();
				break;
		case 2: simpson1_3Multiple();
				break;
		case 3: simpson3_8();
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

void simpson1_3() {
	double a,b;
	char resp = menuFunciones();
	double (*funcion)(double);//apuntador a funcion

	setIntervalo(&a,&b);
	if (b>a) {

	switch(resp) {
		case 'a': funcion = FuncionA;	 break;
		case 'b': funcion = FuncionB;	 break;
		case 'c': funcion = FuncionC;	 break;
		case 'd': funcion = FuncionD;	 break;
		case 'e': funcion = FuncionE;	 break;
		case 'f': funcion = FuncionF; 	 break;
	}
	
	printf("Intervalo [%f,%f] Valor de la integral de f(x) = %f\n", a,b,formulaSimpson1_3(a,b,funcion));

	free(funcion);
	
	} else {
	    printf("Intoduzca un intervalo valido \n");
	}

}

void simpson1_3Multiple() {
	double a,b;
	int n;
	char resp = menuFunciones();
	double (*funcion)(double);//apuntador a funcion

	setIntervalo(&a,&b);

	if (b>a) {
	printf("Introduzca el numero de segmentos (un numero par): ");
	scanf("%d", &n);
	
	if (n%2 != 0) {
	    printf("\nIntroudzca un numero de segmentos par");
	    exit(0);
	}

	switch(resp) {
		case 'a': funcion = FuncionA;	 break;
		case 'b': funcion = FuncionB;	 break;
		case 'c': funcion = FuncionC;	 break;
		case 'd': funcion = FuncionD;	 break;
		case 'e': funcion = FuncionE;	 break;
		case 'f': funcion = FuncionF; 	 break;
	}
	
	printf("Intervalo [%f,%f] Valor de la integral de f(x) = %f\n", a,b,formulaSimpson1_3Multiple(a,b,funcion,n));

	free(funcion);
	} else {
	    printf("Intoduzca un intervalo valido \n");
	}
}

void simpson3_8() {
	double a,b;
	char resp = menuFunciones();
	double (*funcion)(double);//apuntador a funcion

	setIntervalo(&a,&b);

	if (b>a) {
	switch(resp) {
		case 'a': funcion = FuncionA;	 break;
		case 'b': funcion = FuncionB;	 break;
		case 'c': funcion = FuncionC;	 break;
		case 'd': funcion = FuncionD;	 break;
		case 'e': funcion = FuncionE;	 break;
		case 'f': funcion = FuncionF; 	 break;
	}
	
	printf("Intervalo [%f,%f] Valor de la integral de f(x) = %f\n", a,b,formulaSimpson3_8(a,b,funcion));

	free(funcion);
	} else {
	    printf("Intoduzca un intervalo valido \n");
	}
}

double formulaSimpson3_8(double a, double b, double (*funcion) (double)) {
	double h = (b-a)/3;

	return ((funcion(a)+3*funcion(a+h)+3*funcion(a+2*h)+funcion(b))/8.0)*(b-a);
}

double formulaSimpson1_3(double a, double b, double (*funcion) (double)) {
	double h = (b-a)/2;

	return ((funcion(a)+4*funcion(a+h)+funcion(b))/6.0)*(b-a);
}

double formulaSimpson1_3Multiple(double a, double b, double (*funcion) (double), int segmento) {
	double h = (b-a)/segmento;

	double sumImpar = 0; 
	double sumPar = 0; 

	for (double i=a+h; i<b; i+=2*h) {
		sumImpar += funcion(i);
	}

	for (double j=a+2*h; j<b; j+=2*h) {
		sumPar += funcion(j);
	}

	return ((funcion(a)+4*sumImpar+2*sumPar+funcion(b))/(3*segmento))*(b-a);

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
