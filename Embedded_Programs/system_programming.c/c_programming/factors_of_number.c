#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num,i;
	printf("Enter the number\n");
	scanf("%d",&num);
	if(num==0)
	{
		printf("The given value is zero we cant find the factors\n");
		exit(1);
	}
	for(i=1;i<num;i++)
	{
		if(num%i==0)
		printf("The factor:%d\n",i);
	}
}



