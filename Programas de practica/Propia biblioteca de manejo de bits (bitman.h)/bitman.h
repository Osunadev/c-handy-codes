#ifndef BITMAN
#define BITMAN

void display(int dato);
int setbit(int num, int pos);
int clearbit(int num, int pos);
unsigned char getbit(int num, int pos);
int togglebit(int num, int pos);
void encrypt(char * mensaje, unsigned char clave);
int rotleft(int num, int offset);
int rotright(unsigned int num, int offset);
unsigned char byte_rotleft(unsigned char valor, int offset);
unsigned char byte_rotright(unsigned char valor, int offset);
unsigned char getbyte(int num, unsigned char pos);

#endif