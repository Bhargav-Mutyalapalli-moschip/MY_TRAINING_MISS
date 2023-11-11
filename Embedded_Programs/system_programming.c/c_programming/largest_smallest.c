#include<stdio.h>
#define N 10
int main()
{
	int arr[N];
	int i,larg=0,small;
	printf("Enter the number\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	small=arr[5];
	for(i=0;i<N;i++)
	{
		if(arr[i]>=larg)
		{
			larg=arr[i];
		}
		if(arr[i] <= small )
			small=arr[i];
	}
	printf("The larg:%d-----The small:%d\n",larg,small);
}


