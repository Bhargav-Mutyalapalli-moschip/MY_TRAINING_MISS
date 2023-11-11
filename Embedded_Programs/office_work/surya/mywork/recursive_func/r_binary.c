#include<stdio.h>
//int dec_binary(int var);
//int dec_binary(int var);
long int dec_binary(int var);

long int rem;
long int i=1;
long long int sum=0;
int main()
{
	long long int a,temp,num;
	scanf("%lld",&num);
	temp=num;
	a=dec_binary(temp);
	printf("The output%lld\n",a);
}
long int dec_binary(int var)
{
	if(var>0)
	{
		rem=var%2;
		var=var/2;
		sum=sum+rem*i;
		i=i*10;
		dec_binary(var);
	}
	return sum;
}
		
		
