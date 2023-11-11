#include<stdio.h>
int test(int a,int b);
int main()
{
	int x=0;
	x=(void)test(1,2);
	printf("%d",x);
}
int test(int a,int b)
{
	printf("%d",a+b);
	return a+b;
}

