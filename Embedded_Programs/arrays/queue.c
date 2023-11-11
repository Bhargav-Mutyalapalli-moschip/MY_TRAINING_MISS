#include<stdio.h>
void push(int *ptr,int num);
void display(int *ptr);
void pop();
int rindex=-1;
int findex=-1;
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
	if(rindex==-1 && findex==-1)
	{
		findex++;
		rindex++;
		ptr[rindex]=var;

	}
	else{
		rindex++;
	        ptr[rindex]=var;
	}
	if(rindex>5)
		printf("queue-------------is--------full\n");
}
void pop()
{
        if(rindex==-1 && findex==-1)
        {
                printf("queue----------is-----------empty\n");
        }
        findex++;
	//rindex--;
	if(rindex==findex)
		rindex=findex=-1;
}


void display(int *ptr)
{
        int i;
        for(i=findex;i<5;i++)
        {
                printf("%d \n",*(ptr+i));
        }
}

