#include<stdio.h>
void count_digits(int num)
{
	int rem,temp;
	temp=num;
	int count=0;
	while(temp!=0)
	{
		temp=temp/10;
		count++;
	}
	printf("The number of digits is:>>>>>>>>>(       %d)\n",count);
}
	
