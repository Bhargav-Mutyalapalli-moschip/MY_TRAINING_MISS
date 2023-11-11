#include<stdio.h>
int binary_bitwise(unsigned int num);
void main()
{


        printf("enter the value to check:");
        scanf("%x",&num);
        binary_bitwise(num);
}
void binary_bitwise(unsigned int num)
{
	int i;
	for(i=32;i>0;i--)
	{
		if(((num&(0x1<<i))>>i)==0)
		{
			printf("0");
		}
		else
			printf("1");
	}
}


