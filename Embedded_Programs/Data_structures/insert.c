#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	struct node *prev;
	int data;
	int pr;
	struct node *next;
};
struct node *head=NULL;
void insert(int num,int prior)
{
	int flag1=0,flag2=0,flag4=0;
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate in heap\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->pr=prior;
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;                              //only if list contains no elements//
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->pr==prior)
		{
			if(temp->next!=NULL)
			{
				if(temp->next->pr!=prior)
				{
					flag1=1;
					break;
				}
			}
		}
		if(temp->pr > prior)
		{
			break;
		}
		if(temp->next==NULL)
		{
			flag2=2;
			break;
		}
		temp=temp->next;
	}
	if(flag1==1 || flag2==2)                //add after node//
	{
		ptr->next=temp->next;
		ptr->prev=temp;
		if(temp->next!=NULL)
			ptr->next->prev=ptr;
		temp->next=ptr;
		return;
	}
	if(temp->pr > prior)                                //add before node//
	{
		ptr->next=temp;
		ptr->prev=temp->prev;
		if(temp->prev!=NULL)
		temp->prev->next=ptr;
		temp->prev=ptr;
		if(temp==head)
			head=ptr;
		return;
	}


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
		printf("The data:%d-------The prioirity value:%d\n",temp->data,temp->pr);
		temp=temp->next;
	}
}
void swap_link(int num1,int num2);
void selection_sort();
void create_list(int *arr,int count);
void bubble_sort();
int main()
{
	int i,prog,num,prior,num2,var,*ptr,j=0,k=0;
	while(1)
	{
		printf("...................P_queue-------\n");
		printf("0.exit\n1.insert\n2.display\n3.Swap the links\n4.Selection sort\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);
			case 1:
				printf("Insert\n");
				printf("enter data\n");
				scanf("%d",&num);
				__fpurge(stdin);
				printf("enter priority\n");
				scanf("%d",&prior);
				insert(num,prior);
				break;
			case 2:
				printf("Display\n");
				display_data();
				break;

			case 3:
				printf("Swap the nodes\n");
				scanf("%d%d",&num,&num2);
				swap_link(num,num2);
				break;

			case 4:
				printf("Sorting\n");
			//	scanf("%d",&num);
				selection_sort();
				break;

			case 5:
				printf("Create the list\n");
				printf("entire the size of the array\n");
				__fpurge(stdin);
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
					{
						k++;
						printf("Enter the data in %d position\n",k);
					}
					else
					{
						j++;
						printf("Enter the priority value in %d position\n",j);
					}
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,num);
				free(ptr);
				break;

			case 6:
				printf("Sorting\n");
                                bubble_sort();
				break;
		}
	}
}
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
		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;

		temp=p->next;
		p->next=q->next;
		q->next=temp;

		if(p!=head)
		q->prev->next=q;
		else
			head=q;

		q->next->prev=q;

		p->prev->next=p;

		if(p->next!=NULL)
		p->next->prev=p;
	}
	else
	{
		p->next=q->next;
		q->next=p;
		q->prev=p->prev;
		p->prev=q;
		if(p!=head)
			q->prev->next=q;
		else
			head=q;
		if(p->next!=NULL)
		p->next->prev=p;
	}



}
void selection_sort(int num)
{
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->pr==q->pr)
			{
				if(p->data > q->data)
				{
					//if(p->next!=q)
					//{
						temp=p->prev;
						p->prev=q->prev;
						q->prev=temp;

						temp=p->next;
						p->next=q->next;
						q->next=temp;

						if(p!=head)
							q->prev->next=q;
						else
							head=q;

						q->next->prev=q;

						p->prev->next=p;

						if(p->next!=NULL)
							p->next->prev=p;
					//}
					/*else
					{
						p->next=q->next;
						q->next=p;
						q->prev=p->prev;
						p->prev=q;
						if(p!=head)
							q->prev->next=q;
						else
							head=q;
						if(p->next!=NULL)
							p->next->prev=p;
					}*/
					temp=p;
					p=q;
					q=temp;
				}
			}
			else
				break;

		}
	}
}
void bubble_sort()
{
	struct node *p,*q,*temp,*e;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(e=NULL;head->next!=e;e=q)
	{
		for(p=head;p->next!=e;p=p->next)
		{
			q=p->next;
			if(p->data > q->data)
			{
				p->next=q->next;
				q->next=p;
				q->prev=p->prev;
				p->prev=q;
				if(p!=head)
					q->prev->next=q;
				else
					head=q;
				if(p->next!=NULL)
					p->next->prev=p;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}
void create_list(int *arr,int count)
{
	int i;
	int flag1=0,flag2=0,flag4=0;
	struct node *ptr,*temp;
	for(i=0;i<count;i=i+2)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate in heap\n");
			exit(-1);
		}
		ptr->data=arr[i];
		ptr->pr=arr[i+1];
		if(head==NULL)
		{
			ptr->prev=NULL;
			ptr->next=NULL;
			head=ptr;
			//only if list contains no elements//
		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->pr==arr[i+1])
				{
					if(temp->next!=NULL)
					{
						if(temp->next->pr!=arr[i+1])
						{
							flag1=1;
							break;
						}
					}
				}
				if(temp->pr > arr[i+1])
				{
					break;
				}
				if(temp->next==NULL)
				{
					flag2=2;
					break;
				}
				temp=temp->next;
			}
			if(flag1==1 || flag2==2)                //add after node//
			{
				ptr->next=temp->next;
				ptr->prev=temp;
				if(temp->next!=NULL)
					ptr->next->prev=ptr;
				temp->next=ptr;

			}
			else if(temp->pr > arr[i+1])                                //add before node//
			{
				ptr->next=temp;
				ptr->prev=temp->prev;
				if(temp->prev!=NULL)
					temp->prev->next=ptr;
				temp->prev=ptr;
				if(temp==head)
					head=ptr;

			}
		}
	}
}
void delete_priority(int p)
{
	struct node *temp;
	if(head==NULL)
	{
















