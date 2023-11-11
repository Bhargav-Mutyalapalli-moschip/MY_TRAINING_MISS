#include<stdio.h>
void main()
{
	unsigned int x = 0xffaabbcc;
	char *y = &x;
	char z ;
	int i;
	int m = sizeof(int);
	for(i=1 ; i<=m ; i++,m--)
	{
		z = y[i];
		y[i] = y[m];
		y[m] = z;
	}
	printf("    ox%x\n",x);
}
