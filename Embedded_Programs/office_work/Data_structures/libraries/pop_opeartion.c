#include "stack.h"
void pop_operation()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	head=temp->link;
	free(temp);
}
