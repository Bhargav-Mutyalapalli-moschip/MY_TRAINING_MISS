#include<stdio.h>
#include<limits.h>
#define N 10
int main()
{
	int arr[N];
	int i,high=INT_MIN,low=INT_MAX;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	//low=arr[0];
	for(i=0;i<N;i++)
	{
		if(arr[i] > high)
		high=arr[i];
		if(arr[i] < low)
		low=arr[i];
	}
	printf("The highest:%d-------The lowest%d\n",high,low);
}
