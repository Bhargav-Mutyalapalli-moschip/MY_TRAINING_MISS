#include<stdio.h>
#include<stdlib.h>
#include "header.h"
int count=0;
extern struct node *head;
void count_stack()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	printf("The count is:%d\n",count);
	count=0;
}
