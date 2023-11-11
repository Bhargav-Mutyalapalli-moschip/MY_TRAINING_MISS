#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int main()
{
	int i;
	int *ptr;
	ptr=(int *)malloc(10*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(1);
	}
	printf("The address:%p\n",ptr);
	printf("The address:%p\n",(ptr+11));
	printf("The address:%p\n",(ptr+12));
}


