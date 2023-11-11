#include<stdio.h>
void find(int *arr,int *small,int *large)
{
	int i,j,count1=0,count2=20000;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]>arr[j])
			{
				if(count1<arr[i])
				{
					count1=arr[i];
					*large=count1;
				}
			}
			if(arr[i]<arr[j])
			{
				if(count2>arr[i])
				{
					count2=arr[i];
					*small=count2;
				}
			}
		}
	}
}
			
int main()
{
	int arr[5]={20,10,50,30,40};
	int small,large;
	find(arr,&small,&large);
	printf("small : %d \nlarge : %d \n",small,large);
}
