#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int main()
{
	unsigned int num=20,num2=45,carry=0;
	while(num2!=0)
	{
		carry=(~num)&num2;
		num=num^num2;
		num2=carry<<1;
	}
	printf("The out:%d\n",num);
}

