#include<stdio.h>
int main()
{
	int a=10,x;
	int b=20;
	int *ptr1=&a;
	//int *ptr2=&b;
	x=*ptr1+4;
	printf("%p-----%d\n",&a,x);
	printf("%p-----%d\n",&b,b);
	x=*++ptr1;
	printf("%d-----%d\n",x,a);
	x=++*ptr1;
	printf("%d-----%d\n",x,a);
	x=(*ptr1)++;
	printf("%d-----%d\n",x,a);


}

