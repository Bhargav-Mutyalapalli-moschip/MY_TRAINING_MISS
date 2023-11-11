#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	num=(num&~((0x1<<1)|(0x1<<15)))|((num&(0x1<<1))<<(15-1))|((num&(0x1<<15))>>(15-1));
	printf("The out:%x\n",num);
}
