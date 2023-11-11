#include<stdio.h>
#define N 10
int main()
{
	int arr[N];
	int i,j,count,k;
	printf("Enter the values\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	printf("before deleting\n");
	for(i=0;i<N;i++)
	{
		printf("The index %d:%d\n",i,arr[i]);
	}
	printf("after deleting\n");
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(arr[i] == arr[j])
			{
				for(k=j;k<N;k++)
				arr[k]=arr[k+1];
				count++;
			}

		}




	}
	printf("The count:%d\n",count);
	printf("after deleting\n");
	for(i=0;i<N-count;i++)
	{
		printf("The index %d:%d\n",i,arr[i]);
	}
}
