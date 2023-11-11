#include<stdio.h>
int main()
{
	unsigned int carry,a,b;
	printf("First number\n");
	scanf("%d",&a);
	printf("Second number\n");
	scanf("%d",&b);
	while(b!=0)
	{
		carry=(a)&b;
		a=a^b;
		b=carry<<1;
	}
	printf("The out:%d\n",a);
}

