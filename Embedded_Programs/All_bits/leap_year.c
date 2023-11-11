#include<stdio_ext.h>
#include<string.h>
int main()
{
	int num;
	printf("enter a year:");
	scanf("%d",&num);
	__fpurge(stdin);
	if(num % 4==0)
	{
		if(num % 100==0)
		{
			if(num % 400==0)
			printf("Leap year\n");
			else
			printf("not a Leap year\n");

		}
		else
			printf("Leap year\n");
	}
	else
	printf("not a leap year\n");
}


