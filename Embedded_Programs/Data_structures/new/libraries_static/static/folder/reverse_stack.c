#include<stdio.h>
#include "header.h"
extern struct node *head;
void reverse_stack()
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	if(head->link==NULL)
	return;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		temp=current->link;
		current->link=prev;
		prev=current;
		current=temp;
	}
	head=prev;
}
