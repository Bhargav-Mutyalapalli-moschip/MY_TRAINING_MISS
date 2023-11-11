#include<stdio.h>
int main()
{
	unsigned int a=0x12345678;
	//a=(a&(~(0xff<<8))|((a>>16)))|((a&(~(0xff<<24)))|(a>>16));
	a=(((0xffff0000)&a)>>16|((0x0000ffff)&a)<<16);
	printf("a=0x%x\n",a);
}

