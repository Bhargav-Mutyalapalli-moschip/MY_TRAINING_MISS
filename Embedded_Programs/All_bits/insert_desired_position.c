#include<stdio.h>
#define N 10
int main()
{
	int arr[N];
	int i,num,pos;
	printf("Enter the values\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	printf("Enter the element and tell me the indix to insert\n");
	scanf("%d%d",&num,&pos);
	__fpurge(stdin);
	printf("before insering\n");
	for(i=0;i<N;i++)
	{
		printf("The index %d:%d\n",i,arr[i]);
	}
	arr[pos-1]=num;
	printf("after insering\n");
	for(i=0;i<N;i++)
	{
		printf("The index %d:%d\n",i,arr[i]);
	}
}
