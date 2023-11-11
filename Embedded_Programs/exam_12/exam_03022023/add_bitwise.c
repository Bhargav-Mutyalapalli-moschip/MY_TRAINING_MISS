#include<stdio.h>
int main()
{
	int a=258,b=456,c;
	while(b!=0)
	{
		c=a&b;
		a=a^b;
		b=c<<1;
	}
	printf("sum : %d \n",a);
}
