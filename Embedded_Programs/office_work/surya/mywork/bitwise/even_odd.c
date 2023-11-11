#include<stdio.h>
#define NUM 10
int main()
{
	int input,a,b,temp,i1=0,i2=0,i=0;
	int arr[NUM];
	printf("Give the range of a:is least range numbers\nb: is highest range number\n");
	scanf("%d%d",&a,&b);
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	temp=a;
	i2=NUM/2;
	printf("The temp:%d\n",i2);
	while(b>=temp)
	{
		if(temp%2==0)
		{
			arr[i1]=temp;
			i1++;
		}
		else
		{
			arr[i2]=temp;
			i2++;
		}
		temp++;
	}
	for(i=0;i<i2;i++)
	{
		printf("%d \n",arr[i]);
	}
}




	
