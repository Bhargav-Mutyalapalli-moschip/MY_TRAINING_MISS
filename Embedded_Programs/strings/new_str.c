#include<stdio.h>
int main()
{
	char *str="tap";
	func(str);
	return 0;
}
void func(char *p)
{
	if(*p)
	{
		func(++p);
		printf("%c\n",*p++);
	}
}

