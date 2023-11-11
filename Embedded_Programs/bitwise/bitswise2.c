#include<stdio.h>
int main()
{
	unsigned int x=0x24334435,x1,x2;
	x=x|(((x<<20)&(0xf0<<8))|((x>>20)&(0xf0)));

	//unsigned short int b=x2;

	printf("%x\n",x);
	//printf("%x",b);
}

