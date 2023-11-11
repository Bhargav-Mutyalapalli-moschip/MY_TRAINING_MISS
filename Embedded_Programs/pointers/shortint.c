#include<stdio.h>
int main()
{
	unsigned int a=0x31323334;
	char *ptr;
	ptr=(short int *)&a;
	printf("%x\n",*ptr);
	return 0;
}
