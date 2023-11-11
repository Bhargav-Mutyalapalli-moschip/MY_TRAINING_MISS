#include<stdio_ext.h>
#define ROW 3
#define COL 3
void swap(int arr[ROW][COL])
{
	int arr2[ROW][COL];
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			arr2[j][i]=arr[i][j];
		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			arr[i][j]=arr2[i][j];
		}
	}
}

int main()
{
	int arr[ROW][COL];
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			__fpurge(stdin);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("mainenrte");
	swap(arr);
	printf("maine return");
	for(i=0;i<ROW;i++)
	{
		printf("\n");
		for(j=0;j<COL;j++)
		{
			printf("%d\t",arr[i][j]);
		}
	}
}
