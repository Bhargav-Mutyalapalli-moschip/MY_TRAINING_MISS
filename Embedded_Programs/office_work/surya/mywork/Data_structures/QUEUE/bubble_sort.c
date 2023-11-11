#include<stdio.h>
int main()
{
	int arr[6]={5,6,4,3,1,2};
	int i,e,temp,j;
	for(e=6;e>0;e--)
	{
		for(i=0;i<6;i++)
		{
			j=i+1;
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<6;i++)
	printf("%d\n",arr[i]);
}

