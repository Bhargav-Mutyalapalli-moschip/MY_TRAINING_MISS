#include<stdio.h>
int main()
{
	int a,b,temp,sum=0,i=1,rem;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a,a=b,b=temp;
	while(b>=a)
	{
		sum=0;
		i=1;
		temp=a;
		

		while(temp<=b)
		{
			rem=temp%10;
			if(rem>2)
			{
				printf("Invalid input");
				a++;
				break;
			}
			while(temp<2){



			        sum=sum+temp*i;
			        temp=temp/10;
			        i=i*2;
			}
		}
		printf("%d-%d\n",a,sum);
		a++;
	}
}




