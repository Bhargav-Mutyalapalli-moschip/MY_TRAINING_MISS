#include<stdio.h>
int main()
{
	int temp,num=123456789,sum=0,rem;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum*10+rem;
		temp=temp/10;
	}
	printf("%d",sum);
}

