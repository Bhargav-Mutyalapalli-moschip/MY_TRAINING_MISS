#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int num=0xaabbccdd,rev=0;
	int i;
	for(i=0;i<32;i++)
	{
		if(num&0x1<<i)
		{
			rev=rev|0x1<<(31-i);
		}
	}
	printf("The out:%x\n",rev);
}

