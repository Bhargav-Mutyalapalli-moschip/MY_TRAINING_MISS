#include<stdio.h>
int main()
{
	unsigned int x=0xffffff55;
	int i;
	for(i=0;i<32;i++)
	{
		if(((x&(0x7<<i))>>i)==0x5)
		{
			printf("inner\n");
			x=x|(0x7<<i);
		}
	}
	printf("The output:%x\n",x);
}
