#include<stdio.h>
struct node
{
	int a;
};
int main()
{
	struct node k;
	void *ptr;
	ptr=(int *)malloc(1*sizeof(int));
	k.a=20;
	*(int *)ptr=k.a;
	printf("The dma:%d----The normal:%d\n",*(int *)ptr,k.a);
}

