#include<stdio.h>
int main()
{
	unsigned int m;
	unsigned  a1,a2,temp;

	scanf("%d %d",&a1,&a2);
	__fpurge(stdin);
	scanf("%x",&m);
	//printf("%x",m);
	printf("enter the numnber to be swapped\n");
	(a1>a2) ? (temp=a1,a1=a2,a2=temp):0;
	m=(m &( ~((0x1<<a1)|(0x1<<a2)))|((m&(0x1<<a1))<<(a2-a1))|((m&(0x1<<a2))>>(a2-a1)));
	printf("%x\n",m);
}
