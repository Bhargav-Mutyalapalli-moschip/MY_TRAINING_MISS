#include<stdio.h>
int x;
int x=20;
int main()
{
	x=40;
	int x=50;
	
	
	{
		int x=90;
		printf("%d\n",x);
	}

	printf("%d",x);
}
