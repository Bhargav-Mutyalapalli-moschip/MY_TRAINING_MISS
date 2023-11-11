#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	struct node *prev;
	int prior_value;
	int freq;
	int data;
	struct node *next;
};
void insert_element(int var,int p_value);
void display();
void display_prior(int num);
void count();
void delete_priority(int num);
void delete_priority_data(int prior,int var);
void delete_entire_queue();
void create_list(int *iptr,int n);
struct node *head=NULL;
int main()
{
	int prog,num,var,p_value,*ptr,i;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>Queue implementation<<<<<<<<<<<<\n");
		printf(">>>>>>>>>>>Select the option<<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Insert operation\n2.Display\n3.Display prior\n4.Frequency\n5.Delete the priority\n6.Delete the priority and data\n7.Delete entire queue\n8.Create the list\n");
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

			/*case 3:
				printf("Display prior\n");
				scanf("%d",&num);
				display_prior(num);
				break;

			case 4:
				printf("Frequency\n");
				count();
				break;

			case 5:
				printf("Delete the priority\n");
				scanf("%d",&num);
				delete_priority(num);
				break;

			case 6:
				printf("Delete the data with priority and data\n");
				scanf("%d%d",&num,&var);
				delete_priority_data(num,var);
				break;

			case 7:
				printf("Entire queue\n");
				delete_entire_queue();
				break;

			case 8:
				printf("Create the list\n");
				printf("entire the size of the array\n");
				scanf("%d",&num);
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(-1);
				}
				num=num+num;
				for(i=0;i<num;i++)
				{
					__fpurge(stdin);
					if(i%2==0)
						printf("Enter the data in %d position\n",i);
					else
						printf("Enter the priority value in %d position\n",i);
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,num);
				free(ptr);
				break;*/


		}
	}
}
void insert_element(int num,int prior)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=num;
	ptr->next=NULL;
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->prior_value=prior;
		head=ptr;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			if(temp->prior_value > prior)
			{
				ptr->prior_value=prior;
				ptr->prev=temp->prev;
				ptr->next=temp;
				temp->prev=ptr;
				if(temp==head)
				head=ptr;
				return;;
			}
			else if(temp->prior_value < prior)
			{
				if(temp->next==NULL)
				break;
			}
			if(temp->prior_value==prior)
			{
				if(temp!=NULL)
				{
					if(temp->next->prior_value!=prior)
					break;
				}
			if(temp->next==NULL)
				break;
			temp=temp->next;

	                
		}
		ptr->prior_value=prior;
		ptr->prev=temp->prev;
		temp->prev->next=ptr;
		temp->prev=ptr;




	}
}






























void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The data in queue:%d--------The priority values is:%d---------The freq is:%d\n",temp->data,temp->prior_value,temp->freq);
		temp=temp->next;
	}
}
		
	
