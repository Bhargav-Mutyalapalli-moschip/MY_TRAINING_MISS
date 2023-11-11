#include<stdio.h>
int main()
{
	int b,s=0,a[100];
	printf("ENTER THE VALUES");
	scanf("%d",&s);
	for(int i=0;s>0;i++)
	{
		a[i]=s%2;
		s=s/2;
	}
	for(int i=i-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}


}

