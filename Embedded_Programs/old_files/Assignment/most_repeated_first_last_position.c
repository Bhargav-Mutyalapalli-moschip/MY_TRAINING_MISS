#include<stdio.h>
#define NUM 10
int main()
{
	int arr[NUM],k;
	for(k=0;k<NUM;k++)
	{
		__fpurge(stdin);
		scanf("%d",&arr[k]);
	}
	int i,j,index1,index2,count1=0,count2=0,count=0,var,var1;
	int flag=0;
	for(i=0;i<NUM;i++)
	{
		printf("I value:%d\n",i);
		for(j=i+1;j<NUM;j++)
		{
			if(arr[i]==arr[j])
			{
				printf("Arr[i]:%d\nArr[j]:%d\n",arr[i],arr[j]);
				count++;
				if(count>count2)
				{
					count1=count2;
					count2=count;
					index1=i;
					index2=j;
					var=arr[i];
				}
			}
			else
			{
				count=0;
				i++;
			}	
		}
	}


	printf("The number %d is most repeated times of first index is %d and second index is %d\n",var,index1,index2);
}
