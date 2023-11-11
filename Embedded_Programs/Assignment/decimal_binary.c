#include<stdio.h>
int main()
{
	int num,sum=0,rem,temp,pow=1;
	printf("enter the value to check binary:");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%2;
		sum=sum+rem*pow;
		temp=temp/2;
		pow=pow*10;
	}
	printf("The binary:%d\n",sum);
}

