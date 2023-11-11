#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void add_before_data(int num,int var)
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("Stack is empty\n");
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
			ptr->data=var;
			ptr->link=head;
			head=ptr;
			return;
		}
		else
		{
			ptr->data=var;
			ptr->link=head;
			head=ptr;
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
	ptr->data=var;
	ptr->link=prev->link;
	prev->link=ptr;
}
