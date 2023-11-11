#include<stdio.h>
int main()
{
	unsigned int x;
	unsigned int mask=0x1;
	scanf("%d",&x);

	if((mask&x)==0)
	printf("even");
	else
		printf("odd");
}
