#include<stdio.h>
int main()
{
	int a,b,c,max;
	printf("enter the a and b value:");
	scanf("%d %d %d",&a,&b,&c);
	max=a>b>c ? a:b:c;
	printf("the max value is %d\n",max);
}
