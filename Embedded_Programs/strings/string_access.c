#include<stdio.h>
int main()
{
	char str[20];
	func(str);
	//str=str+1;
	//str="ram";
	puts(str);
	func1(str);
	puts(str);
}
void func(char a[])
{
	a="pranav";
	puts(a);
}
void func1(char a[])
{
	a[0]='r';
	a[1]='a';
	a[2]='m';
}
