#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int *ptr;
	ptr=(int *)malloc(10*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed allocate the  memory in heap segment\n");
		exit(-1);
	}
	memset(ptr,-1,40);
	for(i=0;i<10;i++)
	printf("The output:0x%x\n",ptr[i]);
}

