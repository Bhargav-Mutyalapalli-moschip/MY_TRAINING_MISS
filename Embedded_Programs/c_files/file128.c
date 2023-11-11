#include<stdio.h>
int main()
{
	unsigned int x;
	scanf("%d",&x);
	((x&(0x1<<3))==(0x1<<7) ? printf("%x",x):(x=(x^((0x1<<3)|(0x1<<7))));
	printf("%x",x);
}
