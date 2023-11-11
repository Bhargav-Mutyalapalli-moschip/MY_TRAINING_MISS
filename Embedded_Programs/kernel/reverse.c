#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	unsigned int num=0x11223344;
	unsigned int var=0,temp;
	for(i=0;i<32;i++)
	{
		temp=(num & (0x1 << i));
		if(temp)
		{
			var = var | (0x1 << (31-i));
		}
	}
	printf("The reverse number is:0x%x\n",var);
}



