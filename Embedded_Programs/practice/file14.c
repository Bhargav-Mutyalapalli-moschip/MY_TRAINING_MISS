#include<stdio.h>
int main()
{
	unsigned int x;
	scanf("%x",&x);
	x=(x&(0x1<<3)==(0x1<<23))?printf("no swap is required"):x^((0x1<<3)|(0x1<<23));

	printf("%x",x);
}
