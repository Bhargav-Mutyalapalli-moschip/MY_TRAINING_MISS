#include<stdio.h>
#include<stdarg.h>
void func(int a,int b,...);
int main()
{
	int a=10;
	int b=20;
	func(a);
}
void func(int a,int b,...)
{
	printf("The out:%d\n",a);
	printf("The out:%d\n",b);
}




