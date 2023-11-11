#include<stdio.h>
int main()
{
	int sum=0,temp,rem,num,a,b,i=1;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a;a=b;b=temp;
decimal:sum=0;
	temp=a;
	i=1;
	rem=temp%10;
	if(rem>1)
	{
		goto binary;
	}
	sum=sum+(rem*i);
	temp=temp/10;
	i=i*2;
		
	 binary:if(rem>1)
		{
			a++;
			goto decimal;
		}
		printf("%d-----%d\n",a,sum);
		a++;
	
}
	
