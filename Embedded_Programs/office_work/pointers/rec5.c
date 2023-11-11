#include<stdio.h>
int main()
{
	unsigned int c= 0x41424344;
	unsigned short int *ptr=&c;
	unsigned char *ptr2=&c;
	unsigned char *ptr3=(char*)&c;

	++*ptr;
	++*ptr2;
	printf("%c\n",*ptr);
	printf("%p\n",ptr);
	printf("%c\n",*ptr2);
	printf("%p\n",ptr2);
	*ptr++;
	*ptr2++;
	printf("%c\n",*ptr);
	printf("%p\n",ptr);
	printf("%c\n",*ptr2);
	printf("%p\n",ptr2);

}

