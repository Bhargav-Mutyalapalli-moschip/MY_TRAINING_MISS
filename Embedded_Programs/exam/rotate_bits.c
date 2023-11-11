#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int main()
{
	int bit1,bit2;
	unsigned int num=0x11223344;
	printf("enter the first position:");
	scanf("%d",&bit1);
	__fpurge(stdin);
	printf("enter the second position:");
	scanf("%d",&bit2);
	__fpurge(stdin);
	if(bit1 > bit2)
	{
		bit1=bit1^bit2;
		bit2=bit1^bit2;
		bit1=bit1^bit2;
	}
	num=(num & ~ ((0xff<<bit1)|(0xff<<bit2)))|((num&(0xff<<bit1))<<(bit2-bit1))|((num&(0xff<<bit2))>>(bit2-bit1));
	printf("The num after rotation:%x\n",num);
}



