#include<stdio.h>
struct data
{
	int infor;
	struct data *ptr;
};
int main()
{
	struct data ptr1;
	ptr1.infor=10;
	ptr1.ptr=NULL;
	struct data ptr2;
	ptr2.infor=20;
	ptr2.ptr=NULL;
	ptr1.ptr=&ptr2;
	printf ("%d \n", ptr1.infor);
	printf ("%d \n", ptr1.ptr->infor);
}



