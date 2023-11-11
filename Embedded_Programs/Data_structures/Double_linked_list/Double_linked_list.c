#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count1=0;
int search_count=0;
int duplicate1=0;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
void add_at_begin(int num);
void delete_at_begin();
void display();
void add_at_last(int num);
void delete_at_last();
void duplicates();
int search(int num);
void count();
void reverse();
void swap_link(int num1,int num2);
void add_after_node(int num,int var);
void add_before_node(int num,int var);
void delete_particular(int num);
void create_list(int *iptr,int n);
void delete_list();
void selection_sorting();
struct node *head=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Double linked list<<<<<<<<<<<<<<<<<<<\n\n");
		printf("0.Exit the program\n\n1.Add at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.Add at last\n\n5.Delete at last\n\n6.Delete Duplicates\n\n7.Search the data\n\n8.Count the nodes\n\n9.Reverse the list\n\n10.Swap by link\n\n11.Add after node\n\n12.Add before node\n\n13.Delete particular node\n\n14.Create the list\n\n15.Delete the entire list\n\n16.Selection sorting\n\n");
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
				display();
				break;

			case 4:
				
				printf("Enter the element to perform the add at last operation\n");
				scanf("%d",&data_value);
				add_at_last(data_value);
				break;

			case 5:
				printf("Delete at last \n");
				delete_at_last();
				break;

			case 6:
				printf("Duplicates\n");
				duplicates();
				break;

			case 7:
				printf("Search operation\n");
				scanf("%d",&num);
				pos=search(num);
				if(pos>0)
				{
					printf("Element found on %d position\n",pos);
				}
				else if(pos==0)
					printf("Elements is not found\n");

				break;

			case 8:
				printf("Count the nodes\n");
				count();
				break;

			case 9:
				printf("reverse the list\n");
				reverse();
				break;

			case 10:
				printf("Swap by link\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

			case 11:
				printf("Add after a node\n");
				scanf("%d%d",&num,&var);
				add_after_node(num,var);
				break;

			case 12:

				printf("Add before a node\n");
				scanf("%d%d",&num,&var);
				add_before_node(num,var);
				break;

			case 13:
				printf("Delete particular node\n");
				scanf("%d",&num);
				delete_particular(num);
				break;

			case 14:
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

			case 15:
				printf("Delete the entire list\n");
				delete_list();
				break;

			case 16:
				printf("Selection sorting\n");
				selection_sorting();
				break;



			



		}
	}
}
//------------------------------------------------------------------add at begin------------------------------------------------
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
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	ptr->next=head;
	ptr->prev=NULL;
	head->prev=ptr;
	head=ptr;
	return;
}
//--------------------------------------------------------------------Display---------------------------------------------------
void display()
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
		printf("\t\n\t%d\t",temp->data);
		temp=temp->next;
	}
}
//--------------------------------------------------------------------Delete at begin---------------------------------------------------
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}
//--------------------------------------------------------------------Add at last---------------------------------------------------
void add_at_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("List is empty\n");
		exit(-1);
	}
	if(head==NULL)
	{
		ptr->data=num;
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->data=num;
	ptr->prev=temp;
	ptr->next=NULL;
	temp->next=ptr;
	return;
}
//--------------------------------------------------------------------Delete at last---------------------------------------------------
void delete_at_last()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
//--------------------------------------------------------------------Delete duplicates---------------------------------------------------
void duplicates()
{
	struct node *p,*s,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		printf("It has single elements\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(s=p,q=p->next;q!=NULL;s=q,q=q->next)
		{
			if(p->data==q->data)
			{
				s->next=q->next;
				if(q->next!=NULL)
				q->next->prev=q->prev;
				free(q);
				q=s;
			}
		}
	}
}
//--------------------------------------------------------------------Search operation---------------------------------------------------
int search(int num)
{
	int pos=0;
	struct node *temp;
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
			return pos;
		temp=temp->next;

	}
	return 0;
}
//--------------------------------------------------------------------Count the nodes---------------------------------------------------
void count()
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
		count1++;
		temp=temp->next;
	}
	printf("The number of nodes are present is:%d\n",count1);
	count1=0;
}
//--------------------------------------------------------------------Reverse the list---------------------------------------------------
void reverse()
{
	struct node *next,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	return;
	p=head;
	while(p!=NULL)
	{
		next=p->next;
		p->next=p->prev;
		p->prev=next;
		if(p->prev==NULL)
		head=p;
		p=next;
	}
	
}
//--------------------------------------------------------------------Swap by link---------------------------------------------------
void swap_link(int num1,int num2)
{
	int pos1=0,pos2=0;
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2)
	return;
	if(head->next==NULL)
	return;
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num1)
		break;
		p=p->next;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)
		break;
		q=q->next;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p==NULL || q==NULL)
	{
		printf("Elemenets are not found\n");
		return;
	}
	if(p->next!=q)
	{
		temp=p->next;
		p->next=q->next;
		q->next=temp;
		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;
		if(p!=head)
		{

			q->prev->next=q;
			if(p->next!=NULL)
			p->prev->prev=q;
			p->prev->next=p;
			q->next->prev=q;
		}

		else
		{
			head=q;
		q->next->prev=q;
		p->prev->next=p;
		if(p->next!=NULL)
		p->next->prev=p;
		}

	}
	else
	{
		p->next=q->next;
		q->next=p;
		q->prev=p->prev;
		p->prev=q;
		if(p->next!=NULL)
		p->next->prev=p;
		if(p==head)
		{
			head=q;
			q->prev=NULL;
		}
		else
		{
			q->prev->next=q;
		}

	}


}
//--------------------------------------------------------------------Add after node---------------------------------------------------
void add_after_node(int num,int var)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			ptr->data=var;
			ptr->next=NULL;
			ptr->prev=head;
			head->next=ptr;
			return;
		}
		ptr->data=var;
		ptr->next=head->next;
		head->next->prev=ptr;
		ptr->prev=head;
		head->next=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
			break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Elements not found\n");
		return;
	}
	ptr->data=var;
	ptr->next=temp->next;
	if(temp->next!=NULL)
	temp->next->prev=ptr;
	temp->next=ptr;
	ptr->prev=temp;
	

}
//--------------------------------------------------------------------Add before the node---------------------------------------------------
void add_before_node(int num,int var)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			ptr->data=var;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
			return;
		}
		ptr->data=var;
		ptr->prev=NULL;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		return;
	}
	temp=head->next;
	while(temp!=NULL)
	{
		if(temp->data==num)
			break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Elements not found\n");
		return;
	}
	ptr->data=var;
	ptr->next=temp;
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
	if(temp->prev!=NULL)
		temp->prev=ptr;
}
//--------------------------------------------------------------------Delete particular node---------------------------------------------------
void delete_particular(int num)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		return;
		
	}
	temp=head->next;
	while(temp!=NULL)
	{
		if(temp->data==num)
		break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Element not found\n");
		return;
	}
	if(temp->next!=NULL)
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	free(temp);

}
//--------------------------------------------------------------------Create the list---------------------------------------------------
void create_list(int *iptr,int n)
{
	struct node *start=NULL,*p,*temp,*ptr;
	int i;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("List is empty\n");
			return;
		}
		ptr->data=iptr[i];
		if(start==NULL)
		{
			ptr->prev=NULL;
			start=ptr;
			ptr->next=NULL;
			p=ptr;
		}
		else
		{
			ptr->prev=p;
			p->next=ptr;
			ptr->next=NULL;
			p=ptr;
		}
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=start;
	start->prev=temp;
}
//--------------------------------------------------------------------Delete entire list---------------------------------------------------
void delete_list()
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
		temp=head;
		head=head->next;
		if(temp->next!=NULL)
		temp->next->prev=NULL;
		free(temp);
		temp=head;
	}
}
//-------------------------------------------------------------------Selection sorting------------------------------------------------------
void selection_sorting()
{
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	return;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				if(p->next!=q)
				{
					temp=p->next;
					p->next=q->next;
					q->next=temp;
					temp=p->prev;
					p->prev=q->prev;
					q->prev=temp;
					if(p!=head)
					{

						q->prev->next=q;
						if(p->next!=NULL)
							p->prev->prev=q;
						p->prev->next=p;
						q->next->prev=q;
					}
					else
					{
						head=q;
						q->next->prev=q;
						p->prev->next=p;
						if(p->next!=NULL)
							p->next->prev=p;
					}

				}
				else
				{
					p->next=q->next;
					q->next=p;
					q->prev=p->prev;
					p->prev=q;
					if(p->next!=NULL)
						p->next->prev=p;
					if(p==head)
					{
						head=q;
						q->prev=NULL;
					}
					else
					{
						q->prev->next=q;
					}

				}
				temp=p;
				p=q;
				q=temp;

			}
		}
	}
}

















