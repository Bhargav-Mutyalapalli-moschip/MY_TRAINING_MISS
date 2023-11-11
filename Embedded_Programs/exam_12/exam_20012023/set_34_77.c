#include<stdio.h>
int main()
{
	int a=0x12345678;
	int b=0x77;
	//a=((~(0xff<<16))&a|(0x77<<16));
	a = (a&(~(0xff<<16)))|(0x77<<16);
	printf("a=0x%x\n",a);
}

