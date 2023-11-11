#include<stdio.h>
int main()
{
	unsigned int x;
	unsigned char y=0,y1,y2,y3;
	scanf("%x",&x);
	y=x;
	printf("%x\n",y);
	y1=(x>>8);
	printf("%x\n",y1);
	y2=(x>>16);
	printf("%x\n",y2);
	y3=(x>>24);
	printf("%x",y3);



}
