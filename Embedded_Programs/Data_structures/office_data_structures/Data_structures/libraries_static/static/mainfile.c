#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include "header.h"
struct node *head=NULL;
int main()
{
	int prog,num,res=0,*ptr,i,var;
	while(1)
	{
		printf(">>>>>>>>>>>Stack implementation<<<<<<<<<<<<\n");
		printf("0.Exit the program\n\n1.Push operation\n\n2.Pop operation\n\n3.Display stack\n\n4.Count the stack data\n\n5.Search the element in stack\n\n6.Reverse the sstack\n\n7.Create a stack\n\n8.Delete a particular data\n\n9.Add after data\n\n10.add before data\n\n11.Swap the data\n\n12.Swap the data by links\n\n13.Delete duplicates\n\n14.Delete stack\n\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:
				printf("Exit the program\n");
				exit(1);


			case 1:
				printf("The push operation\n");
				printf("Enter the data\n");
				scanf("%d",&num);
				push_operation(num);
				break;

			case 2:
				printf("The pop operation\n");
				pop_operation();
				break;

			case 3:
				printf("Display operation\n");
				display_stack();
				break;

			case 4:
				printf("Count the stack data\n");
				count_stack();
				break;

			case 5:
				printf("Search for particular data\n");
				scanf("%d",&num);
				res=search_stack(num);
				if(res>0)
					printf("Element is found at %d position\n",res);
				else
					printf("ELement is not found\n");
				break;

			case 6:
				printf("Reverse the list\n");
				reverse_stack();
				break;

			case 7:

				printf("Create a stack\n");
				printf("Enter the no of elements count\n");
				scanf("%d",&num);
				ptr=(int *)malloc(num*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(1);
				}
				for(i=0;i<num;i++)
				{
					__fpurge(stdin);
					printf("Enter the %d index element\n",i);
					scanf("%d",&ptr[i]);
				}
				create_stack(ptr,num);
				free(ptr);
				break;

			case 8:
				printf("Delete the particular data\n");
				scanf("%d",&num);
				delete_particular_stack(num);
				break;

			case 9:
				printf("Add after the data\n");
				printf("Enter the search element and add element\n");
				scanf("%d%d",&num,&var);
				add_after_data(num,var);
				break;

			case 10:

				printf("Add before the data\n");
				printf("Enter the search element and add element\n");
				scanf("%d%d",&num,&var);
				add_before_data(num,var);
				break;

			case 11:

				printf("swap the data\n");
				printf("Enter the first element and next element\n");
				scanf("%d%d",&num,&var);
				swap_data(num,var);
				break;

			case 12:

				printf("swap the links\n");
				printf("Enter the first element and next element\n");
				scanf("%d%d",&num,&var);
				swap_link(num,var);
				break;

			case 13:
				printf("Delete duplcates\n");
				delete_duplicates();
				break;

			case 14:
				printf("Delete stack\n");
				delete_stack();
				break;


		}
	}
}


