#include<stdio.h>
int main()
{
	unsigned char x=0x00;
	x=x^(0x7>>7);
	printf("%x",x);
}
