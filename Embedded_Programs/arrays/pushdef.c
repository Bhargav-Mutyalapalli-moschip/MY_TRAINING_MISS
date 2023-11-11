#include<stdio.h>
void push(int *ptr,int var)
{
	int j;
	if(rearind==4)
	{
		printf("queue is full\n");
		return;
	}
	rearind++;
	ptr[rearind]=var;
	frontind++;
	for(j=0;j<5;j++)
	{
		printf("%d",ptr[i]);
	}
}


