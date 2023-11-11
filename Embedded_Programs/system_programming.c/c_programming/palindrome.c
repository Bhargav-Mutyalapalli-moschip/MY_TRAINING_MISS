#include<stdio.h>
int main()
{
	int sum=0,rem,num,temp;
	printf("Enter the number to check palindrome or not\n");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum*10+rem;
		temp=temp/10;
	}
	if(sum==num)
	printf("It is a plaindrome:%d\n",sum);
	else
	printf("It is not a plaindrome\n");
}
	
	
