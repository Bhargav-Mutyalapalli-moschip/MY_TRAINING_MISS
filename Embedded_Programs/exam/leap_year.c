#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	if((num%4==0)&&(num%100)||(num%400))
	{
		printf("leap\n");
	}
	else
		printf("Not leap\n");
}



