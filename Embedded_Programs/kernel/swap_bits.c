#include<stdio.h>
int main()
{
	unsigned int num=0x11223344;
	unsigned int var=0;
	var=(num&(~((0x1 << 1) | (0x1 << 28))))|((num & (0x1 << 1)) << (28-1))|((num & (0x1 << 28)) >> (28 -1));
	printf("The out:%x\n",var);
}
