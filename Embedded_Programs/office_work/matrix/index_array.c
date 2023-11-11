#include<stdio.h>
#define NUM 5
int main()
{
	int arr[NUM]={1,3,5,8,9};
	int i,j,l,k;
	l=arr[NUM-1];
	k=arr[0];
	for(i=0,k;k<l;k++,i++)
	{
		printf("ENtered\n");
		if(arr[i]==k)
			continue;
		else
		{
			printf("%d\n",k);
			i--;
		}
	}
}
