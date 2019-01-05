#include<stdio.h>
#include"bitman.h"

int main()
{
    int pos;
    int num;

    printf("Numero en hexadecimal:");
    scanf("%x",&num);

    printf("Posicion:");
    scanf("%d",&pos);

    printf("%d\n",setbit(num,pos));

    printf("%d\n",clearbit(0x82,2));

    return 0;
}

