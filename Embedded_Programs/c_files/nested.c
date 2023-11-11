#include<stdio.h>
int main()
{
	int a,b,sum=0,temp,rem;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a,a=b,b=temp;
	
	do{
		if(a>10){

			sum=0;
			temp=a;
			do{
				rem=temp%10;
				sum=(sum*10)+rem;
				temp=temp/10;

			}
			while(temp!=0);

			if(sum==a)
				printf("%d\n",sum);
			a++;
		}
		else
			a++;

	}

	while(b>=a);


}



