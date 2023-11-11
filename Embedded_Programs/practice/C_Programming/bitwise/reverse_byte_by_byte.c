#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int main()
{
	unsigned int num=0xff223344,rem;
	rem |= (num&0xff)<<24;
	rem |= (num&0xff<<8)<<8;
	rem |= (num&0xff<<16)>>8;
	rem |= (num&0xff<<24)>>24;
	printf("The changed:0x%x\n",rem);
}

