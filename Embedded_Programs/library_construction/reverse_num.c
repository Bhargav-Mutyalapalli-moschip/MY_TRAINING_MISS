#include<stdio.h>
void reverse_number(int num)
{
	int sum=0,rem,temp;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum*10+rem;
		temp=temp/10;
	}
	printf("The number before reversing:%d\nThe number after reversing:%d\n",num,sum);
}
