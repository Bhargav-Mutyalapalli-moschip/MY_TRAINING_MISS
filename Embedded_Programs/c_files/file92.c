#include<stdio.h>
int main()
{
	int a=10;
	int b=5;
	a=b-a;
	b=b-a;
	a=b+a;
	printf("%d %d",a,b);
}
