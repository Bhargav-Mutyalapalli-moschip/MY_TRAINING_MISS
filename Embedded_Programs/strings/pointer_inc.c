#include<stdio.h>
int main()
{
	char str[]="painstaking";
	char *p=str+5;
	printf("%c\t",*p);
	printf("%s\t",p);
}

