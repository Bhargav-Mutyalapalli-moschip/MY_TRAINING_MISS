#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	struct node * next;
	int data;
};

struct node * insert(struct node *head,int num)
{
	struct node*temp,*ptr;
	temp=(struct node*)malloc(1*sizeof(struct node));
	temp->next=NULL;
	temp->data=num;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
		return head;
	}
}

int add(struct node *head ,int node1,int node2)
{
	struct node *temp;
	int count1=0,count2=0,f1=0,f2=0,data1,data2;
	if(head==NULL)
	{
		printf("the list is empty \n");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		count1++;
		count2++;
		if(count1==node1)
		{
			data1=temp->data;
			f1=1;
		}
		if(count2==node2)
		{
			data2=temp->data;
			f2=1;
		}
		temp=temp->next;
	}
	if(f1==0||f2==0)
	{
		printf("the list is not enough to find the given nodes \n");
		return 0;
	}
	return(data1+data2);
}
			



int main()
{
	int opt,num,pos1,pos2,ret;
	struct node *head=NULL;
	while(1)
	{
		printf("\n\t >>>>> menu <<<<<< \n0-exit \n1-insert \n2-add \nselect the options :");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:
			       printf("\nenter the number to add : ");
			       scanf("%d",&num);
			       head=insert(head,num);
			       break;
			case 2:
			       printf("\nenter the nodes position to add : ");
			       scanf("%d%d",&pos1,&pos2);
			       ret=add(head,pos1,pos2);
			       printf("the result : %d \n",ret);
			       break;
		}
	}
}
			       
