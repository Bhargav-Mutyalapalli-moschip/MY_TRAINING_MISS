#include<stdio.h>
int main()
{
	int h,sum=0,rem,temp,count=0,i,j=0,k=0;
	int arr[50];
	scanf("%d",arr);
	temp=arr[j];
	while(temp!=0)
	{
		rem=temp%10;
		count++;
		temp=temp/10;
	}
	printf("%d\n",count);
	temp=arr[j];
	for(i=count-1;i>=0;i--)
	{
		printf("Enter converted loop\n");
		arr[i]=temp%10;
		arr[i]=arr[i]+48;
		temp=temp/10;
		printf("The elements are%d\n",arr[0]);

	}
	for(i=0;i<count;i++)
		printf("%c",arr[i]);


}


