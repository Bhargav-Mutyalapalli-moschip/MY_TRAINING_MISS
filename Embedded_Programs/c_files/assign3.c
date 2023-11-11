#include<stdio.h>
int main()
{
	unsigned int num=0x55,res;
	int i;
	for(i=0;i<=7;i++)
	{
		res=(num&(0x7<<i));
		printf("%x",res);
	}
}

