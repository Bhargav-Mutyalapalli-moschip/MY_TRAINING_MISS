#include<stdio.h>
int main()
{
	int a,i,count=0;
	unsigned int g=0xff,h;
	for(i=0;i<=(32-4);i++)
	{
		if(((g&(0xf<<i))>>i)==(0xf))
			count++;
	}
	printf("%d",count);
}

