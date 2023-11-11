#include<stdio.h>
void main()
{
	int status = 0xaabbccdd;

	printf("lower order: 0x%x",(((status) & 0xff00) >> 8));
}

