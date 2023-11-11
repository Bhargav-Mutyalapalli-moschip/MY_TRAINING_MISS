#include<stdio.h>
int main()
{
	int arr[100];
	scanf("%d",arr);
	int i,sum=0,temp,j=0;
	for(i=2;i>=1;i--)
	{
		arr[i]=arr[j]%10;
		arr[i]=arr[i]+48;
		arr[j]=arr[j]/10;
	}
	for(i=0;i<3;i++)
		printf("%c",arr[i]);
}


	
	
