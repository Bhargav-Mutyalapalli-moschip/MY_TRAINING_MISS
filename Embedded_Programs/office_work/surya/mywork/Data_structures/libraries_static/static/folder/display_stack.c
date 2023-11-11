#include<stdio.h>
#include "header.h"
#include<stdlib.h>
extern struct node *head;
void display_stack()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The stack data:%d\n",temp->data);
		temp=temp->link;
	}
}

