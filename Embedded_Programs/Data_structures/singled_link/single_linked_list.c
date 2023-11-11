#include<stdio.h>
#include<stdlib.h>
int count=0;
int search_count=0;
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void addatbegin(int num);
void deleteatbegin();
void display();
void count_nodes();
void delete_entire();
int search(int num);
void bubble_sort();
int main()
{
	int pos,opt,num,var=-1;
	while(1)
	{
		printf("\n\n\tMENU\t\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Add_at_beginning\n2.Delete_at_beginning\n3.Display the list\n4.Count the number of nodes\n5.Delete the entire list\n6.Search the particular element\n7.Bubble sort\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program by user\n");
				exit(0);

			case 1:
				printf("Add the data at beginning\n");
				scanf("%d",&var);
				addatbegin(var);
				break;

			case 2:
				printf("Delete at the beginning\n");
				deleteatbegin();
				break;

			case 3:
				printf("Display the list\n");
				display();
				break;

			case 4:
				printf("Count the number of nodes\n");
				count_nodes();
				break;

			case 5:
				printf("Delete entire list\n");
				delete_entire();
				break;

			case 6:
				printf("Search for the element\n");
				scanf("%d",&num);
				var=search(num);
				printf("Var:%d\n",var);
				if(var==0)
				{
					printf("The node data is found of %d times\n",search_count);
				}
				else
					printf("Data is not found\n");
				search_count=0;

				break;

			case 7:
				printf("Sorting technique\n");
				bubble_sort();
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
	int i=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		i++;
		printf("The %d value is %d\n",i,temp->data);
		temp=temp->link;
	}
}
void count_nodes()
{
	if(head==NULL)
	{
		printf("List is empty\n");
		printf("No nodes is created\n");
		return;
	}
	printf("The total nodes is %d\n",count);
}
void delete_entire()
{
	struct node *temporginal;
	struct node *tempduplicate;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temporginal=head;
	while(temporginal!=NULL)
	{
		tempduplicate=temporginal;
		if(tempduplicate!=NULL)
		{
			temporginal=temporginal->link;
			free(tempduplicate);
		}
	}
	count=0;
}
int search(int num)
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
	if(search_count>0)
		return 0;
	else
		return -1;
}
void bubble_sort()
{
	int i,j,temp12;
	struct node *temp;
	struct node *temp1;
	if(head==NULL)
	{
		printf("List is empty\n");
		return ;
	}
	temp=head;
	if(count >=2)
	{

		while(temp!=NULL)
		{
			printf("Date loop\n");
			temp1=temp->link;
                        printf("%p\n",temp1);
			if((temp->data)>(temp1->data))
			{
				temp12=temp->data;
				temp->data=temp1->data;
				temp1->data=temp12;
				printf("temp12:%d\n",temp12);
			}
		        temp=temp->link;
		}
	}

	else
	{
		printf("unable to perform the sorting\n");
		return;
	}
}
void reverse()
{
	struct node *temp;
	struct node *temp1;
	if(head==NULL)
	{
		printf("List is empty\n");
		return ;
	}
	temp=head;











