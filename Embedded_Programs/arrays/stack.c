#include<stdio.h>
void push(int *ptr,int num);
void display(int *ptr);
void pop();
int index=-1;
int main()
{
	int prog,var;
	int arr[5];
	while(1)
	{
		printf("Menu\n");
		printf("0.exit\n 1.Push operation\n 2.Pop operation\n 3.Display the values\n 4.Search the operation\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);

			case 1:
				printf("Performing the push operation\n");
				scanf("%d",&var);
				push_oper(arr,var);
				break;

			case 2:
				printf("Performing the pop operation\n");
				pop();
				break;

			case 3:
				printf("Displaying the values\n");
				display(arr);
				break;

		}
	}
}
void push_oper(int *ptr,int var)
{
	if(index<4)
	{
		index++;
		ptr[index]=var;
	}
	else
		printf("Stack-------------- is--------------------- full\n");
}
void pop()
{
	if(index==-1)
	{
		printf("Stack----------is-----------empty\n");
	}
        index--;
}


void display(int *ptr)
{
	int i;
	for(i=0;i<=index;i++)
	{
		printf("%d \n",*(ptr+i));
	}
}




