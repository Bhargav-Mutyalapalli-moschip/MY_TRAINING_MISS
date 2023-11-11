#include<stdio.h>
int main()
{
	unsigned int num1,num2,res,carry;
	printf("Enter the first number\n");
	scanf("%d",&num1);
	__fpurge(stdin);
	printf("Enter the second number\n");
	scanf("%d",&num2);
	while(num2!=0)
	{
		carry=num1&num2;
		num1=num1 ^ num2;
		num2=carry<<1;
	}
	printf("The sum is :%d\n",num1);
}
