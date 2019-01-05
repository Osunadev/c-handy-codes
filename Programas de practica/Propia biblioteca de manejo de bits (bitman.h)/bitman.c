#include<stdio.h>
#include"bitman.h"

void display(int dato)
{
    int i;
    unsigned int mask = 0x80000000; // 10000000.00000000.00000000.00000000
    //Menor a 16 porque un short tiene 2 bytes, 16 bits
    for(i=0; i<32; i++)
    {

        if(dato&mask)
        {
            putchar('1');
        }
            else putchar('0');

        mask >>=1; // Es igual a mask = mask>>1;

        if(i==7 || i==15 || i==23) putchar('.'); //Para separar el 2do byte del 1ro
    }
}

int setbit(int num, int pos)
{
    return (num|(1<<(pos-1))); //Regresa al numero modificado, con unos agregados
}

int clearbit(int num, int pos)
{
    return (num&~(1<<(pos-1))); //Regresa al numero con ceros agregados
}

unsigned char getbit(int num, int pos)
{
    unsigned int mask = 0x01; //00000000.00000000.00000000.00000001

    mask <<= (pos-1); // (pos-1) porque las posiciones empiezan desde el cero

    if(mask&num) return 1;
        else return 0;
}

int togglebit(int num, int pos)
{
    unsigned int mask = 0x01; //00000000.00000000.00000000.00000001

    mask <<= (pos-1); // (pos-1) porque las posiciones empiezan desde el cero

    return num^mask;
}


void encrypt(char * mensaje, unsigned char clave)
{
    int i, size = 0;
    while (mensaje[size]!= '\0') size++;

    for(i=0; i<size; i++)
    {
        * (mensaje+i) = *(mensaje +i)^clave;
    }

}

int rotleft(int num, int offset)
{
    int i,finbit;

    for(i=0; i<offset; i++)
    {
        finbit = getbit(num,32); //Obtengo el bit final del entero

        num = (num<<1)^finbit; //vamos a recorrer el numero de 1 en 1
    }


    return ( (valor>>(8-offset))^(valor<<offset) );
}

int rotright(unsigned int num, int offset)
{
    int i;
    unsigned int finbit;

    for(i=0; i<offset; i++)
    {
        if (getbit(num,1)) finbit = 0x80000000; // 10000000.00000000.00000000.00000000
            else finbit = 0;

        num = (num>>1)^finbit;

    }
    return num;
}

unsigned char byte_rotleft(unsigned char valor, int offset)
{
    return ( (valor>>(8-offset))^(valor<<offset) );
}

unsigned char byte_rotright(unsigned char valor, int offset)
{
    return ( (valor<<(8-offset))^(valor>>offset) );
}

unsigned char getbyte(int num, unsigned char pos)
{
    return (char) (num>>pos);
}