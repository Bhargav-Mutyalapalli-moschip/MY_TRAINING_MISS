#include<stdio.h>
int main()
{
	int *ptr1=0x500400;
	int *ptr2=0x500800;
	printf("%p",(ptr2-ptr1));
}
