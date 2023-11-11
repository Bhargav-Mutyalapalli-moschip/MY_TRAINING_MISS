#include<stdio.h>
struct node
{
	int data;
	int freq;
	struct node *link;

};
struct node *head=NULL;
void display_nodes();
void add_at_begin(int num);
int main()
{
	int pos,opt,data_value,value,num,*ptr,i,var;
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\tMENU\t\n\n\n\n\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Select the option<<<<<<<<<<<<<<<<<<<\n\n\n");
		printf("0.Exit the program\n\n1.ADD at begin\n\n2.Delete at begin\n\n3.Display the node\n\n4.count the nodes\n\n5.search the nodes\n\n6.add at last\n\n7.Delete at last\n\n11.Reverse\n\n14.Delete entire list\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("Succesfully executed the program\n");
				exit(0);

			case 1:
				printf("Enter the element to perform the add at beginning operation\n");
				scanf("%d",&data_value);
				add_at_begin(data_value);
				break;

			case 2:
				printf("delete at begin\n");
				delete_at_begin();
				break;

			case 3:
				printf("display the nodes\n");
				display_nodes();
				break;


}
void add_at_begin(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	head=temp->link;
	free(temp);
}
void display_nodes()
{
	int count=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(count==0)

		printf("The output data:%d\n",temp->data);
		temp=temp->link;
	}
}

