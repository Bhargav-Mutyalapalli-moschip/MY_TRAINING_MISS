#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void delete_stack()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp=head;
	while(head!=NULL)
	{
		temp=head;
		head=head->link;
		free(temp);
	}
}
