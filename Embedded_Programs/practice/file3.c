#include<stdio.h>
int main()
{
	int x=10;
	int y=25;
	int z;
	z=(x,printf("%d\n",z),y=55,printf("%d\n",z),z=45,printf("%d\n",z),x+y+z,printf("%d\n",z));
	printf("%d",z);
}
