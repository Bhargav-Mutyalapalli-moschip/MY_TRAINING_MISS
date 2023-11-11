#include<stdio.h>
int main()
{
	unsigned int x;
	unsigned char n1,n2,temp;
	scanf("%x",&x);

	__fpurge(stdin);

	scanf("%d %d",&n1,&n2);
	(n1>n2) ? (temp=n2,n1=n2,n2=temp):0;
	x=((x&(1<<n1)|(1<<n2))==0)?(x&n2<<(n2-n1)) 
}
