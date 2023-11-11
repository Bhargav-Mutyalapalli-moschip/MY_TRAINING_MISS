#include<stdio.h>
int main()
{
	int i;
	int **dptr;
	dptr=(int**)calloc(1024*1024*1024*1024,sizeof(int*));
	if(dptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(1);
	}
	printf("-----------------------%p---------------%p\n--------------------",&dptr,dptr);
	for(i=0;i<2;i++)
	{
		printf("----------------%p-----------------%p\n",&dptr[i],dptr[i]);
	}
	scanf("%d",&i);
}
