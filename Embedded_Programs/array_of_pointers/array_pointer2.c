#include<stdio.h>
int main()
{
	int x[5]={10,20,30,40,50};
	int y[5]={1,2,3,4,5};
	int *aptr[2]={x,y};
	printf("%p----%p\n",aptr[0],aptr[1]);
	printf("%p----%p\n",x,y);
}

