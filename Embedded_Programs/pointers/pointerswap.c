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
		*(ptr3+i)=*(ptr1+i);
	}
	for(i=0;i<3;i=i+2)
	{
		*(ptr3+i)=*(ptr2+i);
	}
	printf("%x   \n",z);
	printf("%x   \n",x);
	printf("%x   \n",y);

}

