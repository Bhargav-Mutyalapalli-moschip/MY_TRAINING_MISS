#include<stdio.h>
void func(char str[]);
int main()
{
	char str[10]="pranavram";
	func(str);
	printf("The Output: %s\n",str);
}
void func(char str[])
{
	char str2[20]="bhargav";
	str2=str2+2;
	str=str+6;
	printf("The :%s\n",str);
}
