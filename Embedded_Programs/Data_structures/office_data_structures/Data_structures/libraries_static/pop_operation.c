#include "header.h"
#include<stdlib.h>
#include<stdio.h>
extern struct node *head;
void pop_operation()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	temp=head;
	head=temp->link;
	free(temp);
}
