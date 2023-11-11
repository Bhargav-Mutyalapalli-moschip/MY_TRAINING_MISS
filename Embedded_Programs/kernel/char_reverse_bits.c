#include<stdio.h>
int main()
{
	unsigned char num=0x88;
	unsigned char var=0;
	int i,j,k=0;
	for(i=0,j=7;i<j;i++,j--)
	{
		var=(num&(0x1 << i))<<(j-i);
		var=((num&(0x1 << j))>>(j-i));
	}
	printf("The 0x%d\n",num);
	printf("The 0x%d\n",var);
}

