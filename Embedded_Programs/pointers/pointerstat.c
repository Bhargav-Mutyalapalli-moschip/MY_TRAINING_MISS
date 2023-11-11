#include<stdio.h>
int main()
{
	unsigned int h,k,l,m,d;
	printf("%x ---- %x ----- %x---%x ----%x\n",&h,&k,&l,&m,&d);
	unsigned int *ptr=&h;
	int i,j,v,n,rem,sum,i1=1;
	scanf("%d",&n);
	__fpurge(stdin);
	printf("enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	
	}
	printf("enter values to perform:\n");
	for(i=0;i<n;i++)
	{
		sum=0;
		i1=1;
		while((*(ptr+i))!=0)
		{
			rem=(*(ptr+i))%2;
			sum=sum+(i1*rem);
			(*(ptr+i))=(*(ptr+i))/2;
			i1=i1*10;
		}
		printf("%d   ",sum);
	}
}
			

		

