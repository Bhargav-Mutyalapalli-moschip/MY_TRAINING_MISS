#include<stdio.h>
int main()
{
	int n,num,l;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	int arr[n];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("Enter the %d index element\n",i);
		scanf("%d",&arr[i]);
	}
	i=arr[0];
	k=arr[n-1];
	for(i,l=0;i<k;i++,l++)
	{
		if(i==arr[l])
		{
			continue;
		}
		else
		{

			printf("The output:%d\n",i);
			l--;
		}
	}
}




