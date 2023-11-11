#include<stdio.h>
int main()
{
	unsigned int x=0xAABBCCDD;
	unsigned int y=0;
	y=(char)x;
	printf("%x",x);
}

