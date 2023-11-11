#include<stdio.h>
int main()
{
	int x=650;
	int y=69;
	int z=456;
	int *ptr=&x;
	y=*ptr;
	*ptr=z;;
	printf("%d-------%d\n",x,y);
}
