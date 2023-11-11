
#include<stdio.h>
#include<stdlib.h>
#define VOL 5
int front=-1;
int rear=-1;
void insert(int *ptr,int var);
void remove1();
void display(int *ptr);
void ascend(int *ptr);
int main()
{
	int i,prog,var;
	int arr[VOL];
	while(1)
	{
		printf("Menu-----------select the below option--------\n");
		printf("1.Insert mode\n2.Delete mode\n3.Display the values\n4.Search for number\n5.Ascending order\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);
			case 1:
				printf("Enter the value to insert the value in queue\n");
				scanf("%d",&var);
				insert(arr,var);
				break;
			case 2:
				printf("enter the value to remove the value in queue\n");
				remove1();
				break;

			case 3:
				printf("Displaying the values\n");
				display(arr);
				break;
			case 5:
				printf("Arrange in a order\n");
				ascend(arr);
				break;
		}
	}
}
void insert(int *ptr,int var)
{
	int i;
	if(rear==-1 && front==-1)
	{
		rear++;
		ptr[rear]=var;
		front++;
	}
	else if(((rear==VOL-1)&&(front==0))||(rear==front-1))
	{
		printf("Queue is full\n");
		return;
	}
        else if((rear==VOL-1)&&(front>0))
        {
                rear=0;
                ptr[rear]=var;
                return;
        }
        else{
                rear++;
                ptr[rear]=var;
        }


}
void remove1()
{
        if(front==-1)
        {
                printf("QUeue is empty\n");
                return;
        }
        /*else if((rear>0)&&(front<=rear))
        {
                printf("Queue containing some values\n");
		return;

        }*/
	else if(rear==front){
                rear=front=-1;
		return;
		}

        else if(front == VOL-1)
        {
                front=0;
		return;
        }
        front++;
}
void display(int *ptr)
{
        int i,j;
        if(front==-1 && rear==-1)
        {
                printf("Queue is empty\n");
                return;
        }
        else if(front<rear)
        {
                for(i=front;i<=rear;i++)
			printf("%d\n",ptr[i]);
	

                        
        }
        else if(rear<=front)
        {
                for(i=front;i<=VOL-1;i++)
                        printf("%d\n",ptr[i]);
                for(i=0;i<=rear;i++)
                        printf("%d\n",ptr[i]);
		
        }
}
void ascend(int *ptr)
{
	int i,j;
	if((front==-1) && (rear==-1))
	{
		printf("Queue is empty\n");
		return;
	}
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			for(j=i+1;j<=rear;j++)
			{
				if(ptr[i]>ptr[j]){
					ptr[i]=ptr[j]+ptr[i];
					ptr[j]=ptr[i]-ptr[j];
					ptr[i]=ptr[i]-ptr[j];
				}

			}
			printf("%d\n",ptr[i]);
		}
	}
	if(rear<front)
	{
		for(i=front;i<=VOL+rear;i++)
		{
			for(j=i+1;j<=VOL+rear;j++)
			{
				if(ptr[i%VOL]>ptr[j%VOL]){
                                        ptr[i%VOL]=ptr[j%VOL]+ptr[i%VOL];
                                        ptr[j%VOL]=ptr[i%VOL]-ptr[j%VOL];
                                        ptr[i%VOL]=ptr[i%VOL]-ptr[j%VOL];
                                }
			}
			printf("%d\n",ptr[i%VOL]);
		}
	}
}

























