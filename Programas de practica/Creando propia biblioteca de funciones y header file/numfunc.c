#include<stdio.h>
#include<stdlib.h>

int reversa(int num)
{
	int res,numrev=0;

	while(num>0)
	{
		res=(num%10);
		num=num/10;
		numrev=numrev*10+res;

	}

	return numrev;

}

int digitos(int num)
{
	int digitos=0;

	while(num>0)
	{
		num=num/10;
		digitos++;
	}

	return digitos;

}

int suma(int num)
{
	int sum=0,res=0;


	while(num>0)
	{
		res=(num%10);
		num=num/10;

		sum=sum+res;
	}

	return sum;
}

int sumdiv(int num) //suma de los divisores de un numero
{

	int i, suma=0;

		for (i=1; i<num; i++){

		if( num%i==0 ) {

			suma=suma+i;

		}

    }

	return suma;
}


int perfecto(int num)
{
	int perfsum=0;

	perfsum=sumdiv(num);

	if (perfsum==num) return 1;
		else return 0;
}


void amigos(int num1, int num2)
{

 int amigo1=0 , amigo2=0;

 amigo1=sumdiv(num1);

 amigo2=sumdiv(num2);

 if( amigo1==num2) printf("Los numeros %d y %d son amigos porque la suma de los divisores propios de %d es igual a %d", num1, num2, num1, num2);

    else if( amigo2==num1) printf("Los numeros %d y %d son amigos porque la suma de los divisores propios de %d es igual a %d", num2, num1, num2, num1);

    else printf("El numero %d y %d no son amigos", num1, num2);
}

