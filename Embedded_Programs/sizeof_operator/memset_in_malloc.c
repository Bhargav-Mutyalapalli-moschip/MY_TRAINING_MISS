#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	int *ptr;
	ptr=(int *)malloc(10*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	memset(ptr,0,10);
	for(i=0;i<10;i++)
	printf("The output:%d\n",ptr[i]);
}
	
