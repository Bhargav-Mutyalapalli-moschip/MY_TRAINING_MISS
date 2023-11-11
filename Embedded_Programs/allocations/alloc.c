#include<stdio.h>
#include<stdlib.h>
int main(int argc)
{
	int i;
	int *ptr;
	ptr=(int *)malloc(2*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed\n");
		exit(-1);
	}
	ptr=(int *)realloc(ptr,3*sizeof(int));
	if(ptr==NULL)
	{
		printf("failed\n");
	}
	for(i=0;i<15;i++)
	{
//	scanf("%d",&ptr[i]);
		__fpurge(stdin);
	printf("%d",ptr[i]);
	}
	printf("The Count:%d\n",argc);
	


}



