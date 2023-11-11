#include<stdio.h>
int main()
{
	unsigned int num=0x11223344,var=0;
	printf("The out:%x\n",num);
	var = var | ((0xff & num)<<24);
	var = var | (((0xff << 8) & num)<<8);
	var = var | (((0xff << 16) & num)>>8);
	var = var | (((0xff << 24) & num)>>24);
	printf("The out:%x\n",var);
}


