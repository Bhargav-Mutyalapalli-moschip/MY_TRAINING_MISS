#include<stdio.h>
int main()
{
	int a,b,n,lim=0,y;
	printf("enter the values: ");
	scanf("%d %d",&a,&b);
	__fpurge(stdin);
	scanf("%d",&n);
	y=a+b;
	while(n>=0)
	{
		lim=lim+(a+b);
		printf("%d\n",lim);
		n--;
	}
}	

