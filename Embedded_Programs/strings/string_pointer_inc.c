#include<stdio.h>
int main()
{
	char str[]="Lucknow";
	int  *p;
	printf("%p",str);
	scanf("%p",p);
//	p=p+3;
//	p[3]='p';
	printf("%s-----------%d\n",str,*p);
}
