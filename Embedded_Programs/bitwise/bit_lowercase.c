#include<stdio.h>
int main()
{
	unsigned char u='p';
	u=u&(~32);
	printf("The upper case:%c\n",u);
}

