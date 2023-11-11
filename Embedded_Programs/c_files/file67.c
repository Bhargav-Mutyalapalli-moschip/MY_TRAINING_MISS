#include<stdio.h>
int main()
{
	int a,b,c;
	printf("ENTER THE NUMBERS: ");
	scanf("%d %d %d",&a,&b,&c);
	c=a;
	a=b;
	b=c;
	printf("%d %d",a,b);
}

