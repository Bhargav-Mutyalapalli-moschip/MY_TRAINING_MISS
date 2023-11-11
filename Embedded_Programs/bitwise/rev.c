#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int num=0xaabbccdd,rev=0,tet=0;
	int i,j=31;
	for(i=0;i<32;i++,j--)
	{
		tet=num&(0x1<<i);
		if(tet)
		rev=rev|0x1<<j;
	}
	printf("The out:%x\n",rev);
}

