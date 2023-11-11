#include<stdio.h>
int main()
{
	int a=10,b=25,c=65,d=0;
	d=(a=b,c=a+b+c,a=a+b);
	printf("The d:%d\n",d);
}
