#include<stdio.h>
int main()
{
	unsigned int num=0x11223344;
	unsigned int var=0;
	var|=(num&(0xff))<<24;
	var|=(num&(0xff << 8))<<8;
	var|=(num&(0xff << 16))>>8;
	var|=(num&(0xff << 24))>>24;
	printf("The 0x%x\n",var);
}


