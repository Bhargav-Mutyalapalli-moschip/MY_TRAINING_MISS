#include<stdio.h>
int main()
{
	int num,sum=0,rem,temp,pow=1;
	printf("enter the value to check binary:");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem > 1)
		break;
		sum=sum+rem*pow;
		temp=temp/10;
		pow=pow*2;
	}
	printf("The binary:%d\n",sum);
}

