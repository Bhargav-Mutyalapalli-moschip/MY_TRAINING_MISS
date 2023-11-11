#include<stdio.h>
int main()
{
	long int num,sum=0,rem;
	printf("Enter the number to check the number is perfect or not\n");
	scanf("%ld",&num);
	long int k=1;
	while(k<num)
	{
		if(num%k==0)
		{
			sum=sum+k;
		}
		k++;
	}
	if(sum==num)
	{
		printf("The number(%ld)is perfect\n",sum);
	}
	else
		printf("It is not perfect number\n");
}
		

