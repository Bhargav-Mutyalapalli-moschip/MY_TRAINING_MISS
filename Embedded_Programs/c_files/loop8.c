#include<stdio.h>
int main()
{
	int a,i,count=0;
	unsigned int g=0x55555555,h;
	for(i=0;i<=(32-3);i++)
	{
		if((g&(0x7)<<0)==(0x5))
		{
			h=h | (g|(0x7<<0));
		}
		
	g=g>>1;
	}
	printf("%x",h);

	g=(h&~(0xffffffff<<0));
}

