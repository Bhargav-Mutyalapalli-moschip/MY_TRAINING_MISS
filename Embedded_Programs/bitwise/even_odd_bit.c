#include<stdio.h>
int main()
{
	unsigned int a=6;
	scanf("%u",&a);
	if((a&(0x1))==0)
		printf("The %d is even number\n",a);
	else
		printf("The %d is odd number\n",a);

	
}
