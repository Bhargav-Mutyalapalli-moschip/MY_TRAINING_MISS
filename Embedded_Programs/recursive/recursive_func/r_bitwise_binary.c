#include<stdio.h>
void binary_bitwise(unsigned int var,int k);
int sum=0;
int i=31;
int j;
int main()
{
	unsigned int num;
	printf("enter the value to perform\n");
	scanf("%d",&num);
	binary_bitwise(num,i);
}
void binary_bitwise(unsigned int var,int k)
{
	if(k>=0)
	{
		if((var&((0x1)<<k))==0)
			printf("0");
		else
			printf("1");
		binary_bitwise(var,k=k-1);

	}
}
	
	
