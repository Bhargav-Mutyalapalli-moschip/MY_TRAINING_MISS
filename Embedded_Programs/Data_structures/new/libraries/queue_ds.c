#include<stdio.h>
#include<stdlib.h>
int count1;
struct node
{
	int data;
	struct node *link;
};
struct node *rear=NULL;
struct node *front=NULL;
void insert_data(int num);
void delete_data();
void display();
void count();
int main()
{
	int prog,num;
	while(1)
	{
		printf("*******************Queue implementation*****************\n");
		printf("0.Exit the program\n1.Insert operation\n2.Delete the data\n3.Display queue\n4.Count the queue elements\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Exit the progam\n");
				exit(0);

			case 1:
				printf("Insert the data\n");
				scanf("%d",&num);
				insert_data(num);
				break;

			case 2:
				printf("Delete the data\n");
				delete_data();
				break;

			case 3:
				printf("display\n");
				display();
				break;

			case 4:
				printf("COunt\n");
				count();
				break;
		}
	}
}
void insert_data(int num)
{
	struct node *temp;
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(rear==NULL)
	{
		front=rear=ptr;
	}
	rear->link=ptr;
	rear=ptr;
}
void delete_data()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	front=front->link;
	free(temp);
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
	while(temp!=NULL)
	{
		printf("The Queue Data:-->>(%d)\n",temp->data);
		temp=temp->link;
	}
}
void count()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=rear->link)
	{
		count1++;
		temp=temp->link;
	}
	printf("The number of data in the Queue-->>%d\n",count1);
	count1=0;
}

	




	




