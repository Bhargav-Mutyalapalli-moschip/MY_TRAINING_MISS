#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr;
	char *c;
	*(ptr)=25;
	*c=*ptr;
	printf("%c\n",*c);
}


