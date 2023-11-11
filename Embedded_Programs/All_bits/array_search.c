#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[5];
	int sarr[5];
	int i,count=0,var,j;
	for(i=0;i<5;i++)
	{
		printf("Main list\n");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("search list\n");
		scanf("%d",&sarr[i]);
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		if(arr[i]==sarr[j])
		{
			var=arr[i];
			count++;
		}
	}
	if(count > 0)
	{
		printf("%d\n",var);
	}
	else
		printf("No element in this\n");
}

