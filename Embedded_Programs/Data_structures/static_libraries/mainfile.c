#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include "header.h"
struct node *head=NULL;
int main()
{
	int prog,num,res=0,*ptr,i;
	while(1)
	{
		printf(">>>>>>>>>>>Stack implementation<<<<<<<<<<<<\n");
		printf("0.Exit the program\n\n1.Push operation\n\n2.Pop operation\n\n3.Display stack\n\n4.Count the stack data\n\n5.Search the element in stack\n\n6.Reverse the sstack\n\n7.Create a stack\n\n");
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

		}
	}
}


