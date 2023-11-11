#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct MISS_ES_0423_node
{
	struct MISS_ES_0423_node *prev;
	int data;
	int power;
	struct MISS_ES_0423_node *next;
};
struct MISS_ES_0423_node *head=NULL;
struct MISS_ES_0423_node *head1=NULL;
struct MISS_ES_0423_node *head2=NULL;
void insert_operation(int num,int prior);
void display();
void form_an_equation(int opt);
void display_equation(struct MISS_ES_0423_node *header);
void add_equation(struct MISS_ES_0423_node *head3,struct MISS_ES_0423_node *head4);
int main()
{
	int opt;
	int prog,var,num,i,*ptr,*pptr;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>>>Priority queue implementataion<<<<<<<<<<<<<<<<\n");
		printf("\t0.Exit from the program\n\t1.Insert operation\n\t2.Display \n\t3.Form an equation\n\t4.Create the queue\n\t5.Sortings\n\t6.Frequency of the priority\n");
		__fpurge(stdin);
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Successfully executed by user\n");
				exit(0);



			case 1:
				printf("Insert operation\n");
				printf("Enter the data\n");
				scanf("%d",&num);
				printf("Enter the power\n");
				__fpurge(stdin);
				scanf("%d",&var);
				insert_operation(num,var);
				break;

			case 2:
				printf("Display operation\n");
				display();
				break;

			case 3:
				printf("Form an equtaion\n");
				scanf("%d",&opt);
				form_an_equation(opt);
				break;

			case 4:
				printf("Dsiplay_equation\n");
			        display_equation(head1);
			        display_equation(head2);
			        display_equation(head);
				break;

			case 5:
				printf("Add equation\n");
				add_equation(head1,head2);
				break;

		}
	}
}
void insert_operation(int data,int pow)
{
	struct MISS_ES_0423_node *temp,*ptr;
	ptr=(struct MISS_ES_0423_node *)malloc(sizeof(struct MISS_ES_0423_node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=data;
	ptr->power=pow;
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->power==pow)
		{
			temp->data=temp->data+data;
			return;

			
		}
		if(temp->power < pow)
		{
			break;
		}
		temp=temp->next;
	}
	if(temp->power > pow)
	{
		ptr->prev=temp;
		ptr->next=temp->next;
		if(temp->next!=NULL)                 //----If the priority in the queue are same only then you have to check the this condition also------
			temp->next->prev=ptr;
		temp->next=ptr;
		return;
	}
	if(temp->power < pow)
	{
		ptr->prev=temp->prev;
		ptr->next=temp;
		if(temp->prev!=NULL)                 //if more than single node is present then condition is true
			temp->prev->next=ptr;
		temp->prev=ptr;
		if(temp==head)
			head=ptr;
		return;
	}
}
void display()
{
	struct MISS_ES_0423_node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("The data:%d-----------The power:%d\n",temp->data,temp->power);
		temp=temp->next;
	}
}
void form_an_equation(int opt)
{
	if(opt==1)
	{
		head1=head;
		head=NULL;
	}
	else
	{
		head2=head;
		head=NULL;
	}
}
void display_equation(struct MISS_ES_0423_node *header)
{
	struct MISS_ES_0423_node *temp;
	if(header==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=header;
	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		printf("%d^%d + ",temp->data,temp->power);
		else 
		printf("%d^%d\n",temp->data,temp->power);
		temp=temp->next;
	}
}
void add_equation(struct MISS_ES_0423_node *head3,struct MISS_ES_0423_node *head4)
{
	struct MISS_ES_0423_node *temp1,*temp2;
	if(head3==NULL  && head4==NULL)
	{
		printf("One of the list is empty\n");
		return;
	}
	head=head3;
	temp1=head3;
	temp2=head4;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->power==temp2->power)
		{
			temp1->data=temp1->data+temp2->data;
			

			
		}
		else if(temp1->power < temp2->power)
		{
			temp2->prev=temp1;
			temp2->next=temp1->next;
			if(temp1->next!=NULL)                 //----If the priority in the queue are same only then you have to check the this condition also------
				temp1->next->prev=temp2;
			temp1->next=temp2;
		}
		else if(temp1->power < temp2->power)
		{
			temp2->prev=temp1->prev;
			temp2->next=temp1;
			if(temp1->prev!=NULL)                 //if more than single node is present then condition is true
				temp1->prev->next=temp2;
			temp1->prev=temp2;
			if(temp1==head)
				head=temp2;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
}











