#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void swap_data(int num1,int num2)
{
	int temp;
	struct node *pointer1,*pointer2;
	if(head==NULL)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	if(head->link==NULL)
	return;
	if(num1==num2)
	return;
	pointer1=pointer2=head;
	while(pointer1!=NULL)
	{
		if(pointer1->data==num1)
			break;
		pointer1=pointer1->link;
	}
	while(pointer2!=NULL)
	{
		if(pointer2->data==num2)
			break;
		pointer2=pointer2->link;
	}
	if(pointer1==NULL || pointer2==NULL)
	{
		printf("Elements is not found\n");
		return;
	}
	temp=pointer1->data;
	pointer1->data=pointer2->data;
	pointer2->data=temp;
	return;
}

