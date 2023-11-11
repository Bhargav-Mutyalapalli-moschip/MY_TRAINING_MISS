#include<stdio.h>
int main()
{
	int arr[5];
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
		printf("%d\n",arr[i]);
	}
	int j,k=0,count=0;
	for(j=0;j<5;j++)
	{
		count=1;
		k++;
		if((arr[j]==arr[k])&&(k<5))
		{
			count++;
			k++;

		}
		printf("%d----%d\n",arr[j],count);


	}
}

