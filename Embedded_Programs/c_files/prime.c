#include<stdio.h>
int main()
{
	int a,b,temp,count=0,i=0;
	printf("Enter the value to check the number: ");
	scanf("%d %d",&a,&b);
	if(a>b){
	temp=a;
	a=b;
	b=temp;
	}
	printf("%d %d\n",a,b);
prime:	if(b>=a)
	{
		count=0;
		i=0;
		temp=a;
	prime1	:i++;
		if(b>=i)
		{
			if(temp%i==0)
			count++;
			goto prime1;

		}
		if(count==2)
		{
			printf("%d\n",a);
			a++;
			goto prime;
		}
		else
			a++;
			goto prime;
		
	}
}
