#include<stdio.h>
int main()

{
	unsigned int a=0x11223344;
	unsigned char b, y=a;
	a=(a&~(0xff<<0)|(0xff<<16))|((a&(0xff<<0))<<(16-0))|((a&(0xff<<16))>>(16-0));
	b=a;
	printf("0x%x",y);
	


	printf("%x",b);
}


