#include<stdio.h>
int main()
{
	int a=0,b=0,temp=0;
	printf("enter a value: ");
	scanf("%d",&a);
	__fpurge(stdin);
	printf("enter b value: ");
	scanf("%d",&b);
	temp=a;
	a=b;
	b=temp;
	printf("A is:%d\n B is: %d ",a,b);
}

