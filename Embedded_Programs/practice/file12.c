#include<stdio.h>
int main()
{
	unsigned int x=0x11223344;
	unsigned char y=0;
	x=x&(0xff>>8);
	printf("%x",y);
}
