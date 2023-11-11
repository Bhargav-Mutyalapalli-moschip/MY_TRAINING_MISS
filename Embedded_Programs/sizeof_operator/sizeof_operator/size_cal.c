#include<stdio.h>
int main()
{
	char a=20;
	char *ptr1,*ptr2;
	ptr1=&a;
	ptr2=&a;
	ptr2++;
	printf("The last:%p---The first:%p\n",ptr2,ptr1);
	printf("The size is:%ld\n",(ptr2-ptr1)*4);
}

