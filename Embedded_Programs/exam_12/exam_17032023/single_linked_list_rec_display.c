#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL,*well=NULL,*done=NULL,*res=NULL;
struct node **dptr=NULL;
int i=0;
struct node* create_list(struct node *,int *,int);

struct node* temp;
int c=0;
int rec_display(struct node *head)
{
/*	if(head==NULL)
	{
	//	printf("list is empty \n");
		return 0;
	}
	printf("%d \t",head->data);
	rec_display(head->link);
	return 0;
	*/

	temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return 0;
	}

	if(temp==NULL)
	{
		return -1;
	}

	printf("%d  ",temp->data);
	temp=temp->link;
	
	if(c!=-1)
	{
		c=rec_display(temp);
	}
	return 0;

}

struct node* selection_sort(struct node *);
struct node* bubble_sort(struct node*);
int main()
{
	int opt,dum,num,n,nodes,i,snum;
	int *ptr;
	while(1)
	{
		printf("\n\t*****  menu  *****\n0 -exit \n1 -creating the list \n2 -adding the node at beginning \n3 -deleting the node at beginning \n4 -displaying the data in nodes \n5 -count the nodes \n6 -search the data \n7 -delete the list \n8 -delete at last node \n9 -add the node at last \n10-add the node after selected node\n11-add the node before selected node \n12-delete purticular node \n13-reverse the list \n14-swaping the seleted nodes \n15-delete duplicate nodes\n16-merge sort \n17-selection sorting \n18-bubble sorting \n20-recursive_display \n\nselect the option : ");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("\n\tthe sucessfull termination of program\n\n");
				exit(0);
			case 1:
				printf("enter the no of nodes :");
				__fpurge(stdin);
				scanf("%d",&n);
				ptr=(int *)malloc(n*sizeof(int));
				if(ptr==NULL)
				{
					printf("\n\tfailed to allocate memory\n\n");
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					printf("enter the data : ");
					scanf("%d",&ptr[i]);
				}
				head=create_list(head,ptr,n);
				free(ptr);
				break;

			case 20:
				num=rec_display(head);
			default:
				printf("\n\tEnter the valid option\n\n");
		}
	}
}
//        **************  fun to create the node  ****************
struct node* create_list(struct node *head1,int *iptr,int n)
{
	int i;
	struct node *prev,*start=NULL,*temp;
	for(i=0;i<n;i++)
	{
		struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("\n\tfailed to allocate memory\n\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(start==NULL)
		{
			start=ptr;
		}
		else 
			prev->link=ptr;
		prev=ptr;
	}	
	if(head1==NULL)
	{
		head1=start;
		return head1;
	}
	temp=head1;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}	
	temp->link=start;
	return head1;
}

		//       ************************      end      ***************************
