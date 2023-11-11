#include<stdio.h>
int main()
{
	int rem,sum=0,temp,num,i=1,j,n=10,m=20;
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%16;
		sum=sum+(rem*i);
		temp=temp/16;
		i=i*10;

	}
	for(i=97;i<=102;i++)
	{
		if(sum==n){
			n++;
			printf("%c\n",i);
		}
		else if(sum>=20&&sum<=29){
			m++;
			continue;
		
		}
	}

}
