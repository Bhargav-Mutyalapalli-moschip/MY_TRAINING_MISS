#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num,count=0,i;
	printf("Enter the number\n");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		printf("The i:%d\n",i);
		if(num%i==0)
		count++;
	}
	printf("The count:%d\n",count);
	if(count==2)
	printf("it is prime number:%d\n",num);
	else
	printf("it is not prime number:\n");
	
}


