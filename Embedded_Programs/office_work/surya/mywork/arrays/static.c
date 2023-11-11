#include<stdio.h>
int main()
{
	int x=10;
	static int fg=25;
	fg=fg+x;
	printf("%d",fg);
}
