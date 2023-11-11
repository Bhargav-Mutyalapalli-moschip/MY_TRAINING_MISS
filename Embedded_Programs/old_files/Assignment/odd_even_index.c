#include<stdio.h>
#define NUM 6
int main()
{
	int arr[NUM];
	int i,j,var;
	printf("Hii hello namesthey\n");
	for(i=0;i<NUM;i++)
	{
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<NUM-1;i++)
	{
		if(i%2==0)
		{
			if(arr[i]<arr[i+1])
			{
				arr[i]=arr[i];
			}  
			else
			{
				var=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=var;
			}
		}
		else
		{
			if(arr[i]>arr[i+1])
				arr[i]=arr[i];
			else
			{
				var=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=var;
			}
		}
	}
	for(i=0;i<NUM;i++)
	{
		__fpurge(stdin);
		printf("The output after arranging:%d \n",arr[i]);
	}
}



