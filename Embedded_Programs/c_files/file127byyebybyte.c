#include<stdio.h>
int main()
{
	unsigned int a=0xffaabb5d;
	((a&(1<<3))==0)?printf("0"):printf("1");
	((a&(1<<7))==0)?printf("0"):printf("1");
}

