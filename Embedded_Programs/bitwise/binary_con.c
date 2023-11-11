#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	int i,countz=0,counto=0;
	for(i=31;i>=0;i--)
	{
		if((num&(0x1<<i))==0)
		{
			printf("0");
			countz++;

		}
		else
		{
			counto++;
			printf("1");
		}
	}
	printf("The counto is:%d\n",counto);
	printf("The countz is:%d\n",countz);
}

