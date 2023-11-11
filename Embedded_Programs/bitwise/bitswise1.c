#include<stdio.h>
int main()
{
	unsigned int x=0x11223344,x1,x2;
	x1=(x&~((0xff<<0)|(0xff<<16)))|((x&(0xff<<0))<<(16-0))|((x&(0xff<<16))>>(16-0));
	x2=(x1&~((0xff<<8)|(0xff<<16)))|((x1&(0xff<<8))<<(16-8))|((x1&(0xff<<16))>>(16-8));
	unsigned short int b=x2;

	printf("%x\n",x);
	printf("%x",b);
}
