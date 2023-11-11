#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void add_at_begin(int num);
void display();
void delete_at_begin();
void create_list(int *iptr,int n);
void reverse();
void delete_particular_node(int num);
void delete_duplicates();
void swap_link(int num1,int num2);
void swap_data(int num1,int num2);
void selection_sorting();
void bubble_sort();
int main()
{
	int prog,num,*ptr,i,var;
	while(1)
	{
		printf("----------------------------Circular list----------------\n");
		printf("0.Exit the program\n1.Add at beginning\n2.Display\n3.Delete at begin\n4.Create the list\n5.reverse the lsit\n6.Delete the particular node \n7.Delete duplicates\n8.Swap by link\n9.Swap by data\n10.Selection sorting\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Succesfull termination of program\n");
				exit(0);

			case 1:
				printf("Add at begin\n");
				printf("Enter the to be add--:\n");
				scanf("%d",&num);
				add_at_begin(num);
				break;

			case 2:
				printf("The display\n");
				display();
				break;

			case 3:
				printf("Delete_at_begin\n");
				delete_at_begin();
				break;

			case 4:
				printf("Create the list\n");
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

			case 5:
				printf("Reverse the list\n");
				reverse();
				break;

			case 6:
				printf("Delete particular node\n");
				scanf("%d",&num);
                                delete_particular_node(num);
				break;

			case 7:
				printf("Delete duplicates\n");
				delete_duplicates();
				break;

			case 8:
				printf("Swapy link\n");
			        scanf("%d%d",&num,&var);	
                                swap_link(num,var);
				break;

			case 9:

				printf("Swap data\n");
			        scanf("%d%d",&num,&var);	
                                swap_data(num,var);
				break;

			case 10:
				printf("Selection sort\n");
				selection_sorting();
				break;

			case 11:
				printf("bubble sort\n");

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
	if(head==NULL)
	{
		ptr->data=num;
		ptr->link=head=ptr;
		return;
	}
	ptr->data=num;
	ptr->link=head;
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=head=ptr;
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
	while(temp->link!=head)	
	{
		printf("The data:%d\n",temp->data);
		temp=temp->link;
	}
	printf("The data:%d\n",temp->data);
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
        temp->link=head->link;
        free(head);	
	head=temp->link;
}
void create_list(int *iptr,int n)
{
	int i;
	struct node *temp,*ptr;
	for(i=0;i<n;i++)
	{
		temp=head;
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		if(head==NULL)
		{
			head=ptr->link=ptr;
		}
		else
		{
			while(temp->link!=head)
			{
				temp=temp->link;
			}
			if(temp->link==head)
			{
				temp->link=ptr;
				ptr->link=head;
			}

		}
	}
}
void add_at_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
}
void reverse()
{
	struct node *cur,*prev,*next;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=head;
	cur=head;
	while(cur->link!=head)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	next=cur->link;
	cur->link=prev;
	next->link=cur;
	head=cur;
}
void delete_particular_node(int num)
{
	int flag=0;
	struct node *temp,*start;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==head)
		{
			free(head);
			head=NULL;
			return;
		}
		start=temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}
		head=head->link;
		temp->link=head;
		free(start);
		return;
	}
	start=head;
	temp=head->link;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			flag=1;
			break;
		}
		start=temp;
		temp=temp->link;
	}
	if(flag==0)
	{
		printf("Element is not found\n");
		return;
	}
	start->link=temp->link;
	free(temp);
}
void delete_duplicates()
{
	struct node *cur,*prev,*start;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==head)
	{
		printf("only one element is present\n");
	        return;
	}
	for(start=prev=head;start->link!=head;start=start->link)
	{
		cur=start->link;
		do
		{
			if(start->data==cur->data)
			{
				prev->link=cur->link;
				free(cur);
				cur=prev;
			}
			prev=cur;
			cur=cur->link;
		}
		while(cur!=head);
	}
	/*if(start->data == cur->data)
	{
		prev->link=cur->link;
		free(cur);
		cur=prev;
	}*/


}
void swap_link(int num1,int num2)
{
	int flag1=2,flag2=0,pos1=0,pos2=0;
	struct node *p,*q,*s,*r,*temp,*point;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2)
	{
		printf("Same elements swap is not needed\n");
		return;
	}
	p=q=head;
	do
	{
		pos1++;
		if(p->data==num1)
		{
			flag1=1;
			break;
		}
		r=p;
		p=p->link;
	}
	while(p!=head);
	do
	{
		pos2++;
		if(q->data==num2)
		{
			flag2=1;
			break;
		}
		s=q;
		q=q->link;
	}
	while(q!=head);
	if(flag1!=flag2)
	{
		printf("Elements not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p->link!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)
		{
			r->link=q;
		}
		else
		{
			point=head;
			while(point->link!=head)
			{
				point=point->link;
			}
			point->link=q;
			head=q;
		}
		s->link=p;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p!=head)
		{
			r->link=q;
		}
		else
		{

			point=head;
			while(point->link!=head)
			{
				point=point->link;
			}
			point->link=q;
			head=q;
			
			

		}
	}

}
void swap_data(int num1,int num2)
{
	int flag1=0,flag2=0,pos1=0,pos2=0,var;
	struct node *p,*q,*s,*r,*temp,*point;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
	do
	{
		pos1++;
		if(p->data==num1)
		{
			flag1=1;
			break;
		}
		r=p;
		p=p->link;
	}
	while(p!=head);
	do
	{
		pos2++;
		if(q->data==num2)
		{
			flag2=1;
			break;
		}
		s=q;
		q=q->link;
	}
	while(q!=head);
	if(flag1!=flag2)
	{
		printf("Elements not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	var=p->data;
	p->data=q->data;
	q->data=var;
	
}
/*void selection_sorting()
{
	struct node *p,*r,*q,*s,*temp,*point;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=r=head;p->link!=head;r=p,p=p->link)
	{
		for(s=q=p->link;q!=head;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				if(p->link!=q)
				{
					temp=p->link;
					p->link=q->link;
					q->link=temp;
					if(p!=head)
					{
						r->link=q;
					}
					else
					{
						point=head;
						while(point->link!=head)
						{
							point=point->link;
						}
						point->link=q;
						head=q;
					}
					s->link=p;
				}
				else
				{
					p->link=q->link;
					q->link=p;
					if(p!=head)
					{
						r->link=q;
					}
					else
					{
						point=head;
						while(point->link!=head)
						{
							point=point->link;
						}
						point->link=q;
						head=q;



					}
				}
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}*/
void bubble_sort()
{
	struct node *e,*p,*q,*temp,*point,*r;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(e=head;head->link !=e ;e=p)
	{
		for(r=p=head;p->link!=e;r=p,p=p->link)
		{
			q=p->link;
			if(p->data > q->data)
			{
				p->link=q->link;
				q->link=p;
				if(p!=head)
				{
					r->link=q;
				}
				else
				{
					point=head;
					while(point->link!=head)
					{
						point=point->link;
					}
					point->link=q;

					head=q;
					e=head;
				}
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}

void selection_sorting()
{
	struct node *p,*r,*q,*s,*temp,*point;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=r=head;p->link!=head;r=p,p=p->link)
	{
		for(s=q=p->link;q!=head;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				temp=p->link;
				p->link=q->link;
				q->link=temp;
				if(p!=head)
				{
					r->link=q;
				}
				else
				{
					point=head;
					while(point->link!=head)
					{
						point=point->link;
					}
					point->link=q;
					head=q;
				}
				s->link=p;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}


























