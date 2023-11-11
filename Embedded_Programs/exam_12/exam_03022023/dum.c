#include<stdio.h>
int MAX;
int main()
{
	printf("enter the size of : ");
	scanf("%d",&MAX);
	int i,j,var=0,arr[MAX];
	for(i=0;i<MAX;i++)
	{
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<MAX;i++)
	{
		var=0;
		for(j=0;j<MAX;j++)
		{
			if(arr[i]==arr[j])
				var++;
		}
		if(var==1)
			printf("once repeated is : %d \n",arr[i]);
	}
}
