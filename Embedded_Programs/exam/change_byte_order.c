#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int num=0x11223344,rem;
	rem |= (num&(0xff))<<24;
	rem |= (num&(0xff<<8))<<8;
	rem |= (num&(0xff<<16))>>8;
	rem |= (num&(0xff<<24))>>24;
	printf("The rem:%x\n",rem);
}
	


