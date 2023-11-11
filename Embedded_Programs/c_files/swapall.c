#include<stdio.h>
int main()
{
	unsigned int num;
	scanf("%x",&num);
	int i,j;
	for(i=0,j=31;i<j;i++,j--)
	{
		num=(num&(~((0x1)<<i)|(0x1)<<j)
