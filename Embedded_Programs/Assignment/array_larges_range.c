#include<stdio.h>
int main()
{
	int i,j,count=0,var=0;
	int arr[12]={2,3,4,4,4,5,4,5,5,6,7,7};
	for(i=0;i<12;i++)
	{
		if(var==arr[i])
			continue;
		for(j=i;j<12;j++)
		{

			if(arr[i]==arr[j])
			{
				
				count++;
				var=arr[i];
			}
		}
		if(count>1)
		{
			printf("The number %d is occured %d\n",arr[i],count);
		}
		count=0;
	}
}

