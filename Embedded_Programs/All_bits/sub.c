#include<stdio.h>
int main()
{
	int a=20,b=30;
	printf("The before A:%d----The B:%d\n",a,b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("The after A:%d----The B:%d\n",a,b);
}
