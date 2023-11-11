#include<stdio.h>
int main()
{
	int num,sum=0,rem,temp,pow=1;
	printf("enter the value to check binary:");
	scanf("%o",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%8;
		if(rem > 1)
		break;
		sum=sum+rem*pow;
		temp=temp/8;
		pow=pow*2;
	}
	printf("The binary:%o\n",sum);
}

