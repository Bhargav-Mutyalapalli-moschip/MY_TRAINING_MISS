#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	int i,count=0;
	for(i=0;i<32;i++)
	{
		if(((num&((0x7)<<i))>>i)==(0x5))
		{
			count++;
		}
	}
	printf("The count is:%d\n",count);
}

