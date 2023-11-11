#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void create_list(int *iptr,int n)
{
	struct node *ptr,*temp;
	int i;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->data=iptr[i];
		if(head==NULL)
		{
			temp=ptr->next=ptr->prev=head=ptr;
		}
		else
		{
			ptr->next=head;
			ptr->prev=head->prev;
			ptr->prev->next=ptr;
			head->prev=ptr;
		}
	}
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
	while(temp->next!=head)
	{
		printf("The output data:%d\n",temp->data);
		temp=temp->next;
	}
	printf("The output data:%d\n",temp->data);
}
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Double linked list<<<<<<<<<<<<<<<<<<<\n\n");
		printf("0.Exit the program\n\n1.Create the list\n\n2.Display\n\n3.Display the node\n\n4.Add at last\n\n5.Delete at last\n\n6.Delete Duplicates\n\n7.Search the data\n\n8.Count the nodes\n\n9.Reverse the list\n\n10.Swap by link\n\n11.Add after node\n\n12.Add before node\n\n13.Delete particular node\n\n14.Create the list\n\n15.Delete the entire list\n\n16.Selection sorting\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
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

			case 2:
				printf("delete at begin\n");
				display();
				break;

		}
	}
}

