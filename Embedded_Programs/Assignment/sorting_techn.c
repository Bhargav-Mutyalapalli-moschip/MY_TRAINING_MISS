#include<stdio.h>
int main()
{
	int arr[5]={5,3,1,4,2};
	int i,j,temp;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]>arr[j])
			{
				arr[i]=arr[i]^arr[j];
				arr[j]=arr[i]^arr[j];
				arr[i]=arr[i]^arr[j];
			}
		}
	}
	for(i=0;i<5;i++)
	printf("The sorted order at %d index and the element:%d\n",i,arr[i]);
}
