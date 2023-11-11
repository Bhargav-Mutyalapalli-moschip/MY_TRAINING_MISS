                                      /*Reverse the number using goto statement*/
#include<stdio.h>
int main()
{
	//These are declarations for the variables
	int num,sum=0,temp,rem;
	printf("enter the number to be perform the operation: \n");
	scanf("%d",&num);
	temp=num;
reverse:	rem=temp%10;
		sum=sum*10+rem;
		temp=temp/10;
		if(temp!=0)
			goto reverse;
	
	        printf("%d\n",sum);
}
