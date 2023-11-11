#include<stdio.h>
int main()
{
	int i,j,n=4,l=3-1;
	int sum=0;
	int arr[3][3]={1,2,3,4,5,6,7,8,9};
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==l)
			{
			  printf("%d",arr[i][j]);
			  sum=sum+arr[i][j];
			 }
			else
				printf(" ");
		}
		l--;
		printf("\n");
	}
	printf("Sum:%d\n",sum);
}

