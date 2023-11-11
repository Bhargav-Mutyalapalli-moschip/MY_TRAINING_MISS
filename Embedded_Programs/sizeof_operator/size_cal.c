#include<stdio.h>
int main()
{
	int a=20;
	int *ptr1,*ptr2;
	ptr1=&a;
	ptr2=&a;
	ptr2++;
	printf("The last:%p---The first:%p\n",ptr2,ptr1);
	printf("The size is:%d\n",ptr2-ptr1);
}

