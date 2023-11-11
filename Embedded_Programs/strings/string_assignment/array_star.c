#include<stdio.h>
int main()
{
	int arr[10]={1,2,3,3,3,3,3,3,3,9};
	int i,j,ind1=0,ind2=0,count=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		if(count>0)
			printf("Count:%d\n",count);
		count=0;
	}
}
