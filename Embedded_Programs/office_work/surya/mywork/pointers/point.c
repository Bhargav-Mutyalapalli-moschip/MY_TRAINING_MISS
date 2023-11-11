#include<stdio.h>
int main()
{
	int x=320;
	char *ptr=(char *)&x;
	printf("%d",*ptr);
}
