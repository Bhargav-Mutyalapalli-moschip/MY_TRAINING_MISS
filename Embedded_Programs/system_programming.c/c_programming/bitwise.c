#include<stdio.h>
int main()
{
	unsigned int a=45,b=10,car=0;
	while(b!=0)
	{
		car=(~a)&b;
		a=a^b;
		b=car<<1;
	}
	printf("The out:%u\n",a);
}
