#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	(a>b)&&(a>c)&&(a>d) ? printf("%d",a) : ((b>c)&&(b>a)&&(b>d) ? printf("%d",b) : ((c>a)&&(c>b)&&(c>d) ? printf("%d",c) : printf("%d",d)));
}
