#include<stdio.h>
int main()
{
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int ret;
	ret=((short int*)&ptr[2]-(short int*)&ptr[0]);
	printf("%d\n",ret);
}
