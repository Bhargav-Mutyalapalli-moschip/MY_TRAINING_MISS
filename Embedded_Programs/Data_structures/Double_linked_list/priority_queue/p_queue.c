#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int prior_value;
	int data;
	struct node *next;
};
void insert_element(int var,int p_value);
void display();
struct node *front=NULL;
struct node *rear=NULL;
int main()
{
	int prog,num,var,p_value;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>Queue implementation<<<<<<<<<<<<\n");
		printf(">>>>>>>>>>>Select the option<<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Insert operation\n2.Display\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Succesfully executed by user\n");
				exit(0);

			case 1:
				printf("Insert the element\n");
				printf("Enter the data to be insert\n");
				scanf("%d",&num);
				printf("Enter the priority value\n");
				scanf("%d",&p_value);
				insert_element(num,p_value);
				break;

			case 2:
				printf("display\n");
				display();
				break;
		}
	}
}
void insert_element(int var,int p_value)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=var;
	ptr->next=NULL;
	if(rear==NULL)
	{
		ptr->prior_value=p_value;
		ptr->prev=NULL;
		rear=front=ptr;
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		if(temp->prior_value==p_value)
		{
			if(temp->next!=NULL)
			{
				if(temp->next->prior_value!=p_value)
				break;
			}
		}
		/*if(temp->prior_value >  p_value)
		  {

		  if(temp->next!=NULL)
		  {
		  if(temp->next->prior_value!=temp->prior_value)
		  break;
		  }
		  }
		  if(temp->prior_value <  p_value)
		  {

		  if(temp->next!=NULL)
		  {
		  if(temp->next->prior_value!=temp->prior_value)
		  break;
		  }
		  }*/
		if(temp->prior_value > p_value)
			break;
		temp=temp->next;



	}
	if(temp==NULL)
	{
		ptr->prior_value=p_value;
		ptr->next=rear->next;
		ptr->prev=rear;
		if(rear->next!=NULL)
			rear->next->prev=ptr;
		rear->next=ptr;
		rear=ptr;
		return;
	}
	if(temp->prior_value > p_value)
	{
		ptr->prior_value=p_value;
		ptr->prev=temp->prev;
		ptr->next=temp;
		temp->prev=ptr;
		if(temp==front)
		front=ptr;
		return;
	}
	if(temp->prior_value < p_value)
	{
		ptr->prior_value=p_value;
		ptr->prev=temp;
		ptr->next=temp->next;
		temp->next=ptr;
		if(rear==temp)
		rear=ptr;
		return;
	}
	ptr->prior_value=p_value;
	ptr->next=temp->next;
	ptr->prev=temp;
	if(temp->next!=NULL)
		temp->next->prev=ptr;
	else
		rear=ptr;
	temp->next=ptr;


}
void display()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=rear->next)
	{
		printf("The data in queue:%d--------The priority values is:%d\n",temp->data,temp->prior_value);
		temp=temp->next;
	}
}








