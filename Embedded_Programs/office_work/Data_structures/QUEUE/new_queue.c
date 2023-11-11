#include<stdio.h>
#include<stdlib.h>
int count1;
struct node
{
	int data;
	struct node *link;
};
struct node *rear=NULL;
struct node *front=NULL;
void insert_data(int num);
void delete_data();
void display();
void count();
void delete_particular_element(int num);
void add_after_element(int num,int var);
void add_before_element(int num,int var);
void swap_link(int num1,int num2);
void selection_sorting();
void selection_sorting_link();
void bubble_sorting_link();
int main()
{
	int prog,num,var;
	while(1)
	{
		printf("*******************Queue implementation*****************\n");
		printf("0.Exit the program\n1.Insert operation\n2.Delete the data\n3.Display queue\n4.Count the queue elements\n5.Delete the particular\n6.Add after the element\n7.Add before element\n8.Swap by link\n9.Selection sorting\n10 election sorting by link");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Exit the progam\n");
				exit(0);

			case 1:
				printf("Insert the data\n");
				scanf("%d",&num);
				insert_data(num);
				break;

			case 2:
				printf("Delete the data\n");
				delete_data();
				break;

			case 3:
				printf("display\n");
				display();
				break;

			case 4:
				printf("COunt\n");
				count();
				break;

			case 5:
				printf("Delete the particular element\n");
				scanf("%d",&num);
				delete_particular_element(num);
				break;

			case 6:
				printf("Add after a particular element\n");
				scanf("%d%d",&num,&var);
				add_after_element(num,var);
				break;

			case 7:
				printf("Add after a particular element\n");
				scanf("%d%d",&num,&var);
				add_before_element(num,var);
				break;

			case 8:
				printf("Swap by link for a particular elements\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

			case 9:
				printf("Selection sorting of exchange data\n");
				selection_sorting();
				break;

			case 10:

				printf("Selection sorting of exchange data\n");
				selection_sorting_link();
				break;

			case 11:
				printf("Bubble sorting of exchange data\n");
				bubble_sorting_link();
				break;

				

		}
	}
}
void insert_data(int num)
{
	struct node *temp;
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(rear==NULL)
	{
		front=rear=ptr;
	}
	rear->link=ptr;
	rear=ptr;
}
void delete_data()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	front=front->link;
	free(temp);
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
	while(temp!=rear->link)
	{
		printf("The Queue Data:-->>(%d)\n",temp->data);
		temp=temp->link;
	}
}
void count()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=rear->link)
	{
		count1++;
		temp=temp->link;
	}
	printf("The number of data in the Queue-->>%d\n",count1);
	count1=0;


}
void delete_particular_element(int num)
{
	struct node *prev,*cur,*temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(front->link==NULL)
		{
			free(front);
			front=rear=NULL;
			return;
		}
		temp=front;
		front=front->link;
		free(temp);
		return;
	}
	prev=front;
	cur=front->link;
	while(cur!=NULL)
        {
		if(cur->data==num)
		break;
		prev=cur;
		cur=cur->link;
	}
	if(rear->data==num)
	rear=prev;
	prev->link=cur->link;
	free(cur);
}
void add_after_element(int num,int var)
{
	struct node *prev,*cur,*temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(front->link==NULL)
		{
			ptr->data=var;
			ptr->link=rear->link;
			rear->link=ptr;
			rear=ptr;
			return;
		}
		ptr->data=var;
		ptr->link=front->link;
		front->link=ptr;
		return;
	}
	prev=front;
	cur=front->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
			break;
		prev=cur;
		cur=cur->link;
	}
	if(rear->data==num)
		rear=ptr;
	ptr->data=var;
	ptr->link=cur->link;
	cur->link=ptr;
}
void add_before_element(int num,int var)
{
	struct node *prev,*cur,*temp,*ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(front->link==NULL)
		{
			ptr->data=var;
			ptr->link=front;
			front=ptr;
			return;
		}
		ptr->data=var;
		ptr->link=front;
		front=ptr;
		return;
	}
	prev=front;
	cur=front->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
			break;
		prev=cur;
		cur=cur->link;
	}
	ptr->data=var;
	ptr->link=cur;
	prev->link=ptr;
}
void swap_link(int num1,int num2)
{
	int pos1=0,pos2=0;
	struct node *p,*q,*s,*r,*temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(rear==front && num1==num2)
	return;
	p=front;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num1)
		break;
		r=p;
		p=p->link;
	}
	q=front;
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)
		break;
		s=q;
		q=q->link;
	}
	if(p==NULL || q==NULL)
	{
		printf("\n\n\tElements are not found please give valid existed elements\n\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
		temp=r;
		r=s;
		s=temp;
	}
	if(p->link!=q)
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=front)
		r->link=q;
		else
			front = q;
		s->link=p;
		if(rear==q)
		rear=p;
		return;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p!=front)
		r->link=q;
		else
			front=q;
		if(rear==q)
			rear=p;
		return;
	}
}
void selection_sorting()
{
	int var;
	struct node *p,*q,*temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(rear==front)
	return;
	for(p=front;p!=NULL;p=p->link)
	{
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(p->data > q->data)
			{
				p->data=p->data ^ q->data;
				q->data=p->data ^ q->data;
				p->data=p->data ^ q->data;
			}
		}
	}
}
void selection_sorting_link()
{
	int var;
	struct node *p,*q,*temp,*s,*r;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(rear==front)
	return;
	for(p=r=front;p!=NULL;r=p,p=p->link)
	{
		for(s=q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				/*if(p->link!=q)
				{*/
					temp=p->link;
					p->link=q->link;
					q->link=temp;
					if(p!=front)
					r->link=q;
					else
						front=q;
					s->link=p;
				        if(rear==q)
					rear=p;
				//}
				/*else
				{
					p->link=q->link;
					q->link=p;
					if(p!=front)
					r->link=q;
					else
						front=q;
				        if(rear==q)
					rear=p;

				}*/
				temp=p;
				p=q;
				q=temp;
			}
		}
	}

}
void bubble_sorting_link()
{
	int var;
	struct node *p,*q,*temp,*r,*e;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(rear==front)
	return;
	for(e=NULL;front->link!=e;e=q)
	{
		for(r=p=front;p->link!=e;r=p,p=p->link)
		{
			q=p->link;
			if(p->data > q->data)
			{
				p->link=q->link;
				q->link=p;
				if(p!=front)
				r->link=q;
				else
					front=q;
				if(rear==q)
				rear=p;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}


	


