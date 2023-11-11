#include<stdio.h>
#define NUM 10
int main()
{
	int arr[NUM];
	int target=20;
	int i,j;
	for(i=0;i<NUM;i++)
	{
		printf("Enter the elements\n");
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<NUM;i++)
	{
		for(j=i+1;j<NUM;j++)
		{
			if((arr[i]+arr[j])==target)
			printf("The first element %d The second element %d to get the %d\n",arr[i],arr[j],target);
		}
	}
}
