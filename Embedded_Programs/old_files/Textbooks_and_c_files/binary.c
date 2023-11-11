#include<stdio.h>
int main()
{
	int sum=0,i=1,num,rem;
	scanf("%d",&num);
	while(num!=0)
	{
		rem=num%10;
		if(rem > 1)
		continue;
		sum=sum+i*rem;
		num=num/10;
		i=i*2;
	}
	printf("The sum is:%d\n",sum);
}


