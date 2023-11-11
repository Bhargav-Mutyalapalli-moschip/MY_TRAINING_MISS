#include<stdio.h>
int main()
{
	int x=5;
	int y=10;
	int z=0;
	z=(x,printf("%d\n",z));
	z=(y=25,printf("%d\n",z));
	z=(z=453,printf("%d\n",z));
	z=(x+y+z,printf("%d",z));
	printf("%d",z);

}
