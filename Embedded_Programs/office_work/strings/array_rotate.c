#include<stdio.h>
#define NUM 5
int main()
{
	int i,a,n,temp,j;
	int arr[NUM];
	printf("ENter the value to rotate how many times\n");
	scanf("%d",&n);
	for(i=0;i<NUM;i++)
	{
		printf("Enter the %d index value\n",i);
		scanf("%d",&arr[i]);
	}
	int g=0,k=2;
	for(i=0;i<n;i++)
	{
		temp=arr[g];
		for(j=0;j<NUM-1;j++)
		{
			arr[j]=arr[j+1];

		}
	        arr[NUM-1]=temp;
		printf("The variables:%d\n",arr[i]);
	
		


	}
	for(i=0;i<NUM;i++)
	{
		printf("%d\n",arr[i]);
	}
}

		


