#include<stdio.h>
union node
{
	int a;
	double b;
}var;
int main()
{
	var.a=20;
	printf("%d\n",var.b);
}

