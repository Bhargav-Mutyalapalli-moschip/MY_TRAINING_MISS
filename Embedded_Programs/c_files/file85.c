#include<stdio.h>
int main()
{
	int a=65;
	int b=22;
	b=a++;
	printf("%d",b);
	b=++a;
        printf("%d",b);
	b=--a;

	printf("%d",b);
	b=--a;

	printf("%d %d",b,a);
}
