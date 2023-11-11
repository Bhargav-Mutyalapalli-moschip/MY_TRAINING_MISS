#include<stdio.h>
int main()
{
	int a=0,b=1,c,count=2;
	int num;
	printf("Enter the range\n");
	scanf("%d",&num);
	while(count<num)
	{
		count++;
		c=a+b;
		a=b;
		b=c;
		printf("The output:%d\n",c);
	}
}


