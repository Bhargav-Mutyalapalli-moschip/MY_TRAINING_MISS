#include<stdio.h>
#define NUM 10
int main()
{
	int i,j,temp;
	int arr[NUM];
	int n=11;
	int d=0,k,count=0;
	printf("Enter the elements\n");
	for(temp=0;temp<NUM;temp++)
	{
		scanf("%d",&arr[temp]);
	}
	temp=0;

	for(i=0;i<NUM;i++)
	{
		k=i+d;
		if(arr[k]==0)
		{
			//count++;
			temp=arr[k];
			for(j=k;j<NUM;j++)
			{
				arr[j]=arr[j+1];
		         }
			d--;
		//	i=i-1;
			//printf("The num:%d\n",d);
			arr[NUM-1]=temp;
			
		}
	}
	for(i=0;i<NUM-count;i++)
	printf("The output is:%d\n",arr[i]);
}


