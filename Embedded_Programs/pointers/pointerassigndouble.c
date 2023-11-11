#include<stdio.h>
void func(int **pptr)
{
	(**pptr)++;
}
int main()
{
	int x=20;
	int *ptr=&x;
	printf("%p-----------%p\n",ptr,&ptr);
	func(&ptr);
	printf("%d\n",x);
	printf("%p-----------%p\n",ptr,&ptr);
}

