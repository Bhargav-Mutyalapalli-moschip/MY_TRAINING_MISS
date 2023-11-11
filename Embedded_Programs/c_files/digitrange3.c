
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
		if(b!=0)
		{
			count =0;
			n=b;
			while(n!=0)
			{
				n=n/10;
				count++;
			}
			printf("%d-%d\n",b,count);
			b--;
		}
		else{

			count++;
		        printf("%d-%d\n",b,count);
			b--;
		}

	}	

	
        	
	
	
}
