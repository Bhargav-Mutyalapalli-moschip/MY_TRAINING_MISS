#include<stdio.h>
int main()
{
	unsigned char x='A';
	 
	unsigned int y=0x31323334;
	unsigned int *iptr;
	unsigned char *cptr;
	iptr=&x;
	cptr=&y;
	printf("%x\n",*iptr);
	printf("%c\n",*cptr);
}
