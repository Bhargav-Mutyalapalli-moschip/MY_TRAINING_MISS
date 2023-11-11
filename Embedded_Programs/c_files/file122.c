#include<stdio.h>
int main()
{
	unsigned char x=0xff;
	x=x&(~(0x1<<5));
	x=x&(~(0x1<<3));
	printf("%x",x);
}
