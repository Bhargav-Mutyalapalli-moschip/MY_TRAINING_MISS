#include<stdio.h>
int main()
{
	int a,b,sum=0,temp,rem,i=1;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a,a=b,b=temp;
	while(b>=a)
	{
		sum=0;
		i=1;
		temp=a;
		while(temp!=0)
		{
			rem=temp%10;
			if(rem>1)
			{
				a++;
				break;
			}
			sum=sum+(rem*i);
			temp=temp/10;
			i=i*2;
		}
		if(rem>1)
		{
			a++;
			continue;
		}
		printf("%d  %d\n",a,sum);
		a++;
	}
}



