#include<stdio.h>
int main()
{
	unsigned int g=0x11223344,k;
	k=g>>28;
	unsigned char j=k;

	printf("%x",j);
}
