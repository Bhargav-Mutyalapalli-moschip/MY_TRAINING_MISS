#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
int main()
{
	int i,j,sum=0,k=0;
	int arr[ROW][COL];
	if(ROW==COL)
	{
		for(i=0;i<ROW;i++)
		{
			for(j=0;j<COL;j++)
			{
				//scanf("%d",&arr[i][j]);
				//__fpurge(stdin);
				arr[i][j]=++k;
			}
		}
	}
	else
	{
		printf("Invalid rows and columns\n");
		exit(-1);
	}
	printf("The left diagonal matrix\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(i==j)
			{
				sum=sum+arr[i][j];
				printf("%-2d",arr[i][j]);
			}
			else if(j==(COL-1)-i)
			{
				sum=sum+arr[i][j];
				printf("%-2d",arr[i][j]);
			}

			else
				printf(" ");
		}
		printf("\n\n");
	}
	printf("Sum:%d\n",sum);
}

