#include<stdio.h>
int main()
{
	int v,test;
	printf("enter the value to check the boundary conditions: ");
	scanf("%d",&v);
	(v>=1 && v<=999) ? printf("the value is in range"):printf("the value is out f range");


}
