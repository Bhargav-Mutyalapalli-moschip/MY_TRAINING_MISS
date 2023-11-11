#include<stdio.h>
int main()
{
	float sum=0,rem,powers=1,num;
	printf("Enter the value to check the binary\n");
	while(num!=0)
	{
		rem=num%10.0;
		num=num/10.0;
		sum=sum+(rem*powers);
		powers=powers*2;
	}
	printf("%f",sum);
}
