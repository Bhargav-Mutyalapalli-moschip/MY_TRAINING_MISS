#include<stdio.h>
int main()
{
	unsigned int num1,num2,res,carry;
	int i;
	printf("Enter the first number\n");
	scanf("%d",&num1);
	__fpurge(stdin);
	printf("Enter the second number\n");
	scanf("%d",&num2);	
	while(num2>0)
	{
		if(num2 & 1)
			res=res+num1;
		num1=num1<<1;
		num2=num2>>1;
	}
	printf("The mul is :%d\n",res);
}
