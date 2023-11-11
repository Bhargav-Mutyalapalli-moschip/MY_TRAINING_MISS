#include<stdio.h>
int main()
{
	unsigned int n=0x89,j;
	j=n>>(int)32;
	printf("%x",j);
}

