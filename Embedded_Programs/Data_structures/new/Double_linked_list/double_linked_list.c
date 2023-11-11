#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void add_at_begin(int num);
void display();
void reverse();
void delete_list();
void swap_link(int num,int var);
struct node *head=NULL;
int main()
{
	int prog,num,var;
	while(1)
	{
		printf(">>>>>>>>Double linked list<<<<<<<<\n");
		printf("1.Add at begin\n2.Display\n3.Reverse the list\n4.Delete the list\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);

			case 1:
				printf("Add at begin\n");
				printf("Enter the data\n");
				scanf("%d",&num);
				add_at_begin(num);
				break;

			case 2:
				printf("Displaying.......\n");
				display();
				break;

			case 3:
				printf("Reverse the list \n");
				reverse();
				break;

			case 4:
				printf("Delete the list\n");
				delete_list();
				break;

			case 5:
				printf("Swap operation\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

		}
	}
}
void add_at_begin(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->prev=NULL;
	ptr->next=head;
	if(head!=NULL)
	{
		head->prev=ptr;
	}
	head=ptr;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The output:%d\n",temp->data);
		temp=temp->next;
	}
}
void reverse()
{
	struct node *p1,*c1,*next1,*next2;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(-1);
	}
	if(head->next==NULL)
	return;
	p1=NULL;
	c1=head;
	while(c1!=NULL)

	{
		next1=c1->next;
		c1->next=p1;
		c1->prev=c1->next;
		p1=c1;
		c1=next1;
	}
	head=p1;
}
void swap_link(int num,int var)
{
	int pos1=0,pos2=0;
	struct node *temp,*p,*q;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	return;
	if(num==var)
	return;
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
		break;
		p=p->next;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==var)
		break;
		q=q->next;
	}
	if(p==NULL || q==NULL)
	{
		printf("Elemenets not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	printf("Pos1:%d\nPos2:%d\n",pos1,pos2);
	if(p->next!=q)
	{
		temp=p->next;
		p->next=q->next;
		q->next=temp;
		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;
		if(p!=head)
		p->next->prev=q;
		else
			head=q;
		q->prev->next=p;
	}



}
void delete_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		temp=head;
		head=head->next;
		if(temp->next!=NULL)
		temp->next->prev=NULL;
		free(temp);
		temp=head;
	}
}

	





