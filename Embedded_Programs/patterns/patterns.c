#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i==j)
				printf("*");
			else if(j==9-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}

