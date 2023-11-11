#include<stdio.h>
void func(int a,int b);
int main(void)
{
	func(1,2);
	func(3,4);
}
void func(int a,int b)
{
	a++;
	b++;
	printf("%d %d\n",a,b);
}

