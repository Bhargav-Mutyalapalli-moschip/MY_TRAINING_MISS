#include<stdio.h>
int main(int count,char*arr[])
{
	int i,k;
	int zero;
	int sum=0;
	int temp,m=0;
	int array[count-2];
	for(i=2;i<count;i++)
	{
		sum=0;
		zero=0;
		if(arr[i][0]=='-')
		{
			zero++;
		}
		for(k=zero;arr[i][k]!='\0';k++)
		{
			if(arr[i][k]>='0' && arr[i][k]<='9')
			{
				temp=arr[i][k]-48;
				sum=sum*10+temp;
			}
			else
			{
				printf("Inavlid input\n");
				return;
			}
		}
		if(zero==1)
		{
			sum=-(sum);
		}
		array[m]=sum;
		m++;
	}
	for(i=0;i<count-2;i++)
	printf("%d ",array[i]);
}



