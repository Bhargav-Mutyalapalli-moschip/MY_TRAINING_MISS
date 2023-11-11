#include<stdio.h>
int main()
{
	unsigned int h=0x11223344,j;
	int i;
	unsigned int count=0,count2=0;
	for(i=31;i>=0;i--)
	{
		if(((h&(0x1)<<i)>>i)==0)
			printf("0");
		else
			printf("1");
		
		
		
		//h=h>>i;
	}
	
}
