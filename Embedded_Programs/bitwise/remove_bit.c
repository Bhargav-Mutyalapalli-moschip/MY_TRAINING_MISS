#include<stdio.h>
int main()
{
	unsigned char a=255;
	a=a&(~(0x1<<7));
	printf("The output is:%d\n",a);
}
