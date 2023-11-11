#include<stdio.h>
int main()
{
	int c,i;
	unsigned int num;
	scanf("%d",&num);
	c=num&(0x1<<1);
	if(c==0)
		num=num|(0x1<<1);
	else
		num=num&(~(0x1<<1));
	for(i=31;i>=0;i--)
	{
		if((num&(0x1<<i))==0)
			printf("0");
		else
			printf("1");
	}

	printf("The clear:%d\n",num);
}
