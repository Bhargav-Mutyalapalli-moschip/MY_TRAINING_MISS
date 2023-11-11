#include<stdio.h>
int main()
{
	int x,i;
	int *ptr;
	ptr=(int *)calloc(1024*1024*1024,sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to allocate memory");
		exit(1);
	}
	*ptr=200;
	scanf("%d",&x);
}
