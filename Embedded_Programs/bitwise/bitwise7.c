#include<stdio.h>
int main()
{
	unsigned int x=0x55555555,l,x1;
	int i;
	for(i=0;i<32-3;i++)
	{
		if((x&(0x7))==(0x5)){
		l=((x&(0x5))|(0x7));
		}
	

		
		x=x>>1;
	}
	printf("%d",l);
}
