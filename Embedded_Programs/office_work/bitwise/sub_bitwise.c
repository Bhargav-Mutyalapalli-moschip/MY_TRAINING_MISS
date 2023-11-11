#include<stdio.h>
int main()
{
	unsigned int a,b,carry=0;
	scanf("%d%d",&a,&b);
	while(b!=0)
	{
		carry=(~a)&b;
		a=a^b;
		b=carry<<1;
	}
	printf("The output:%d\n",a);
}
