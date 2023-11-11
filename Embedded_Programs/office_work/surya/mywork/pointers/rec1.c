#include<stdio.h>
int f(int x)
{
	if(x<=4)
		return x;
	else
		return(x+f(--x));
}
int main()
{
	int h;
	h=f(7);
	printf("%d",h);
}
