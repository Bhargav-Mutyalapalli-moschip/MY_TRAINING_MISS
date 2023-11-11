#include<stdio.h>
int main()
{
	unsigned int d=0x123456f,c=0;
	int i,count=0;
	for(i=0;i<32;i++)
	{
		if(((d&(0xf<<i))>>i)==0xf)
		{
			c=d|((0x7<<i));
		}

	}
	printf("The count is :%x\n",c);
}

