#include<stdio.h>
#include "header.h"
extern struct node *head;
int search_stack(int num)
{
	int pos=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
	return 0;
}
