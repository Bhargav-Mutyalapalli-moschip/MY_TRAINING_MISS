#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j%2==0)
			printf("1");
			else
			printf("0");
		}
		printf("\n");
	}
}




