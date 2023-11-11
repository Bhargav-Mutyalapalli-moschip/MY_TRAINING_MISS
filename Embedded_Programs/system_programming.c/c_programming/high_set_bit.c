#include<stdio.h>
int main()
{
	int i,var=0,sum;
	unsigned int num;
	printf("Enter value:");
	scanf("%x",&num);
	for(i=0;i<32;i++)
	{
		printf("The \n");
		if((num&(0x1<<i)) != 0)
		{
		printf("Theereeergv \n");
			var=i;
			break;
		}
	}
	printf("The higest set bit is:%d\n",var);
}


