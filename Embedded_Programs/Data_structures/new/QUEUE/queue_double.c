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
void insert_queue(int num);
void delete_at_begin();
void display();
void add_at_last(int num);
void delete_at_last();
void duplicates();
int search(int num);
void count();
//void reverse();
void reverse_queue();
void swap_link(int num1,int num2);
void add_after_node(int num,int var);
void add_before_node(int num,int var);
void delete_particular(int num);
void selection_sorting();
struct node *rear=NULL;
struct node *front=NULL;
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.ADD at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.count the nodes\n\n5.search the nodes\n\n6.Duplicates\n\n7.Delete at last\n\n8.Count the nodes\n\n11.Reverse\n\n12.Selection sort\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				insert_queue(data_value);
				break;

			case 2:
				printf("delete at begin\n");
			//	delete_at_begin();
				break;

			case 3:
				printf("display the nodes\n");
				display();
				break;

			/*case 4:
				
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				add_at_last(data_value);
				break;

			case 5:
				printf("Delete at last \n");
				delete_at_last();
				break;*/

			case 6:
				printf("Duplicates\n");
				duplicates();
				break;

			/*case 7:
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
				break;*/

			case 9:
				printf("reverse the list\n");
				reverse_queue();
				break;

			case 10:
				printf("Swap by link\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

			/*case 11:
				printf("Add after a node\n");
				scanf("%d%d",&num,&var);
				add_after_node(num,var);
				break;

			case 12:

				printf("Add after a node\n");
				scanf("%d%d",&num,&var);
				add_before_node(num,var);
				break;

			case 13:
				printf("Delete particular node\n");
				scanf("%d",&num);
				delete_particular(num);
				break;*/

			case 14:
				printf("Selection sorting\n");
				selection_sorting();
				break;

			



		}
	}
}
void insert_queue(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->next=NULL;
	if(rear==NULL)
	{
		ptr->prev=NULL;
		rear=front=ptr;
		return;
	}
	ptr->prev=rear;
	rear->next=ptr;
	rear=ptr;
}
void display()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		printf("The queue data:%d\n",temp->data);
		temp=temp->next;
	}
}
void delete_particular(int num)
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(rear==front)
		{
			free(front);
			rear=front=NULL;
			return;
		}
		temp=front;
		front=front->next;
		front->prev=NULL;
		free(temp);
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		if(temp->data==num)
		break;
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
	temp->next->prev=temp->prev;
	if(temp==rear)
		rear=temp->prev;
	free(temp);
}
void reverse_queue()
{       
        struct node *temp,*p,*nxt;
        if(rear==NULL)
        {       
                printf("List is empty\n");
                return;
        }       
        p=front;
        while(p!=NULL)
        {
		nxt=p->next;
                temp=p->next;
                p->next=p->prev;
                p->prev=temp;
                if(p->prev==NULL)
		{
			rear=front;
			front=p;
		}
                p=nxt;
        }
}
void duplicates()
{
        struct node *p,*q,*temp;
        if(rear==NULL)
        {
                printf("List is empty\n");
                return;
        }
        if(front->next==NULL)
        return;
        for(p=front;p!=NULL;p=p->next)
        {
                for(q=p->next;q!=NULL;q=q->next)
                {
                        if(p->data==q->data)
                        {
				temp=q;
				q->prev->next=q->next;
				if(q->next!=NULL)
				q->next->prev=q->prev;
				if(rear==q)
				{
					rear=q->prev;
					rear->next=NULL;
				}
				q=q->prev;
				free(temp);
			}
		}
	}
}

void swap_link(int num1,int num2)
{
	int pos1=0,pos2=0;
	struct node *p,*q,*temp;
	if(front==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(num1==num2)
	return;
	if(front->next==NULL)
	return;
	p=q=front;
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
		if(p!=front)
		{

			q->prev->next=q;
			if(p->next!=NULL)
			p->prev->prev=q;
			else
				rear=p;
			p->prev->next=p;
			q->next->prev=q;
		}

		else
		{
			front=q;
		q->next->prev=q;
		p->prev->next=p;
		if(p->next!=NULL)
		p->next->prev=p;
		else
			rear=p;
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
		else
			rear=p;
		if(p==front)
		{
			front=q;
			q->prev=NULL;
		}
		else
		{
			q->prev->next=q;
		}

	}


}
	




void selection_sorting()
{
	struct node *p,*q,*temp;
	if(front==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(front->next==NULL)
	return;
	for(p=front;p->next!=NULL;p=p->next)
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
					if(p!=front)
					{

						q->prev->next=q;
						if(p->next!=NULL)
							p->prev->prev=q;
						else
							rear=p;
						p->prev->next=p;
						q->next->prev=q;
					}
					else
					{
						front=q;
						q->next->prev=q;
						p->prev->next=p;
						if(p->next!=NULL)
							p->next->prev=p;
						else
							rear=p;
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
					else
						rear=p;
					if(p==front)
					{
						front=q;
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












