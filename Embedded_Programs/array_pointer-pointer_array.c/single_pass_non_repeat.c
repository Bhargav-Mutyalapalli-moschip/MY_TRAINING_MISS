#include<stdio.h>
int main()
{
	int arr[11];
	int i;
	for(i=0;i<11;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
	unsigned int result=0;
	for(i=0;i<11;i++)
	result=result^arr[i];
	printf("The non repeated:%u\n",result);
}

