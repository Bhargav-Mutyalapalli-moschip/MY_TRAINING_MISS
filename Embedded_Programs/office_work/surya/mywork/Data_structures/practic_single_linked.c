#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count=0;
int search_count=0;
int duplicate1=0;
struct node
{
	int data;
	struct node *link;
};
void add_at_begin(int num);
void delete_at_begin();
void display_nodes();
void count_nodes();
int search_nodes(int num);
void add_at_last(int num);
void delete_at_last();
void add_after_node(int num,int var);
void add_before_node(int num,int var);
void delete_particular_node(int num);
void reverse_list();
void create_list(int *iptr,int num);
void swap_data(int num1,int num2);
void delete_list();
void delete_duplicates();
void swap_link(int num,int val);
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.ADD at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.count the nodes\n\n5.search the nodes\n\n6.add at last\n\n7.Delete at last\n\n11.Reverse\n\n14.Delete entire list\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				add_at_begin(data_value);
				break;

			case 2:
				printf("delete at begin\n");
				delete_at_begin();
				break;

			case 3:
				printf("display the nodes\n");
				display_nodes();
				break;

			case 4:
				printf("Count the nodes\n");
				count_nodes();
				break;

			case 5:
				printf("Search the nodes\n");
				scanf("%d",&data_value);
				var=search_nodes(data_value);
				if(var>0)
				{
					printf("Element is found at %d position\n",var);
				}
				else
					printf("Element is not found\n");
				break;

			case 6:
				printf("Add at last\n");
				scanf("%d",&data_value);
				add_at_last(data_value);
				break;

			case 7:
				printf("Delete at last\n");
				delete_at_last();
				break;

			case 8:
				printf("Add after a node\n");
				printf("Enter the search element and add search element\n");
				scanf("%d%d",&data_value,&var);
				add_after_node(data_value,var);
				break;

			case 9:
				printf("Add before a node\n");
				scanf("%d%d",&data_value,&var);
				add_before_node(data_value,var);
				break;

			case 10:
				printf("Delete the particular node\n");
				scanf("%d",&data_value);
				delete_particular_node(data_value);
				break;

			case 11:
				printf("Reverse the list\n");
				reverse_list();
				break;

			case 12:
				printf("Create a list\n");
				printf("Enter the elements\n");
				scanf("%d",&num);
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(1);
				}
				for(i=0;i<num;i++)
				{
					__fpurge(stdin);
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,num);
				free(ptr);
				break;

			case 13:
				printf("enter the elements\n");
				scanf("%d%d",&data_value,&var);
                                swap_data(data_value,var);
				break;

			case 14:
				printf("Delete entire list\n");
				delete_list();
				break;

			case 15:
				printf("Delete Duplicates\n");
				delete_duplicates();
				break;

			case 16:
				printf("enter the elements\n");
				scanf("%d%d",&data_value,&var);
                                swap_link(data_value,var);
				break;
				

				





		}
	}
}
void add_at_begin(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
void delete_at_begin()
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
void display_nodes()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The output data:%d\n",temp->data);
		temp=temp->link;
	}
}
void count_nodes()
{
	struct node *temp;
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
	printf("The count is:%d\n",count);
	count=0;
}
int search_nodes(int num)
{
	int pos=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
	return 0;
}
void add_at_last(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	temp=head;
	if(head==NULL)
	{
		ptr->data=num;
		ptr->link=head;
		head=ptr;
		return;
	}
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	ptr->data=num;
	ptr->link=temp->link;
	temp->link=ptr;
}
void delete_at_last()
{
	struct node *current,*prev,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		temp=head;
		head=head->link;
		free(head);
		return;
	}
	prev=head;
	current=head->link;
	while(current-> link!=NULL)
	{
		prev=current;
		current=current->link;
	}
	prev->link=current->link;
	free(current);
}
void add_after_node(int num,int var)
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=(struct  node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			ptr->data=var;
			ptr->link=head->link;
			head->link=ptr;
			return;
		}
		else
		{
			ptr->data=var;
			ptr->link=head->link;
			head->link=ptr;
			return;
		}
	}
	prev=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		break;
		current=current->link;
	}
	ptr->data=var;
	ptr->link=current->link;
	current->link=ptr;

}
void add_before_node(int num,int var)
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=(struct  node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			ptr->data=var;
			ptr->link=head;
			head=ptr;
			return;
		}
		else
		{
			ptr->data=var;
			ptr->link=head;
			head=ptr;
			return;
		}
	}
	prev=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		break;
		prev=current;
		current=current->link;
	}
	ptr->data=var;
	ptr->link=prev->link;
	prev->link=ptr;
}
void delete_particular_node(int num)
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=(struct  node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			temp=head;
			head=head->link;
			free(temp);
			return;
		}
		else
		{
			temp=head;
			head=head->link;
			free(temp);
			return;
		}
	}
	prev=head;
	current=head->link;
	while(current!=NULL)
	{
		if(current->data==num)
		break;
		prev=current;
		current=current->link;
	}
	prev->link=current->link;
	free(current);
}
void reverse_list()
{
	struct node *current,*prev,*temp,*ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)
	return;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		temp=current->link;
		current->link=prev;
		prev=current;
		current=temp;
	}
	head=prev;
}
void create_list(int *iptr,int num)
{
	struct node *temp;
	struct node *begin=NULL;
	struct node *prev;
	struct node *ptr;
	int i;
	for(i=0;i<num;i++)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(1);
		}
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(begin==NULL)
		{
			begin=ptr;
		}
		else
			prev->link=ptr;
		prev=ptr;
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
	struct node *pointer1,*pointer2;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(1);
	}
	if(head->link==NULL)
	return;
	if(num1==num2)
	return;
	pointer1=pointer2=head;
	while(pointer1!=NULL)
	{
		if(pointer1->data==num1)
			break;
		pointer1=pointer1->link;
	}
	while(pointer2!=NULL)
	{
		if(pointer2->data==num2)
			break;
		pointer2=pointer2->link;
	}
	if(pointer1==NULL || pointer2==NULL)
	{
		printf("Elements is not found\n");
		return;
	}
	temp=pointer1->data;
	pointer1->data=pointer2->data;
	pointer2->data=temp;
	return;
}
void delete_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(head!=NULL)
	{
		temp=head;
		head=head->link;
		free(temp);
	}
}
void swap_link(int num,int val)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(num==val)
	{
		return;
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
		{
			break;
		}
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==val)
		{
			break;
		}
		s=q;
		q=q->link;
	}
	if(p==NULL||q==NULL)
	{
		printf("Element not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;

		if(p==head)
		{
			head=q;
		}
		else
			r->link=q;
		s->link=p;
		return;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p==head)
		{
			head=q;
		}
		else
			r->link=q;
		return;
	}
}
void delete_duplicates()
{
	struct node *p,*s,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->link)
	{
		for(s=p,q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data==q->data)
			{
				s->link=q->link;
				free(q);
				q=s;
			}
		}
	}
}

























