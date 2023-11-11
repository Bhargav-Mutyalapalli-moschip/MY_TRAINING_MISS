#include<stdio.h>
int main()
{
	unsigned int num=0xaabbccdd;
	unsigned int var=0,temp;
	int i,j,k=0;
	for(i=0;i<32;i++)
	{
		if((num&(1<<i)))
		{
			var=var|(1 << (31-i));
		}
		else
		{
			var =var | (0<<(31-i));
		}
	}
	printf("The 0x%x\n",var);
}

