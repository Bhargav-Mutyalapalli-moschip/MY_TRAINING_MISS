#include<stdio.h>
int main()
{
	int a,b,temp,count =0,n;
	scanf("%d %d",&a,&b);
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(b>=a)
	{
		//printf("%d\n",a);
		count =0;
		n=a;
		while(n>0)
		{
			n=n/10;
			count++;
		}
		printf("%d-%d\n",a,count);
		a++;

	}	

	
        	
	
	
}
