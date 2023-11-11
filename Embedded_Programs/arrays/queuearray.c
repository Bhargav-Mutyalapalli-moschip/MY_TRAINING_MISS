#include<stdio.h>
void push(int *ptr,int var);
void display(int *ptr,int n);
int rearind=-1;
int frontind=-1;
int main()
{
	int j,prog,var;
	int arr[5];
	while(1)
	{
		printf(" MENU\n 0.exit\n 1.Push operation\n 2.Pop operation\n 3.display values\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);
			case 1:
				printf("perform the push operation\n");
				scanf("%d",&var);
				push(arr,var);
				break;
			case 2:
				printf("perform the pop operation\n");
				pop();
				break;
			case 3:
				printf("Dis[play the outputs\n");
				display(arr,5);
				break;


		}
	}
}

void push(int *ptr,int var)
{
	if(rearind==4)
	{
		printf("queue is full\n");
		return;
	}
	if(rearind==-1 && frontind==-1){
		rearind++;
		ptr[rearind]=var;
		frontind++;
        }
	else
		rearind++;
                ptr[rearind]=var;


}

void display(int *ptr,int n)
{
	int i;
	if(frontind==rearind)
	{
		printf("queue is empty\n");
		return;
	}
	if(frontind==rearind)
		printf("Queue is empty");

	for(i=frontind;i<n;i++)
	{
		printf("%d \n",ptr[i]);
	}
}
void pop()
{
	if(rearind==frontind)
	{
		printf("Queue is empty\n");
		rearind=frontind=-1;
		return;
	}
	if(frontind>=0)
	frontind++;
}

