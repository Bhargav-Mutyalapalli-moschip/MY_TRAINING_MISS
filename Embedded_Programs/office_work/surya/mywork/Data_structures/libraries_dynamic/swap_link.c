#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct node *head;
void swap_link(int num,int val)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(num==val)
	{
		return;
	}
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
		{
			break;
		}
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==val)
		{
			break;
		}
		s=q;
		q=q->link;
	}
	if(p==NULL||q==NULL)
	{
		printf("Element not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;

		if(p==head)
		{
			head=q;
		}
		else
			r->link=q;
		s->link=p;
		return;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p==head)
		{
			head=q;
		}
		else
			r->link=q;
		return;
	}
}
