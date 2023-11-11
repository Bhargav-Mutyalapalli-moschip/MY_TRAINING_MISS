#include<stdio.h>
int main()
{
	unsigned int var,num;
	scanf("%x",&var);
	num=(var&~(0x1<<15 && 0x1<<1))|((num&(0x1<<(15))>>(15-1)))|((num&(0x1<<1))>>(15-1));
	printf("The out:%x\n",num);
}

