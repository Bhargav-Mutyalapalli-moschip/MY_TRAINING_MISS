#include<stdio.h>
int main()
{
	int a,b,sum=0,temp,check,rem;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a,a=b,b=temp;
	while(b>=a)
	{
		sum=0;
		temp=a;
		while(temp!=0)
		{
			rem=temp%10;
			sum=(sum*10)+rem;
			temp=temp/10;
		}
		check=sum;
		if((check%2!=0)&&(sum==a))
		{
			printf("even pal:%d\n",check);
		}
		a++;
	}
}

