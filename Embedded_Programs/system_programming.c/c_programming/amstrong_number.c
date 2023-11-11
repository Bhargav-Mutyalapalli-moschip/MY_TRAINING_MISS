#include<stdio.h>
int main()
{
	int sum=0,num,rem,temp,count=0,i;
	printf("enter the value\n");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		count++;
		temp=temp/10;
	}
	temp=num;
	printf("The val:%d----The num:%d----The count:%d\n",temp,num,count);
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum+(rem*rem*rem);
		temp=temp/10;
	}
	printf("The output:%d\n",sum);
}
	
	


