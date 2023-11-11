#include<stdio.h>
int main()
{
	unsigned int v;
	unsigned char c,c1,c2,c3;
	scanf("%x",&v);
	printf("%x\n",c=v);
	c1=(v>>8);
	printf("%x\n",c1);
	c2=(v>>16);
	printf("%x\n",c2);
	c3=(v>>24);
	printf("%x\n",c3);
}
