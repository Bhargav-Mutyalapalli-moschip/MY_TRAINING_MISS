#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void delete_particular_stack(int num)
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	ptr=(struct  node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			temp=head;
			head=head->link;
			free(temp);
			return;
		}
		else
		{
			temp=head;
			head=head->link;
			free(temp);
			return;
		}
	}
	prev=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		break;
		prev=current;
		current=current->link;
	}
	prev->link=current->link;
	free(current);
}

