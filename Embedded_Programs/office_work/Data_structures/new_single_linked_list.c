#include<stdio.h>
#include<stdlib.h>
int count=0;
int search_count=0;
int duplicate1=0;
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
void addatlast(int num);
void deleteatlast();
void addafternode(int num,int data);
void addbeforenode(int num,int data);
void delete_particular(int num);
void reverse_list();
void duplicate(int num);
void create_list(int *ptr1,int num);
void swap_data(int num1,int num2);
void swap_link(int num1,int num2);
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.Add at beginning\n\n2.Delete at beginning\n\n3.Display the nodes\n\n4.Count the nodes\n\n5.Delete the entire list\n\n6.Search the particular data\n\n7.Sorting the data in the lsit\n\n8.Add at last\n\n9.Delete at last\n\n10.Add after node\n\n11.add before a node\n\n12.Delete particular node\n\n13.Reverse the list\n\n14.Delete the duplicates\n\n15.Create a list\n\n16.swap the data\n\n17.swap the data with links\n\n");
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
				if(value>=1)
					printf("Data is found at %d position\n",value);
				break;

			case 7:
				printf("sorting the numbers in the list\n");
				sorting();
				break;

			case 8:
				printf("Add at last\n");
				scanf("%d",&num);
                                addatlast(num);
				break;

			case 9:
				printf("delete the data at last\n");
				deleteatlast();
				break;

			case 10:
				printf("add after node\n");
				printf("enter search element and add element\n");
				scanf("%d%d",&data_value,&num);
				addafternode(data_value,num);
				break;

			case 11:
				printf("Add before node\n");
				printf("enter search element and add element\n");
				scanf("%d%d",&data_value,&num);
				addbeforenode(data_value,num);
				break;

			case 12:
				printf("Enter the data to delete the particular data\n");
				scanf("%d",&num);
				delete_particular(num);
				break;

			case 13:
				printf("Reverse the entire list\n");
				reverse_list();
				break;

			case 14:
				printf("Remove duplicates\n");
				scanf("%d",&num);
				duplicate(num);
				break;

			case 15:
				printf("Create a list\n");
				printf("Enter the number of elements\n");
                                scanf("%d",&num);
				ptr=(int*)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("failed to allocate the memory in heap sgment\n");
					exit(-1);
				}
				for(i=0;i<num;i++)
				{
					printf("Enter the element\n");
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,num);
				free(ptr);
				break;


			case 16:
				printf("Swap the data by exchange by data method\n");
				scanf("%d%d",&num,&var);
				swap_data(num,var);
				break;

			case 17:

				printf("Swap the data by exchange by data method\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
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
	struct node*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
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
}
int search_data(int num)
{
	struct node *temp;
	int pos=0;
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
		{

			return pos;
		}
		temp=temp->link;
	}
	printf("data is not found\n");
	return 0;

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
	struct node *temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		ptr->data=num;
		ptr->link=NULL;
		head=ptr;
		return;

	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	ptr->data=num;
	temp->link=ptr;
	ptr->link=NULL;

}
void deleteatlast()
{
	struct node *cur,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;

	}
	if(head->link==NULL)
	{
		free(head);
		head=NULL;
	}
	prev=head;
	cur=head->link;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=NULL;
	free(cur);

	

}
void addafternode(int num,int data)
{
	struct node *temp;
	struct node *ptr;
	if(head==ptr)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("failed to alocate the memory in heap segment\n");
				exit(-1);
			}
			ptr->data=data;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}
		temp=temp->link;
	}
	printf("Element is not found\n");
}
void addbeforenode(int num,int data)
{
	struct node *temp;
	struct node *ptr;
	struct node *current;
	struct node *previous;

	if(head==ptr)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("failed to allocate the memory in heap segment\n");
				exit(-1);
			}
			ptr->data=data;
			ptr->link=head;
			head=ptr;
			return ;
		}
	}
	previous=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("failed to allocate the memory in heap segment\n");
				exit(-1);
			}
			ptr->data=data;
			ptr->link=previous->link;
			previous->link=ptr;
			return;
		}
		previous=current;
		current=current->link;
	}
        printf("Element not found\n");
}
void delete_particular(int num)
{
	struct node *temp;
	struct node *previous;
	struct node *current;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		previous=head;
		current=head->link;
		free(previous);
		head=current;
		return;
		
	}
	previous=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		{
			previous->link=current->link;
			free(current);
			return;
		}
		printf("pevious->link:%p\n",previous->link);
		previous=current;
		current=current->link;
		
	}
	printf("Elements not found\n");

}
void reverse_list()
{
	struct node* temp;
	struct node *previous,*current,*next;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	previous=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->link;
		current->link=previous;
		previous=current;
		current=next;
	}
	head=previous;
}
void duplicate(int num)
{
	struct node *temp;
	struct node *current;
	struct node *previous;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	previous=head;
	current=head;
	while(current!=NULL)
	{
		if(current->data==num)
		{
			duplicate1++;
			if(duplicate1>1)
			{
				previous->link=current->link;
				temp=current;
				free(current);

			}
		}
		previous=current;
		current=current->link;
		if(duplicate1>1)
		{
			previous=temp;
			current=temp->link;
		}

	}
	printf("Element is not found\n");
}
/*void swap(int num1,int num2)
{
	struct node *temp;
	struct node *current;
	struct node *previous;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	previous=head;
	current=head->link;
	while(temp!=NULL)
	{
		if(previous->link==num1)
		{*/
void create_list(int *ptr1,int num)
{
	int i;
	struct node *temp;
	struct node *begin=NULL;
	struct node *ptr,*previous;
	for(i=0;i<num;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(-1);
		}

		ptr->data=ptr1[i];
		ptr->link=NULL;
		if(begin==NULL)
		{
			begin=ptr;
		}
		else
			previous->link=ptr;
		previous=ptr;
	}
	if(head==NULL)
	{
		head=begin;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=begin;
}
void swap_data(int num1,int num2)
{
	int temp;
	struct node *point1,*point2;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(1);
	}
	point1=point2=head;
	while(point1!=NULL)
	{
		if(point1->data==num1)
			break;
		point1=point1->link;
	}
	while(point2!=NULL)
	{
		if(point2->data==num2)
			break;
		point2=point2->link;
	}
	if((point1==NULL)||(point2==NULL))
	{
		printf("Element is not found\n");
		return;
	}
	temp=point1->data;
	point1->data=point2->data;
	point2->data=temp;
	return;

}
void swap_link(int num1,int num2)
{
	int temp1,locate1=0,locate2=0;
	struct node *start_current,*start_prev,*end_prev,*end_current,*temp,*p1,*p2;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(1);
	}
	if(num1==num2)
	return;
	start_current=end_current=head;
	while(start_current!=NULL)
	{
		locate1++;
		if(start_current->data==num1)
			break;
		start_prev=start_current;
		start_current=start_current->link;
	}
	while(end_current!=NULL)
	{
		locate2++;
		if(end_current->data==num2)
			break;
		end_prev=end_current;
		end_current=end_current->link;
	}
	if(start_current==NULL || end_current==NULL)
	{
		printf("Elements not found\n");
		return;
	}
	if(locate1>locate2)
	{
		temp=start_current;
		start_current=end_current;
		end_current=temp;
	}


	


			




}
	

	



































































































	

	



































































































