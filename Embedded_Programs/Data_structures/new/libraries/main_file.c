#include<stdio.h>
#include<stdio_ext.h>
#include "stack.h"
#include<stdlib.h>
struct node *head=NULL;
int main()
{
	int prog,num;
	while(1)
	{
		printf(">>>>>>>>>>Stack Implementation<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Push operation\n2.Pop operation\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:
				printf("Exit the program\n");
				exit(1);
			case 1:
				printf("Push operation\n");
				scanf("%d",&num);
				push_operation(num);
				break;

			case 2:
				printf("Pop operation\n");
				pop_operation();
				break;
		}
	}
}


