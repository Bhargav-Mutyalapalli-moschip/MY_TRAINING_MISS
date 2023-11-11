#include<stdio.h>
int main()
{
	unsigned int x=3;
	x=x^(0x1<<3);
	printf("The output is:%u",x);
}
