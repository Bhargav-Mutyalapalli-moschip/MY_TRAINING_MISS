#include<stdio.h>
int main()
{
	int x=20;
	int y;
	y=x++ + ++x;
	printf("%d",y);
}
