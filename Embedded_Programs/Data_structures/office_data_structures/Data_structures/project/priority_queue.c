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

			case 3:
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
				num=num+num;
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(-1);
				}
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
	if(head==NULL)
	{
		ptr->prior_value=p_value;
		ptr->prev=NULL;
		head=ptr;
		return;
	}
	temp=head;
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
		if(temp->prior_value > p_value)
			break;
		if(temp->next==NULL)
			break;
		temp=temp->next;



	}
	if(temp==NULL)
	{
		ptr->prior_value=p_value;
		ptr->next=head->next;
		ptr->prev=head;
		if(head->next!=NULL)
			head->next->prev=ptr;
		head->next=ptr;
		return;
	}
	if(temp->prior_value > p_value)
	{
		ptr->prior_value=p_value;
		ptr->prev=temp->prev;
		ptr->next=temp;
		if(temp->prev!=NULL)
		temp->prev->next=ptr;
		temp->prev=ptr;
		if(head==temp)
		head=ptr;
		return;
	}
	if(temp->prior_value < p_value)
	{
		ptr->prior_value=p_value;
		ptr->prev=temp;
		ptr->next=temp->next;
		temp->next=ptr;
		return;
	}
	ptr->prior_value=p_value;
	ptr->next=temp->next;
	ptr->prev=temp;
	if(temp->next!=NULL)
		temp->next->prev=ptr;
	temp->next=ptr;


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
void display_prior(int num)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior_value==num)
		{
			printf("The prior value is :%d--------The data is:%d--------The freq:%d\n",num,temp->data,temp->freq);
		}
		temp=temp->next;
	}
}
void count()
{
	int count=1;
	struct node *p,*q,*temp,*var;
	temp=NULL;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->prior_value==q->prior_value)
			{
				count++;
				printf("Inner\n");
				p=p->next;
			}
			
		}
		var=p;
		while(var!=temp)
		{
			var->freq=count;
			var=var->prev;
		}
		temp=p;
		printf("The count is:%d-----The priority is :%d\n",count,p->prior_value);
		count=1;
	}
}

void delete_priority(int num)
{
	struct node *temp,*var;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior_value==num)
		{
			if(temp==head)
			head=head->next;
			else
			temp->prev->next=temp->next;
			if(temp->next!=NULL)
			temp->next->prev=temp->prev;;
			var=temp->next;
			free(temp);
			temp=var;

                }
		else
			temp=temp->next;
	}
}
void delete_priority_data(int prior,int val)
{
	struct node *temp,*var;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior_value==prior && temp->data==val)
		{
			if(temp==head)
			head=head->next;
			else
			temp->prev->next=temp->next;
			if(temp->next!=NULL)
			temp->next->prev=temp->prev;;
			var=temp->next;
			free(temp);
			temp=var;
		}
		else
			temp=temp->next;
	}
}
void delete_entire_queue()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
}
void create_list(int *iptr,int n)
{
	int i;
	struct node *temp;
	for(i=0;i<n;i=i+2)
	{
		struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		ptr->next=NULL;
		if(head==NULL)
		{
			ptr->prior_value=iptr[i+1];
			ptr->prev=NULL;
			head=ptr;
			
		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->prior_value==iptr[i+1])
				{
					if(temp->next!=NULL)
					{
						if(temp->next->prior_value!=iptr[i+1])
							break;
					}
				}
				if(temp->prior_value > iptr[i+1])
					break;
				if(temp->next==NULL)
					break;
				temp=temp->next;



			}
			if(temp==NULL)
			{
				ptr->prior_value=iptr[i+1];
				ptr->next=head->next;
				ptr->prev=head;
				if(head->next!=NULL)
					head->next->prev=ptr;
				head->next=ptr;
			//	continue;

			}
			else if(temp->prior_value > iptr[i+1])
			{
				ptr->prior_value=iptr[i+1];
				ptr->prev=temp->prev;
				ptr->next=temp;
				if(temp->prev!=NULL)
					temp->prev->next=ptr;
				temp->prev=ptr;
				if(head==temp)
					head=ptr;
			//	continue;

			}
			else if(temp->prior_value < iptr[i+1])
			{
				ptr->prior_value=iptr[i+1];
				ptr->prev=temp;
				ptr->next=temp->next;
				temp->next=ptr;
			//	continue;
				
			}
			else if(temp!=NULL)
			{
				ptr->prior_value=iptr[i+1];
				ptr->next=temp->next;
				ptr->prev=temp;
				if(temp->next!=NULL)
					temp->next->prev=ptr;
				temp->next=ptr;
			}
		}


	}
}


















