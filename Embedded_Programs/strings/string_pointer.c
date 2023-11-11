#include<stdio.h>
int main()
{
	char *p="Pranav";
	char str[]="RAMPRANAV";
	//*(p+2)='b';
	str[2]='b';
	puts(p);
	puts(str);
	return 0;
}
