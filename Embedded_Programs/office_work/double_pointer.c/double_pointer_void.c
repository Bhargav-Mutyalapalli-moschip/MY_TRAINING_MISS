#include<stdio.h>
void scaninput(int **dptr,int n,int e);
int main()
{
	int i;
	int **dptr;
	dptr=(int**)malloc(2*sizeof(int*));
	if(dptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(1);
	}
	printf("-----------------------%p---------------%p\n--------------------",&dptr,dptr);
	for(i=0;i<2;i++)
	{
		printf("----------------%p-----------------%p\n",&dptr[i],dptr[i]);
		dptr[i]=(int *)malloc(3*sizeof(int));
		printf("----------------%p-----------------%p\n",&dptr[i],dptr[i]);
	}
	scaninput(dptr,2,3);
//	display(dptr,2,3);
	for(i=0;i<2;i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}
void scaninput(int **dptr,int n,int e)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<e;j++)
		{
			scanf("%d",&dptr[i][j]);
		//	printf("the output is ------------%d\n",dptr[i][j]);
		}
	}
}
