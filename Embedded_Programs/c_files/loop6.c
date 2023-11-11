
#include<stdio.h>
int main()
{
	int i,j;
	for(i=5;i>0;i--)
	{
		for(j=i;j>0;j--)
		{
			if(i>=j)
			{
				printf("&");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i<=j)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
}
