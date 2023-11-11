#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	num=(num & ~((0xff<<16)|(0xff<<0)))|((num &(0xff<<0))<<(16-0))|((num&(0xff<<16))>>(16-0));
	printf("The swap:%x",num);
}
