#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
int main()
{
	int fd[2];
	pipe(fd);
	int sum=0,rem,num,temp;
	printf("Enter the number to check sum of digits\n");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=sum+rem;
		temp=temp/10;
	}
	printf("The sum is:%d\n",sum);
	raise(9);
}
	
	

