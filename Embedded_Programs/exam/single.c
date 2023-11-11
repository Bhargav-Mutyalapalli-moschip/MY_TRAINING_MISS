#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void insert_an_element(int num);
void display_data();
int search_element(int num);
void delete_duplicates();
void add_after_node(int s_value,int num);
void add_before_node(int s_value,int num);
void reverse_list();
void swap_data(int num1,int num2);
void swap_by_links(int num1,int num2);
void selection_sorting();
void bubble_sorting();
void create_list(int *iptr,int count);
int main()
{
	int prog,num,pos,*ptr,var,i;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>>>>>>Single linked list<<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Insert the data\n2.Display the data\n3.Search the elements\n4.Delete duplicates\n5.Add after the node\n6.Add before node\n7.Reverse the list\n8.Swap the data\n9.swap by link\n10.Selection sorting\n11.Bubble sort\n12.Create the list\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("The exit the program\n");
				exit(0);

			case 1:
				printf("The insert the data\n");
				scanf("%d",&num);
				insert_an_element(num);
				break;

			case 2:
				printf("To display the nodes\n");
				display_data();
				break;

			case 3:
				printf("The search the elemnt\n");
				scanf("%d",&num);
				pos=search_element(num);
				if(pos > 0)
				{
					printf("The element is:%d found at %d position\n",num,pos);
				}
				else
					printf("Element not found\n");
				break;

			case 4:
				printf("Delete duplicates\n");
				delete_duplicates();
				break;

			case 5:
				printf("Add after the node\n");
				printf("Enter the value to be searched\n");
				scanf("%d",&pos);
				printf("Enter the value to be add\n");
				scanf("%d",&num);
				add_after_node(pos,num);
				break;

			case 6:
				printf("Add after the node\n");
				printf("Enter the value to be searched\n");
				scanf("%d",&pos);
				printf("Enter the value to be add\n");
				scanf("%d",&num);
				add_before_node(pos,num);
				break;

			case 7:
				printf("reverse the list\n");
				reverse_list();
				break;

			case 8:
				printf("SwAP THE DATA\n");
				printf("Enter the value to be SAWP1\n");
				scanf("%d",&pos);
				printf("Enter the value to be SWAP2\n");
				scanf("%d",&num);
				swap_data(pos,num);
				break;

			case 9:
				printf("SwAP THE DATA\n");
				printf("Enter the value to be SAWP1\n");
				scanf("%d",&pos);
				printf("Enter the value to be SWAP2\n");
				scanf("%d",&num);
				swap_by_links(pos,num);
				break;

			case 10:
				printf(">>Selection Sorting<<\n");
				selection_sorting();
				break;

			case 11:
				printf(">>Bubble sorting<<\n");
				bubble_sorting();
				break;

			case 12:
				printf("Create the list\n");
				printf("Enter the size of the array to create\n");
				scanf("%d",&var);
				ptr=(int *)malloc(var*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(1);
				}
				printf("Enter the values\n");
				for(i=0;i<var;i++)
				{
					scanf("%d",&ptr[i]);
					__fpurge(stdin);
				}
				create_list(ptr,var);
				free(ptr);
				break;


		}
	}
}
void insert_an_element(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
void display_data()
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
		printf("The output:%d\n",temp->data);
		temp=temp->link;
	}
}
int search_element(int num)
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
		temp=temp->link;
	}
	return -1;
}
void delete_duplicates()
{
	struct node *p,*q,*s;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(1);
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
void add_after_node(int s_value,int num)
{
	printf("The search value:%d----The add value:%d\n",s_value,num);
	struct node *ptr,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(1);
	}
	ptr->data=num;
	if(head->data==s_value)
	{
		if(head->link==NULL)
		{
			ptr->link=head->link;
			head->link=ptr;
			return;
		}
		ptr->link=head->link;
		head->link=ptr;
		return;
	}
	cur=head->link;
	while(cur!=NULL)
	{

		if(cur->data==s_value)
		break;
		cur=cur->link;

	}
	if(cur==NULL)
	{
		printf("Element is not found\n");
		return;
	}
	ptr->link=cur->link;
	cur->link=ptr;
	


}
void add_before_node(int s_value,int num)
{
	printf("The search value:%d----The add value:%d\n",s_value,num);
	struct node *ptr,*cur,*prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(1);
	}
	ptr->data=num;
	if(head->data == s_value)
	{
		ptr->link=head;
		head=ptr;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data == s_value)
		break;
		prev=cur;
		cur=cur->link;
	}
	if(cur==NULL)
	{
		printf("Element is not found\n");
		return;
	}
	ptr->link=cur;
	prev->link=ptr;


		

}
void reverse_list()
{
	struct node *prev=NULL,*next,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	cur=head;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
}
void swap_data(int num1,int num2)
{
	int temp;
	struct node *p,*q;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2 || head->link==NULL)
	return;
	p=q=head;
	while(p!=NULL)
	{
		if(p->data==num1)
		break;
		p=p->link;
	}
	while(q!=NULL)
	{
		if(q->data==num2)
		break;
		q=q->link;
	}
	if(p==NULL || q==NULL)
	{
		printf("Element is not found\n");
		return;
	}
	temp=p->data;
	p->data=q->data;
	q->data=temp;
}
void swap_by_links(int num1,int num2)
{
	struct node *p,*q,*s,*r,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2 || head->link==NULL)
	return;
	p=q=head;
	while(p!=NULL)
	{
		if(p->data==num1)
		break;
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		if(q->data==num2)
		break;
		s=q;
		q=q->link;
	}
	if(p==NULL || q==NULL)
	{
		printf("Element is not found\n");
		return;
	}
	if(p->link!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)
		r->link=q;
		else
			head=q;
		s->link=p;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p!=head)
		r->link=q;
		else
		head=q;
	}
}
void selection_sorting()
{
	struct node *p,*q,*s,*r,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == NULL)
	{
		printf("Only sigle node is present\n");
		return;
	}
	for(r=p=head;p!=NULL;r=p,p=p->link)
	{
		for(s=q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				temp=p->link;
				p->link=q->link;
				q->link=temp;
				if(p!=head)
					r->link=q;
				else
					head=q;
				s->link=p;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}
void bubble_sorting()
{
	struct node *p,*q,*e,*r,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == NULL)
	{
		printf("Only sigle node is present\n");
		return;
	}
	for(e=NULL;head->link!=e;e=q)
	{
		for(r=p=head;p->link!=e;r=p,p=p->link)
		{
			q=p->link;
			if(p->data > q->data)
			{
				p->link=q->link;
				q->link=p;

				if(p!=head)
				r->link=q;
				else
				head=q;

				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}
void create_list(int *iptr,int count)
{
	int i;
	struct node *ptr,*start=NULL,*prev,*temp;
	for(i=0;i<count;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
	        if(ptr == NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(1);
		}
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(start==NULL)
		{
			start=ptr;
		}
		else
		{
			prev->link=ptr;
		}
		prev=ptr;
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	else
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=start;
	}
}









