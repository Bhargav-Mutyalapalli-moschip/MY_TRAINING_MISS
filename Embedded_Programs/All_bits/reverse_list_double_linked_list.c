#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void insert_element(int val);
void display();
struct node *head=NULL;
int main()
{
	int prog,num;
	while(1)
	{
		printf("1.insert\n2.display\n3.reverse\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 1:
				printf(">>>>insert<<<\n");
				scanf("%d",&num);
				__fpurge(stdin);
				insert_element(num);
				break;

			case 2:
				printf(">>>>display<<<\n");
				display();
				break;

			case 3:
				printf(">>reverse<<<\n");
				//reverse_list();
				break;

		}
	}
}
void insert_element(int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(1);
	}
	ptr->next=NULL;
	ptr->data=val;
	if(head==NULL)
	{
		ptr->prev=NULL;
		head=ptr;
	}
	else
	{
	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(1);
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The data:%d\n",temp->data);
		temp=temp->next;
	}
}




