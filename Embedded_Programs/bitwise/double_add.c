#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count=0;
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
void count_nodes();
int search_nodes(int num);
void add_at_last(int num);
void delete_at_last();
void add_after_node(int num,int var);
void add_before_node(int num,int var);
void delete_particular_node(int num);
void reverse_list();
void create_list(int *iptr,int num);
void swap_data(int num1,int num2);
void selection_sort();
void duplicates();
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.ADD at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.count the nodes\n\n5.search the nodes\n\n6.Duplicates\n\n7.Delete at last\n\n11.Reverse\n\n12.Selection sort\n\n");
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



