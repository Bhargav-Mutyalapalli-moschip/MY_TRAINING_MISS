#include<stdio.h>
#include<stdio_ext.h>
#include<stdio.h>
#define N 10
int main()
{
	int arr[N];
	int i,sum=0;
	printf("Enter the number\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
		sum=sum+arr[i];
	}
	sum=sum/N;
	printf("The average is :%d\n",sum);
}
	
	
		


