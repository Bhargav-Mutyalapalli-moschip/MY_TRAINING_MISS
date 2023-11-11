#include<stdio.h>
int main()
{
	unsigned int x;
	unsigned char n1,n2,t0;
	scanf("%x",&x);
	printf("the values are ready to swap");
	__fpurge(stdin);
	scanf("%hhd %hhd",&n1,&n2);
	__fpurge(stdin);
	(n1>n2)? (t0=n1,n1=n2,n2=t0):0;
	x=(x& ~((0xf<<n1)|(0xf<<n2)))|((x&(0xf<<n1))<<(n2-n1))|((x&(0xf<<n2))>>(n2-n1));
	printf("the swapped numbers are%x\n",x);
}
