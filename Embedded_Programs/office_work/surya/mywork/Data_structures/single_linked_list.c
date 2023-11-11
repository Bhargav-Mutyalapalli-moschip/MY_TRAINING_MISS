#include<stdio.h>
#include<stdlib.h>
int count=0;
int search_count=0;
struct node
{
	int data;
	struct node *link;
};
void addatbegin(int num);
void deleteatbegin();
void display();
void count_nodes();
void delete_entire_list();
int search_data(int num);
void sorting();
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.Add at beginning\n\n2.Delete at beginning\n\n3.Display the nodes\n\n4.Count the nodes\n\n5.Delete the entire list\n\n6.Search the particular data\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				addatbegin(data_value);
				break;

			case 2:
				printf("Delete at the beginning\n");
				deleteatbegin();
				break;

			case 3:
				printf("Display the node data\n");
				display();
				break;

			case 4:
				printf("Count the number of nodes in the list\n");
				count_nodes();
				break;

			case 5:
				printf("Delete the entire list\n");
				delete_entire_list();
			        break;

			case 6:
				printf("Search the data in the nodes\n");
				scanf("%d",&data_value);
				value=search_data(data_value);
				if(value==0)
					printf("Data is found %d times\n",search_count);
				else
					printf("Data is not found\n");
				break;

			case 7:
				printf("sorting the numbers in the list\n");
				sorting();
				break;


		}
		
	}
}
void addatbegin(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head!=NULL)
	{
		printf("The data is already present if you want to add the data you can\n");
	}
	count++;
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
void deleteatbegin()
{

	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	count--;
	temp=head;
	head=temp->link;
	free(temp);
}
void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The data:%d\n",temp->data);
		temp=temp->link;
	}
}
void count_nodes()
{

	if(head==NULL)
	{
		printf("List is empty\n");
		printf("There is no nodes in the list\n");
		return;
	}
	else
		printf("The number of nodes in list is %d\n",count);
}
void delete_entire_list()
{
	struct node *tempdup;
	struct node *temporg;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temporg=head;
	while(temporg!=NULL)
	{
	        tempdup=temporg;
		if(tempdup!=NULL)
		{
			temporg=temporg->link;
			free(tempdup);
		}

	}
	head=NULL;
	count=0;
}
int search_data(int num)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{

			search_count++;
		}
		temp=temp->link;
	}
	if(search_count >0)
	return 0;
	else
		return -1;

}
void sorting()
{
	int i,tempnew;
	struct node *temp;
	struct node *temp1;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	if(head->link!=NULL)
	{
		while(temp!=NULL)
		{
			temp1=temp->link;
			for(i=0;i<count-1;i++)
			{
				if((temp->data)>(temp1->data))
				{
					tempnew=temp->data;
					temp->data=temp1->data;
					temp1->data=tempnew;
					printf("temp->data:%d\n",temp->data);
					printf("Temp1->data:%d\n",temp1->data);
			                temp1=temp1->link;
					
				}
				else
			        temp1=temp1->link;
				if(temp1!=NULL)
					break;
			}
			count--;
			temp=temp->link;
		}
	}
}
void addatlast(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		ptr->data=num,;
		ptr->linl=NULL;
		return;

	}
	else
	{
	    ptr->link=head;
	    head=ptr;
	}
}

		




	










	
