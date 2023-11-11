#include<stdio.h>
int main()
{
	int x=20,y=85,a=98,i;
	int x1=10,*pp=&x1;
	printf("the data at at that address:%d---------The address stored in pointer(pp)-%p-----------The address for pointer pp-%p\n\n\n",*pp,pp,&pp);
	int *ptr[3];
	ptr[2]=&a;
	ptr[1]=&y;
	ptr[0]=&x;
	printf("Size of array of pointer--------%d\n\n\n\n",sizeof(ptr));
	for(i=0;i<3;i++)
	{
		printf("Pointer base address:---%p--------address stored in that pointer:--%p\n",&ptr[i],(ptr+i));
		printf("-------------------%d\n",*(*ptr+i));

	}
}


