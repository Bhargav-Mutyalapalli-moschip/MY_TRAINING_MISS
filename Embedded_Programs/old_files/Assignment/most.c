#include<stdio.h>
#define NUM 13
int main()
{
	int arr[NUM];
	int i1;
	for(i1=0;i1<NUM;i1++)
	{
		__fpurge(stdin);
		scanf("%d",&arr[i1]);
	}
	int i,j=0,count=0,count1=0,index1,index2,var;
	for(i=0;i<NUM;i++)
	{
		for(j=i+1;j<NUM;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;

				if(count>count1)
				{
					count1=count;
					index1=i;
					index2=j;
					var=arr[i];
				}
			}
			else
			{
				i++;
				count=0;
			}
		}


	}
	count1=count1+1;
	printf("Count is %d and number is %d and index1: %d index2:%d\n",count1,var,index1,index2);
}
