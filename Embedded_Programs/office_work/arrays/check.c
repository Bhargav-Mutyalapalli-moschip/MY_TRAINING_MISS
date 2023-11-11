#include<stdio.h>
int main()
{
	int x=10;
	int *y=&x;
	printf("size of x= %p\n",y);
	printf("size of x= %p\n",y++);
	//printf("the value is %d\n",*y);
	printf("size of x= %p\n",++y);
	//printf("the value in:%d\n",*y);
	printf("size of x= %p\n",y);
	printf("size of x= %p\n",--y);
	printf("size of x= %p\n",y--);

	printf("size of x= %p\n",y);
}
