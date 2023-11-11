#include<stdio.h>
int main()
{
	unsigned long int x=0x89;
	x=x>>64;
	printf("%lx",x);
}
