#include<stdio.h>
int main()
{
	unsigned int a;
	scanf("%d",&a);
	if((a&(0x1))==0)
	{
		printf("Even number\n");
	}
	else
		printf("Odd number\n");
}
