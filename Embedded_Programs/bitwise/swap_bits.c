#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	num=(num & (~((0xff<<(23)|(0x1<<(0))))))|((num &((0x1<<0))))|(num&(0x1>>(23)));
	printf("The swap:%x",num);
}
