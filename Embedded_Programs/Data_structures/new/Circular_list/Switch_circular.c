#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void add_at_begin(int num);
void display();
void delete_at_begin();
void create_list(int *iptr,int n);
void reverse();
int main()
{
	int prog,num,*ptr,i;
	while(1)
	{
		printf("----------------------------Circular list----------------\n");
		printf("0.Exit the program\n1.Add at beginning\n2.Display\n3.Delete at begin\n4.Create the list\n5.Reverse the list\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Succesfull termination of program\n");
				exit(0);

			case 1:
				printf("Add at begin\n");
				printf("Enter the to be add--:\n");
				scanf("%d",&num);
				add_at_begin(num);
				break;

			case 2:
				printf("The display\n");
				display();
				break;

			case 3:
				printf("Delete_at_begin\n");
				delete_at_begin();
				break;

			case 4:
				printf("Create the list\n");
				ptr=(int *)malloc(sizeof(int));
				if(ptr==NULL)
				{
					printf("failed to allocate the memory in heap segment\n");
					exit(-1);
				}
				printf("Enter the size of the array\n");
				scanf("%d",&num);
				for(i=0;i<num;i++)
				{
					__fpurge(stdin);
					printf("Enter the %d data\n",i);
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,num);
				free(ptr);
				break;

			case 5:
				printf("Reverse the list\n");
				reverse();
				break;


		}
	}
}
void add_at_begin(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		ptr->data=num;
		ptr->link=head=ptr;
		return;
	}
	ptr->data=num;
	ptr->link=head;
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=head=ptr;
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
	while(temp->link!=head)	
	{
		printf("The data:%d\n",temp->data);
		temp=temp->link;
	}
	printf("The data:%d\n",temp->data);
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
        temp->link=head->link;
        free(head);	
	head=temp->link;
}
void create_list(int *iptr,int n)
{
	int i;
	struct node *temp,*ptr;
	for(i=0;i<n;i++)
	{
		temp=head;
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		if(head==NULL)
		{
			head=ptr->link=ptr;
		}
		else
		{
			while(temp->link!=head)
			{
				temp=temp->link;
			}
			if(temp->link==head)
			{
				temp->link=ptr;
				ptr->link=head;
			}

		}
	}
}
void add_at_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
}
void reverse()
{
	struct node *next,*cur,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=head;
	cur=head;
	while(cur->link!=head)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	next=cur->link;
	cur->link=prev;
	prev=cur;
	cur=next;
	head=prev;
}






		













