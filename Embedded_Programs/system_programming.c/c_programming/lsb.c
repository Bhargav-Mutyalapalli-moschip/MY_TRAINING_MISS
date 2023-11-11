#include<stdio.h>
int main()
{
	unsigned int num=0x81223341;
	if((num&(0x1)<<31) == 0)
	printf("it is not a set bit\n");
	else
	printf("it is  a set bit\n");
}
	
