#include<stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)
main()
{
	int i=10,j=5,k=0;
	k=MAX(i++,++j);
	printf("Thei:%d\nThe j:%d\nZThe k:%d\n",i,j,k);
}

