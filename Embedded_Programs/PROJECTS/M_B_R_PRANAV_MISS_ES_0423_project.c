//-------------------------------------------------------------------Project work----------------------------------------
//-------Name : M.B.R.Pranav------------------
//--------Id no: MISS_ES_0423----------------

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct MISS_ES_0423_node
{
	struct MISS_ES_0423_node *prev;
	int data;
	int priority;
	int freq;
	struct MISS_ES_0423_node *next;
};
struct MISS_ES_0423_node *head=NULL;
void insert_operation(int num,int prior);
void display();
void delete_priority_list(int var);
void delete_first_priority(int var);
void delete_priority_data(int var,int num);
void delete_overall_list();
void create_queue(int *iptr,int *pptr,int s);
void selection_sorting();
void selection_sorting_data();
void selection_sorting_overall();
void display_priority(int num);
void frequency();
int main()
{
	char opt;
	int prog,var,num,i,*ptr,*pptr;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>>>Priority queue implementataion<<<<<<<<<<<<<<<<\n");
		printf("\t0.Exit from the program\n\t1.Insert operation\n\t2.Display \n\t3.Delete operations\n\t4.Create the queue\n\t5.Sortings\n\t6.Frequency of the priority\n");
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
				printf("Enter the priority\n");
				__fpurge(stdin);
				scanf("%d",&var);
				insert_operation(num,var);
				break;

			case 2:
				while(1)
				{
					printf("..................Display..........................\n");
					printf("q.quit from display case\na.Overall display\nb.Dsiplay based on priority\n");
					__fpurge(stdin);
					scanf("%c",&opt);
					if(opt=='q')
					break;
					switch(opt)
					{
						case 'a':
							printf("Display operation\n");
							display();
							break;


						case 'b':
							printf("Display based on priority\n");
							printf("Enter the priority\n");
							scanf("%d",&num);
							display_priority(num);
							break;
					}
				}
				break;
			case 3:
				while(1)
				{
					printf("..................Delete..........................\n");
					printf("q.quit from delete case\na.Overall delete\nb.Delete priority list\nc.Delete the priority and data\nd.Delete the first priority\n");
					__fpurge(stdin);
					scanf("%c",&opt);
					if(opt=='q')
					break;
					switch(opt)
					{
						case 'a':
							printf("Delete the overall queue\n");
							delete_overall_list();
							break;
						case 'b':
							printf("Delete the particular priority list\n");
							__fpurge(stdin);
							scanf("%d",&num);
							delete_priority_list(num);
							break;
						case 'c':
							printf("Delete tne particular priority and data\n");
							printf("Enter the data\n");
							scanf("%d",&num);
							printf("Enter the priority\n");
							__fpurge(stdin);
							scanf("%d",&var);
							delete_priority_data(num,var);
							break;
						case 'd':
							printf("Delete the first priority \n");
							__fpurge(stdin);
							scanf("%d",&num);
							delete_first_priority(num);
							break;

					}
				}
				break;

			case 4:
				printf("Create list\n");
				printf("Enter the size of an array\n");
				__fpurge(stdin);
				scanf("%d",&num);
				ptr=(int *)malloc(num*sizeof(int));                         //--------Integer array creating dynamically for Data
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(0);
				}
				pptr=(int *)malloc(num*sizeof(int));                          //-------Integer array creating dynamically for Priority
				if(pptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(0);
				}
				for(i=0;i<num;i++)
				{
					printf("Enter the data\n");
					scanf("%d",&ptr[i]);                   //--------------Reading the data----
					__fpurge(stdin);
					printf("Enter the priority\n");
					scanf("%d",&pptr[i]);                 //----------Reading the prorities-----
				}
				create_queue(ptr,pptr,num);
				free(ptr);                                //Deallocating the dynamically allocated memory for data------
				free(pptr);                               //Deallocating the dynamically allocated memory for Priorities--
				break;

			case 5:
				while(1)
				{
					printf("..................Delete..........................\n");
					printf("q.quit from sorting case\na.Overall sorting\nb.Sorting exchange by link\nc.Sorting exchange by data\n");
					__fpurge(stdin);
					scanf("%c",&opt);
					if(opt=='q')
						break;
					switch(opt)
					{
						case 'a':
							 printf("OVerall sorting\n");
                                                         selection_sorting_overall();
							 break;



						case 'b':
							printf("Sorting\n");
							selection_sorting();
							break;

						case 'c':
							printf("Sorting by data\n");
							selection_sorting_data();
							break;
					}
				}
				break;

			case 6:
				printf("Frequency\n");
                                frequency();
				break;

		}
	}
}
//---------------------------------------------------------------------Insert operation-------------------------------
void insert_operation(int num,int prior)
{
	int flag1=0,flag2=0,flag3=0;	
	struct MISS_ES_0423_node *temp,*ptr;
	ptr=(struct MISS_ES_0423_node *)malloc(1*sizeof(struct MISS_ES_0423_node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->priority=prior;
	if(head==NULL)                    //If the queue is empty condition
	{
		ptr->next=NULL;
		ptr->prev=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==prior)         //---------------------Checking the equality condition of present pointed node---------
		{
			if(temp->next!=NULL)      //---------------------If the queue contains only single node (or) not ------------
			{
				if(temp->next->priority!=prior)       //--------------If the same priority is present in next node or not you have to check it------------
				{
					flag1=1;
					break;
				}
			}
		}
		if(temp->priority > prior)       //-------------------If the existing priority is greater than the given prority or not you have to check it-----------
			break;
		if(temp->next==NULL)             //--------------------------If it is single greater than or equal to existing priority----------
		{
			flag2=1;
			break;
		}
		temp=temp->next;
	}
	if(flag1==1 || flag2==1)                        //Add after the node implementation
	{
		ptr->prev=temp;
		ptr->next=temp->next;
		if(temp->next!=NULL)                 //----If the priority in the queue are same only then you have to check the this condition also------
			temp->next->prev=ptr;
		temp->next=ptr;
		return;
	}
	if(temp->priority > prior)                    //Add before node implementation
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
//-----------------------------------------------------Display overall------------------------------------------------
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
		if(temp->freq > 0)
		printf("The data:%d-----------The priority:%d--------The frequency:%d\n",temp->data,temp->priority,temp->freq);
		else
		printf("The data:%d-----------The priority:%d\n",temp->data,temp->priority);
		temp=temp->next;
	}
}
//---------------------------------------------------Display priority----------------------------------------
void display_priority(int num)
{
	int count=0;
	struct MISS_ES_0423_node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==num)                                   //--------------------If given priority is existing or not checking the condition and printing the values-----------
		{
			count++;
			printf("The data:%d-----------The priority:%d\n",temp->data,temp->priority);
		}
		temp=temp->next;
	}
	if(count==0)
	printf("The given priority is not found in this nodes\n");
}
//-----------------------------------------------Delete priority---------------------------------------
void delete_priority_list(int var)
{
	int count=0;
	struct MISS_ES_0423_node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==var)
		{
			count++;
			if(temp->prev!=NULL)                                     //----------if deleting element is first element or not-------
				temp->prev->next=temp->next;
			if(temp->next!=NULL)                                     //-----------if deleteing element is last element or not ----
				temp->next->prev=temp->prev;
			p=temp->next;
			if(temp==head)
				head=p;                                        //---if the deleting element is first elment you have to update in head-----
			free(temp);
			temp=p;
		}
		else
			temp=temp->next;
	}
	if(count==0)
	{
		printf("This priority is not found in this priority queue\n");
	}
}
//------------------------------------------------------------------Delete first priority---------------------------------
void delete_first_priority(int var)
{
	int count=0;
	struct MISS_ES_0423_node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==var)
		{
			count++;
			if(temp->prev!=NULL)                               //----------if deleting element is first element or not-------
				temp->prev->next=temp->next;
			if(temp->next!=NULL)                            //-----------if deleteing element is last element or not ----
				temp->next->prev=temp->prev;
			p=temp->next;
			if(temp==head)                                  //---if the deleting element is first elment you have to update in head-----
				head=p;
			free(temp);
			temp=p;
			return;
		}
		else
			temp=temp->next;
	}
	if(count==0)
	{
		printf("This priority is not found in this priority queue\n");
	}
}
//-----------------------------------------Delete the priority and data-----------------------------------------------
void delete_priority_data(int num,int var)
{
	int count=0;
	struct MISS_ES_0423_node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==var && temp->data==num)
		{
			count++;
			if(temp->prev!=NULL)                            //----------if deleting element is first element or not-------
				temp->prev->next=temp->next;
			if(temp->next!=NULL)                             //-----------if deleteing element is last element or not ----
				temp->next->prev=temp->prev;
			p=temp->next;
			if(temp==head)                                  //---if the deleting element is first elment you have to update in head-----
				head=p;
			free(temp);
			temp=p;

		}
		else
			temp=temp->next;
	}
	if(count==0)
	{
		printf("This priority is not found in this priority queue\n");
	}
}
//-------------------------------------------------------------------Delete overall-----------------------------------
void delete_overall_list()
{
	struct MISS_ES_0423_node *temp;
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
//----------------------------------------------------------------------Create the queue-------------------------------
void create_queue(int *iptr,int *pptr,int s)
{
	int i;
	struct MISS_ES_0423_node *temp,*ptr;
	for(i=0;i<s;i++)
	{

		ptr=(struct MISS_ES_0423_node *)malloc(1*sizeof(struct MISS_ES_0423_node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		ptr->priority=pptr[i];
		if(head==NULL)
		{
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;

		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->priority==pptr[i])
				{
					if(temp->next!=NULL)
					{
						if(temp->next->priority!=pptr[i])
						{

							break;
						}
					}
				}
				if(temp->priority > pptr[i])
					break;
				if(temp->next==NULL)
				{
					break;
				}
				temp=temp->next;
			}
			if(temp->priority < pptr[i] || temp->priority==pptr[i])                        //Add after the node implementation
			{
				ptr->prev=temp;
				ptr->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=ptr;
				temp->next=ptr;


			}
			else if(temp->priority > pptr[i])                    //Add before node implementation
			{
				ptr->prev=temp->prev;
				ptr->next=temp;
				if(temp->prev!=NULL)
					temp->prev->next=ptr;
				temp->prev=ptr;
				if(temp==head)
					head=ptr;
			}
		}
	}
}
//------------------------------------------------------------------------------Selection sorting exchange by link------------------------------------------------------
void selection_sorting()
{
	struct MISS_ES_0423_node *temp,*p,*q;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->priority==q->priority)
			{
				if(p->data > q->data)
				{
					if(p->next!=q)            //-------Condition for Non adjacent nodes----
					{
						temp=p->prev;                        //-----------Swapping the node previous address------
						p->prev=q->prev;
						q->prev=temp;

						temp=p->next;                       //--------------Swapping the node next address-------
						p->next=q->next;
						q->next=temp;

						if(p!=head)                     //-------------Checking the head condition----------
							q->prev->next=q;
						else
							head=q;
						if(p->next!=NULL)
							p->next->prev=p;
						p->prev->next=p;
						q->next->prev=q;             //---------In Non adjacent we have to update 8 address in the queue ------------
					}
					else                           //-------Condition for adjacent nodes----
					{
						q->prev=p->prev;          //-------Updating previous addresses-------
						p->prev=q;

						p->next=q->next;          //-----------Updating the next addresses-----
						q->next=p;


						if(p!=head)               //-------------Checking the head condition----------
							q->prev->next=q;
						else
							head=q;
						if(p->next!=NULL)
							p->next->prev=p;            //---------In adjacent we have to update 6 address in the queue -----------
					}
					temp=p;
					p=q;
					q=temp; //----After the swapping the links you have recheck that particular element with other nodes data which are presented in that queue-----

				}
			}
			else
				break;
		}
	}
}
//-------------------------------------------------------------Selection sorting exchange by data-------------------------------------------------------
void selection_sorting_data()
{
	int var;
	struct MISS_ES_0423_node *temp,*p,*q;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->priority==q->priority)
			{
				if(p->data > q->data) //-------------Here we are checking the condition just swapping the data not links----------
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
//----------------------------------------------------------------Overall sorting---------------------------------------------------------------------------
void selection_sorting_overall()
{
	struct MISS_ES_0423_node *temp,*p,*q;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
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
					if(p->next!=NULL)
						p->next->prev=p;
					p->prev->next=p;
					q->next->prev=q;
				}
				else
				{
					q->prev=p->prev;
					p->prev=q;

					p->next=q->next;
					q->next=p;


					if(p!=head)
						q->prev->next=q;
					else
						head=q;
					if(p->next!=NULL)
						p->next->prev=p;
				}
				temp=p;
				p=q;
				q=temp;

			}


		}
	}
}
//----------------------------------------------------------------------------------Find its frequency -------------------------------------------------
void frequency()
{
	int count=1;
	struct MISS_ES_0423_node *temp=NULL,*p,*q,*var;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->priority==q->priority)
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

