#include<stdio.h>
main()
{
	int x,t;
	printf("enter a value x: ");
	scanf("value is:%d",&x);
	__fpurge(stdin);
	printf("enter a value t: ");
	scanf("value is:%d",&t);
	printf("%d %d",x,t);
}




