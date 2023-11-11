#include<stdio.h>
int main()
{
	int x=20;
	int z=64;
	int y=40;
	int *ptr[2];
//	ptr=(int*)malloc(3*sizeof(int));
	printf("%p--------------%p------------%p\n",&x,&z,&y);
//
	ptr[0]=&x;
	ptr[1]=&y;
	
	printf("%p--------------%p------------%p\n",&x,&z,&y);
	printf("%d\n",ptr[0][1]);

}
