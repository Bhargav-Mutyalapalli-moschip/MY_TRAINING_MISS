#include<stdio.h>
int main()
{
	char *ptr;
	ptr="my name is %s and my age is %d\n";
	printf(ptr,"pranav",22);
	ptr[0]='o';
}
