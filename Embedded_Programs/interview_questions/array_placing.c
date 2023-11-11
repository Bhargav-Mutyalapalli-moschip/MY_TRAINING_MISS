#include<stdio.h>
int main()
{
	int arr[10];
	int i,j,sum,c_z=0,c_o=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	for(i=0;i<10;i++)
	{
		for(j=9;j>i;j--)
		{
			if(arr[i]==1 && arr[j]==0)
			{
				sum=arr[i];
				arr[i]=arr[j];
				arr[j]=sum;
			}
			
		}
	}
	

	for(i=0;i<10;i++)
	{
		printf("%d",arr[i]);

	}
}

