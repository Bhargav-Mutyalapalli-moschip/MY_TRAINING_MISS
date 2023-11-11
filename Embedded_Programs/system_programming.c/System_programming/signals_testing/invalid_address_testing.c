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
void frequency();
void delete_priority(int num);
void delete_priority_data(int prior,int var);
void delete_entire_queue();
void create_list(int *iptr,int n);
void selection_sorting();
void selection_sorting_data();
void selection_sorting_link();
void delete_first_priority(int num);
struct node *head=NULL;
int main()
{
	char opt;
	int prog,num,var,p_value,*ptr,i,k=0,j=0;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>Queue implementation<<<<<<<<<<<<\n");
		printf(">>>>>>>>>>>Select the option<<<<<<<<<<<<<<\n");
		printf("\n\t0.Exit the program\n\n\t1.Insert operation\n\n\t2.Display\n\n\t3.Find the frequency\n\n\t4.Delete operation\n\n\t5.Create the list\n\n\t6.Sorting methods\n\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:
				printf("Succesfully executed by user\n");
				struct node *temp;
				if(head==NULL)
				{
					printf("Queue is empty\n");
					exit(0);
				}
				while(head!=NULL)
				{
					temp=head;
					head=head->next;
					free(temp);
				}
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
				while(1)
				{
					printf("---------------------Display-----------------\n");
					printf("\n\tq.Quit from display\n\ta.Display based priority\n\tb.Overall display\n");
					scanf("%c",&opt);
					__fpurge(stdin);
					if(opt=='q')
						break;
					switch(opt)
					{

						case 'a':
							printf("display based on priority\n");
							scanf("%d",&num);
							display_prior(num);
							break;
						case 'b':
							printf("Overall display\n");
							display();
							break;

					}
					
				}
				break;
			case 3:
				printf("Finding the frequency for the priority\n");
				frequency();
				break;

			case 4:
				while(1)
				{
					printf(".....................Delete operations...............\n");
					printf("\n\tQ.Quit the program\n\tA.Delete the first priority\n\tB.Delete the priority list\n\tC.Delete the priority and data\n\tD.Delete the overall complete list\n");
					scanf("%c",&opt);
					__fpurge(stdin);
					if(opt=='Q')
						break;
					switch(opt)
					{
						case 'A':
							printf("Delete the first priority\n");
							scanf("%d",&num);
							delete_first_priority(num);
							break;

						case 'B':
							printf("Delete the priority\n");
							scanf("%d",&num);
							delete_priority(num);
							break;

						case 'C':
							printf("Delete  with priority and data\n");
							scanf("%d%d",&num,&var);
							delete_priority_data(num,var);
							break;

						case 'D':
							printf("Entire Queue\n");
							delete_entire_queue();
							break;

					}
					
				}
				break;
			case 5:
				printf("Create the list\n");
				printf("entire the size of the array\n");
				scanf("%d",&num);
				__fpurge(stdin);
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(-1);
				}
				num=num+num;
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
				while(1)
				{
					printf("*********************Sorting*****************\n");
					printf("\n\tq.Quit the program\n\ta.Sorting ---Exchange by data\n\tb.Sorting---Exchange by link\n\tc.Overall sorting\n");
					scanf("%c",&opt);
					__fpurge(stdin);
					if(opt=='q')
						break;
					switch(opt)
					{
						case 'a':
							printf("Sorting --Exchange by data\n");
							selection_sorting_data();
							break;

						case 'b':
							printf("Sorting --Exchange by link\n");
							selection_sorting_link();
							break;

						case 'c':
							printf("Overall sorting\n");
							selection_sorting();
							break;

					}
					
				}
				break;
			default:
				printf("Invalid option\n");


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
		if(temp->freq > 0)
		printf("The data in queue:%d--------The priority values is:%d---------The freq is:%d\n",temp->data,temp->prior_value,temp->freq);
		else
		printf("The data in queue:%d--------The priority values is:%d\n",temp->data,temp->prior_value);
		temp=temp->next;
	}
}
void display_prior(int num)
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
		if(temp->prior_value==num)
		{
			if(temp->freq > 0)
			printf("The prior value is :%d--------The data is:%d--------The freq:%d\n",num,temp->data,temp->freq);
			else
			printf("The prior value is :%d--------The data is:%d\n",num,temp->data);
		}
		temp=temp->next;
	}
}
void frequency()
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
		count=1;
	}
}

void delete_priority(int num)
{
	struct node *temp,*var;
	if(head==NULL)
	{
		printf("Queue is empty\n");
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
void delete_first_priority(int num)
{
	struct node *temp,*var;
	if(head==NULL)
	{
		printf("Queue is empty\n");
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
			return;

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
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior_value==prior && temp->data==val)
		{
			if(temp==head)
			{
				head=head->next;
				free(temp);
				return;
			}
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
		printf("Queue is empty\n");
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
		

			}
			else if(temp->prior_value < iptr[i+1])
			{
				ptr->prior_value=iptr[i+1];
				ptr->prev=temp;
				ptr->next=temp->next;
				temp->next=ptr;
			
				
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
	for(p=head;p!=NULL;p=p->next)
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
						q->prev->next=q;

					else
						head=q;
					if(p->next!=NULL)
						p->next->prev=p;
					p->prev->next=p;
					q->next->prev=q;


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
void selection_sorting_link()
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
			if(p->prior_value==q->prior_value)
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
			else
				break;
		}
	}
}
void selection_sorting_data()
{
	int var;
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
			if(p->prior_value==q->prior_value)
			{
				if(p->data > q->data)
				{
					var=p->data;
					p->data=q->data;
					q->data=var;

				}
			}
			else
				break;
		}
	}
}














