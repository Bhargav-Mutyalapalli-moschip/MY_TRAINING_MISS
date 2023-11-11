#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
extern struct node *head;
void push_operation(int num)
{
	int temp;
	struct node *ptr;
	ptr=(struct node *)malloc(1*(sizeof(struct node)));
	if(ptr==NULL)
	{

		printf("failed to allocate the memory in heap segment\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}


