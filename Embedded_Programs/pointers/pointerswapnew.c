#include<stdio.h>
int main()
{
	unsigned int x=0xaabbccdd;
	unsigned int y=0x11223344;
	unsigned int z;
	unsigned char *ptr1=&x;
	unsigned char *ptr2=&y;
	unsigned char *ptr3=&z;
	int i;
	for(i=1;i<4;i=i+2)
	{
		*(ptr3+i) = *(ptr1+i);

	printf("%x",*(ptr3+1));
	}
}



