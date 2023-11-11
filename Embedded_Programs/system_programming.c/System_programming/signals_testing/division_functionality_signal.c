#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int main()
{
	int a,b,c;
	printf("Enter first number\n");
	scanf("%d",&a);
	__fpurge(stdin);
	printf("Enter second number\n");
	scanf("%d",&b);
	c=a/b;
	printf("The resultant is:%d\n",c);
}

	


