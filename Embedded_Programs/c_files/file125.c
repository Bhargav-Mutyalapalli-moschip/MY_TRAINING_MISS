#include<stdio.h>
int main()
{
	unsigned char x=0xf9;
	x=x|(0x3<<1);
	printf("%x",x);
}
