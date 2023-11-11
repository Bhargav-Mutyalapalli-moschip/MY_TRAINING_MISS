#include<stdio.h>
int main()
{
	//float rem,sum=0,power=1,num;
	printf("Enter the value\n");
	//scanf("%f",&num);

	int i;
	float num=123.456;
	int *ptr=&num;
	for(i=31;i>=0;i--)
	{
		if((*ptr&(0x1<<i))==0)
			printf("0");
		else
			printf("1");
	}
}

