#include<stdio.h>
int main()
{
	unsigned int num,mask=1<<31;
	scanf("%d",&num);
	int i;
	for(i=31;i>=0;i--)
	{
		(num & mask) ? printf("1") : printf("0");
		mask=mask>>1;
	}

}
