#include<stdio.h>
#include<string.h>
int main()
{
	unsigned int num1=20;
	unsigned int num2=40;
	unsigned int carry=0;
	while(num2 != 0)
	{
		carry=(~num1) & num2;
		num1 = num1 ^ num2;
		num2=carry<<1;
	}
	printf("The out:%d\n",num1);
}




