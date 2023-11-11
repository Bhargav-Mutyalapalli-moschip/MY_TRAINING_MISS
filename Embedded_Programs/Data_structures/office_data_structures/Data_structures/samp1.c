#include<stdio.h>
int main()
{
	int a=0xaabbccdd;
	char *cptr=&a;
	printf("%x",*cptr);
}
