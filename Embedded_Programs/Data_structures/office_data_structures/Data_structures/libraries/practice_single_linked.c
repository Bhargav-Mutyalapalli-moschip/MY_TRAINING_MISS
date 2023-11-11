#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void addatbeg(int num)
{
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
void addatend(int num)
{
	struct node *temp;
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=ptr;
}
void deleteatend()
{
	struct node *temp;
	struct node *prev;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		free(head);
		head=NULL;
	}
	prev=head;
	temp=head->link;
	while(temp->link!=NULL)
	{
		prev=temp;
		temp=temp->link;
	}
	free(temp);
	prev->link=NULL;
}
void deleteatbeg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	free(temp);
	printf("deleted at beginning\n");
}
void addafternode(int num,int val)
{
	struct node *temp,*ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if((temp->data)==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}	
		temp=temp->link;
	}
	printf("Element not found\n");
}
void addbeforenode(int num,int val)
{ 
	struct node *temp,*ptr,*prev;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate\n");
			exit(1);
		}
		ptr->data=val;
		ptr->link=head;
		head=ptr;
		return;
	}
	prev=head;
	temp=prev->link;
	while(temp!=NULL)
	{
		if((temp->data)==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp;
			ptr->link=ptr;
			return;
		}
		prev=temp;
		temp=temp->link;
	}
	printf("Element not found\n");
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
		printf("%d\n",temp->data);
		temp=temp->link;
	}

}
void reverselist()
{
	struct node *prev,*cur,*next;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=0)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head=prev;

}
void duplicate()
{
	struct node *temp,*prev;
	if(head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	temp=head;
	prev=temp;
	while(temp!=NULL);
	{

	}
}
void count()
{
	int c=0;
	struct node*temp;
	if(head==NULL)
	{
		printf("List is empty so count is\"0\"\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	printf("the count is:%d\n",c);
}
void search(int num)
{
	struct node*temp;
	int i=1,c=0;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data!=num)
		{
			i++;
		}
		else
		{
			printf("The element is found at node: %d\n",i);
			i++;
			c++;
		}
		temp=temp->link;
	}
	if(c==0)
		printf("the searched element: %d is not found at any node\n",num);
}
void dellist()
{
	struct node *temp;
	struct node *prev;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		prev=temp;
		if(prev!=NULL)
		{
			temp=temp->link;
			free(prev);
		}
	}
	head=NULL;
}
void createlist(int* ptr,int num)
{
	struct node* iptr,*temp,*prev,*start=NULL;
	int i;
	for(i=0;i<num;i++)
	{
		iptr=(struct node*)malloc(sizeof(struct node));
		if(iptr==NULL)
		{
			printf("failed to allocate memory\n");
		}
		iptr->data=ptr[i];
		iptr->link=NULL;
		if(start==NULL)
		{
			start=iptr;
		}
		else
		{
			prev->link=iptr;
		}
		prev=iptr;
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;	
	}
	temp->link=start;
}
void swap_by_data(int num,int val)
{
	int temp;
	struct node *f,*s;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(num==val)
	{
		return;
	}
	s=f=head;
	while(f!=NULL)
	{
		if(f->data==num)
		{
			break;
		}
		f=f->link;
	}
	while(s->link!=NULL)
	{
		if(s->data==val)
		{
			break;
		}
		s=s->link;
	}
	if(f==NULL||s==NULL)
	{
		return;
	}
	temp=f->data;
	f->data=s->data;
	s->data=temp;
}
void del_part_node(int num)
{
	struct node *prev,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)//one node is present
	{
		if(head->link==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		cur=head;
		head=head->link;
		free(cur);
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("Element not found\n");
}
void swap_by_link(int num,int val)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(num==val)
	{
		return;
	}
	if(head==NULL)
	{
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
	temp=p->link;
	p->link=q->link;
	q->link=temp;
	if(p==head)
	{
		head=q;
	}
	else
		r->link=q;
	return;
}
}
int main()
{
	int num,pos,opt,val;
	while(1)
	{
		printf("Menu\n");
		printf("0.exit\n1.add at beginning\n2.delete at beggining\n3.display\n4.delete list\n5.count\n6.search\n7.add at ending\n8.delete at last\n9.Add after node\n10.Add before node\n11.reverse list\n12.create list\n13.swap by values\n14.delete particular node\n15.swap by links\n");	
		printf("****************************************************\n");
		printf("select option from above menu\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		printf("--------------------------------------\n");
		switch(opt)
		{
			case 0: exit(0);
			case 1:printf("Enter the data\n");
			       scanf("%d",&num);
			       addatbeg(num);
			       printf("--------------------------------------\n");
			       break;
			case 2:deleteatbeg();
			       printf("--------------------------------------\n");
			       break;
			case 3:display();
			       printf("--------------------------------------\n");
			       break;
			case 4:dellist();
			       printf("--------------------------------------\n");
			       break;
			case 5:count();
			       printf("--------------------------------------\n");
			       break;
			case 6:
			       printf("Enter the data to search\n");
			       scanf("%d",&num);
			       search(num);
			       printf("--------------------------------------\n");
			       break;
			case 7:printf("Enter the data\n");
			       scanf("%d",&num);
			       addatend(num);
			       printf("--------------------------------------\n");
			       break;
			case 8:deleteatend();
			       printf("--------------------------------------\n");
			       break;
			case 9:printf("Enter the data\n");
			       scanf("%d",&num);
			       __fpurge(stdin);
			       printf("enter the pos\n");
			       scanf("%d",&pos);
			       addafternode(pos,num);
			       printf("--------------------------------------\n");
			       break;
			case 10:printf("Enter the data\n");
				scanf("%d",&num);
				__fpurge(stdin);
				printf("enter the pos\n");
				scanf("%d",&pos);
				addbeforenode(pos,num);
				printf("--------------------------------------\n");
				break;
			case 11:
				reverselist();
				printf("--------------------------------------\n");
				break;
			case 12:printf("Enter the count elements in list\n");
				scanf("%d",&num);
				int *ptr;
				int i;
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("failed to allocate memory\n");
					exit(2);
				}
				for(i=0;i<num;i++)
				{
					printf("enter the list of data\n");
					scanf("%d",&ptr[i]);
				}
				createlist(ptr,num);
				free(ptr); 
				printf("--------------------------------------\n");
				break;
			case 13:
				printf("Enter the value of elements need to be swapped\n");
				scanf("%d %d",&num,&val);
				swap_by_data(num,val);
				printf("--------------------------------------\n");
				break;
			case 14:
				printf("Enter the element need to delete\n");
				scanf("%d",&num);
				del_part_node(num);
				printf("--------------------------------------\n");
				break;
			case 15:printf("Enter the value of elements need to be swapped\n");
				scanf("%d %d",&num,&val);
				swap_by_link(num,val);
				printf("--------------------------------------\n");
				break;

			default:
				printf("Invalid option selected please select correct option from menu\n");
				break;


		}
	}
}
