#include<stdio.h>
#define N 5
int i=-1;
void push_oper(int *ptr,int send);
void pop_oper(int *ptr);
void search(int *ptr,int sea);
int main()
{
	int prog,arr[N],send,sea;
	while(1)
	{
		printf("Select the option\n");
		printf("1.Push operation\n 2.Pop operation\n 3.Display\n ");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);
			case 1:
				printf("performed the push operation\n");
				scanf("%d",&send);
				push_oper(arr,send);
				break;
			case 2:
				printf("Performing the pop operation\n");
				pop_oper(arr);
				break;
			case 3:
				printf("Display the values:\n");
				int j;
				for(j=0;j<5;j++)
				{
					if(arr[j]!=0)
					printf("%d \n",arr[j]);
				}
				break;
			case 4:
				printf("Searching for the vlaue\n");
				scanf("%d",&sea);
				search(arr,sea);
				break;


		}
	}
}
void push_oper(int *ptr,int send)
{
        //int i;
        if(i<4)
        {
                i++;
                ptr[i]=send;
        }
	else
		printf("stackis full\n");
}
void pop_oper(int *ptr)
{
	if(i<=4 && i>=0){
	        ptr[i]=0;
		i--;
	}
	else if(i==-1)
		printf("stack is empty\n");
}
void search(int *ptr,int sea)
{
	int s;
	for(s=0;s<5;s++)
	{
		if(ptr[s]==sea)
			printf("element found %d\n",s);
		else
			printf("Not found\n");
	}
}









