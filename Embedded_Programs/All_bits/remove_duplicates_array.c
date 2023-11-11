#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j,count=0,k,count1;
	int arr[10];
	for(i=0;i<10;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
				for(k=j;k<10;k++)
				arr[k]=arr[k+1];
			}
			else
				count1=count;
		}
	}
	printf("Count:%d\n",count);
	for(i=0;i<10-count1;i++)
		printf("The output:%d\n",arr[i]);
}










