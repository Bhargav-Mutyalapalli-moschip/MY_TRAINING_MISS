#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count1=0;
int search_count=0;
int duplicate1=0;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void add_at_begin(int num);
void delete_at_begin();
void display();
void add_at_last(int num);
void delete_at_last();
void duplicates();
int search(int num);
void count();
void reverse();
void swap_link(int num1,int num2);
void add_after_node(int num,int var);
void add_before_node(int num,int var);
void delete_particular(int num);
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.ADD at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.count the nodes\n\n5.search the nodes\n\n6.Duplicates\n\n7.Delete at last\n\n8.Count the nodes\n\n11.Reverse\n\n12.Selection sort\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				add_at_begin(data_value);
				break;

			case 2:
				printf("delete at begin\n");
				delete_at_begin();
				break;

			case 3:
				printf("display the nodes\n");
				display();
				break;

			case 4:
				
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				add_at_last(data_value);
				break;

			case 5:
				printf("Delete at last \n");
				delete_at_last();
				break;

			case 6:
				printf("Duplicates\n");
				duplicates();
				break;

			case 7:
				printf("Search operation\n");
				scanf("%d",&num);
				pos=search(num);
				if(pos>0)
				{
					printf("Element found on %d position\n",pos);
				}
				else if(pos==0)
					printf("Elements is not found\n");

				break;

			case 8:
				printf("Count the nodes\n");
				count();
				break;

			case 9:
				printf("reverse the list\n");
				reverse();
				break;

			case 10:
				printf("Swap by link\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

			case 11:
				printf("Add after a node\n");
				scanf("%d%d",&num,&var);
				add_after_node(num,var);
				break;

			case 12:

				printf("Add after a node\n");
				scanf("%d%d",&num,&var);
				add_before_node(num,var);
				break;

			case 13:
				printf("Delete particular node\n");
				scanf("%d",&num);
				delete_particular(num);
				break;

			



		}
	}
}
void add_at_begin(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	ptr->next=head;
	ptr->prev=NULL;
	head->prev=ptr;
	head=ptr;
	return;
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
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}
void add_at_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("List is empty\n");
		exit(-1);
	}
	if(head==NULL)
	{
		ptr->data=num;
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->data=num;
	ptr->prev=temp;
	ptr->next=NULL;
	temp->next=ptr;
	return;
}
void delete_at_last()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
void duplicates()
{
	struct node *p,*s,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		printf("It has single elements\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(s=p,q=p->next;q!=NULL;s=q,q=q->next)
		{
			if(p->data==q->data)
			{
				s->next=q->next;
				if(q->next!=NULL)
				q->next->prev=q->prev;
				free(q);
				q=s;
			}
		}
	}
}
int search(int num)
{
	int pos=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	temp=head;
	while(temp!=NULL)
	{
		pos++;

		if(temp->data==num)
			return pos;
		temp=temp->next;

	}
	return 0;
}
void count()
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
		count1++;
		temp=temp->next;
	}
	printf("The number of nodes are present is:%d\n",count1);
	count1=0;
}
void reverse()
{
	struct node *next,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	return;
	p=head;
	while(p!=NULL)
	{
		next=p->next;
		p->next=p->prev;
		p->prev=next;
		if(p->prev==NULL)
		head=p;
		p=next;
	}
	
}
void swap_link(int num1,int num2)
{
	int pos1=0,pos2=0;
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2)
	return;
	if(head->next==NULL)
	return;
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num1)
		break;
		p=p->next;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)
		break;
		q=q->next;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p==NULL || q==NULL)
	{
		printf("Elemenets are not found\n");
		return;
	}
	if(p->next!=q)
	{
		temp=p->next;
		p->next=q->next;
		q->next=temp;
		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;
		if(p!=head)
		{

			q->prev->next=q;
			if(p->next!=NULL)
			q->next->prev=q;
			q->next->next=p;
		}

		else
		{
			head=q;
		q->next->prev=q;
		p->prev->next=p;
		p->next->prev=p;
		}
	}
}

void add_after_node(int num,int var)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			ptr->data=var;
			ptr->next=NULL;
			ptr->prev=head;
			head->next=ptr;
			return;
		}
		ptr->data=var;
		ptr->next=head->next;
		head->next->prev=ptr;
		ptr->prev=head;
		head->next=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
			break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Elements not found\n");
		return;
	}
	ptr->data=var;
	ptr->next=temp->next;
	if(temp->next!=NULL)
	temp->next->prev=ptr;
	temp->next=ptr;
	ptr->prev=temp;
	

}
void add_before_node(int num,int var)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			ptr->data=var;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
			return;
		}
		ptr->data=var;
		ptr->prev=NULL;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		return;
	}
	temp=head->next;
	while(temp!=NULL)
	{
		if(temp->data==num)
		break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Elements not found\n");
		return;
	}
	ptr->data=var;
	ptr->next=temp;
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
	if(temp->prev!=NULL)
	temp->prev=ptr;
}
void delete_particular(int num)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		temp=head;
		head=head->next;
		head->next->prev=NULL;
		free(temp);
	}
}










