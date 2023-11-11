#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void create_stack(int *iptr,int num)
{
	struct node *temp;
	struct node *ptr;
	int i;
	for(i=0;i<num;i++)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(1);
		}
		ptr->data=iptr[i];
		ptr->link=head;
		head=ptr;
	}
}
