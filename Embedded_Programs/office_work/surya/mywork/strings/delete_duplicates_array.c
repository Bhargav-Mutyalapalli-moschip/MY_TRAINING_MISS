#include<stdio.h>
int main()
{
	int arr[10]={10,4,5,6,1,2,8,1,3,9};
	int i,j,count=0,k;
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
				for(k=j;k<10;k++)
				{
					arr[k]=arr[k+1];
					
				}
				/*for(k=i;k<10;k++)
				{
					arr[k]=arr[k+1];
				}
				*/	
			//	i=i-1;
			}
		}
	}
	for(i=0;i<10-count;i++)
	printf("%d\n",arr[i]);
}


