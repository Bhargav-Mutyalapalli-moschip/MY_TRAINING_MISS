#include<stdio.h>
int main()
{
	char d;
	scanf("%c",&d);
	(d>=65)&&(d<=90) ? printf("Upper case"):((d>=97)&&(d<=120) ? printf("LOwer case"):printf("not a character"));
}
