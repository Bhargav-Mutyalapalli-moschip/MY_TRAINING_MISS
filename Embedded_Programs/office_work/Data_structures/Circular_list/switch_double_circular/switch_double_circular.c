#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void add_at_begin(int num);
void delete_at_begin();
void create_list(int *iptr,int n);
void display();
void add_at_last(int num);
void delete_at_last();
void count();
int search_operation(int num);
void reverse_list();
void delete_duplicates();
void delete_particular_node(int num);
void swap(int num,int dum);
void selection_sort();
void bubble_sort();
struct node *head=NULL;
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
				printf("Display\n");
				display();
				break;

			case 3:
				printf("Add at begin\n");
				scanf("%d",&num);
				add_at_begin(num);
				break;

			case 4:

				printf("Delete at begin\n");
				delete_at_begin();
				break;

			case 5:
				printf("Add at last\n");
				scanf("%d",&num);
				add_at_last(num);
				break;

			case 6:
				printf("Delete at last\n");
				delete_at_last();
				break;

			case 7:
				printf("Count the nodes\n");
				count();
				break;

			case 8:
				printf("Search operation\n");
				scanf("%d",&num);
				var=search_operation(num);
				if(var>0)
					printf("Elements is found\n");
				else
					printf("Not found\n");
				break;

			case 9:
				printf("Reverse operation\n");
				reverse_list();
				break;

			case 10:
				printf("delete duplicates\n");
				delete_duplicates();
				break;

			case 11:
				printf("Delete the particular node\n");
				scanf("%d",&num);
                                delete_particular_node(num);
				break;

			case 12:
				printf("Swap by link\n");
				scanf("%d%d",&num,&var);
				swap(num,var);
				break;

			case 13:
				printf("Selection sorting\n");
                                selection_sort();
				break;

			case 14:
				printf("Bubble_sort\n");
                                bubble_sort();
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
	ptr->data=num;
	if(head==NULL)
	{
		ptr->prev=ptr->next=head=ptr;
		return;
	}
	ptr->prev=head->prev;
	ptr->prev->next=ptr;
	ptr->next=head;
	head->prev=ptr;
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==head)
	{
		printf("COming\n");
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	head->prev->next=head->next;
	head->next->prev=head->prev;
	head=head->next;
	free(temp);
}
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
	if(head!=NULL)
	printf("The output data:%d\n",temp->data);
}
void add_at_last(int num)
{

	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in gheap segment\n");
		exit(-1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->prev=ptr->next=head=ptr;
		return;
	}
	head->prev->next=ptr;
	ptr->prev=head->prev;
	ptr->next=head;
	head->prev=ptr;
}
void delete_at_last()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head->prev;
	head->prev->prev->next=head;
	head->prev=head->prev->prev;
	free(temp);
}
void count()
{
	int count=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		count++;
		temp=temp->next;
	}
	if(head!=NULL)
	{
		count++;
		printf("The output data:%d\n",temp->data);
	}
	printf("The count:%d\n",count);
	count=0;
}
int search_operation(int num)
{
	int pos=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	temp=head;
	do
	{
		pos++;
		if(temp->data==num)
		return pos;
		temp=temp->next;
	}
	while(temp!=head);
	return 0;
}

void reverse_list()
{
	struct node *temp,*p,*q;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
	do
	{
		q=p->next;
		temp=p->prev;
		p->prev=p->next;
		p->next=temp;
		p=q;
	}
	while(p!=head);
	head=head->next;
	
}
void delete_duplicates()
{
	struct node *q,*p,*s;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==head)
	return;
        for(p=head;p->next!=head;p=p->next)
	{
		for(q=p->next;q!=head;q=q->next)
		{
			printf("entered Q**********\n");

			if(p->data == q->data)
			{
				printf("entered\n");
				q->next->prev=q->prev;
				q->prev->next=q->next;
				//if(q==head->prev)
				//head->prev=p;
				s=q->prev;
				free(q);
				q=s;
			}
		}
	}
}
void delete_particular_node(int num)
{
	int flag=0;
	struct node *temp,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==head)
		{
			free(head);
			head=NULL;
			return;
		}
		temp=head;
		temp->prev=temp->next->prev;
		free(temp);
		temp=head;
		head=head->next;
		head->prev=head;
		return;
	}
	prev=head;
	temp=head->next;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			flag=1;
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if(flag==0)
	{
		printf("Element is not found\n");
		return;
	}
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	free(temp);
}
void swap(int num,int dum)
{
        int pos1=0,pos2=0,flag1=0,flag2=0;
        struct node *p,*q,*temp,*ptr,*s;
        if(head==NULL)
        {
                printf("\n\tthe list is empty\n\n");
                return;
        }
        if(head->next==head)
                return;
        if(num==dum)
                return;
        q=p=head;
	do
        {
                pos1++;
                if(p->data==num)
		{
			flag1=1;
                        break;
		}
                p=p->next;
        }
        while(p!=head);
	do
        {
                pos2++;
                if(q->data==dum)
		{
			flag2=1;
                        break;
		}
                q=q->next;
        }
        while(q!=head);
        if((flag1!=1)||(flag2!=1))
        {
                printf("\n\tthe data not found\n\n");
                return;
        }
        if(pos1>pos2)
        {
                temp=p;
                p=q;
                q=temp;
        }
	printf("Pos1:%d\n	pos2:%d\n",pos1,pos2);
        if(p->next!=q)
        {
		
		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;

		temp=p->next;
		p->next=q->next;
		q->next=temp; 


		if(p!=head)
		{
		q->prev->next=q;
		}
		else
		{
			if(q==q->prev)
			{
				
				temp=p->next;
				p->next=q->prev;
				q->prev=temp; 
			}
			else
			{
				q->prev->next=q;
			}
			head =q;


		}
		p->prev->next=p;
		q->next->prev=q;
		if(q!=head)
		p->next->prev =p;

	}
	else
	{
		q->prev=p->prev;
		p->prev=q;

		p->next=q->next;
		q->next=p;

		
			q->prev->next=q;
		

		p->next->prev =p;

		if(p==head)
		{
			head =q;

		}

	}
}
void selection_sort()
{
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p->next!=head;p=p->next)
	{
		for(q= p->next;q!=head;q=q->next)
		{
			if(p->data > q->data)
			{
				temp=p->prev;
				p->prev=q->prev;
				q->prev=temp;

				temp=p->next;
				p->next=q->next;
				q->next=temp;


				if(p!=head)
				{
					q->prev->next=q;
				}
				else
				{
					/*	if(q==q->prev)
						{

						temp=p->next;
						p->next=q->prev;
						q->prev=temp;
						}
						else
						{
						q->prev->next=q;
						}*/

					temp =head;
					while(temp->next!=head)
						temp=temp->next;
					temp->next=q;
					head =q;
				}
				p->prev->next=p;
				q->next->prev=q;
				if(q!=head)
					p->next->prev =p;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}
void bubble_sort()
{
	struct node *p,*q,*e,*temp;
	for(e=head;head->next!=e;e=p)
	{
		for(p=head;p->next!=e;p=p->next)
		{
			q=p->next;
			if(p->data > q->data)
			{
				q->prev=p->prev;
				p->prev=q;

				p->next=q->next;
				q->next=p;

				q->prev->next=q;


				p->next->prev =p;

				if(p==head)
				{
					e=q;
					head =q;
				}
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}

















