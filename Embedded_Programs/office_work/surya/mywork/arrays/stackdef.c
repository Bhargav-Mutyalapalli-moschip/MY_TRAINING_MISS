#include<stdio.h>
void push_oper(int *ptr,int n)
{
	int i;
	for(i=4;i<=0;i--)
	{
		if(ptr+i==NULL)
		{
			printf("Stack is empty \n");
			scanf("%d",ptr+i);
			push_oper((ptr+i),*(ptr+i));
			
		}
		else
		{
			printf("Stack is full at that positon");
			for(i=0;i<n;i++)
			{
				if(ptr+i==NULL)
				{
					scanf("%d",ptr+i);
                                        push_oper((ptr+i),*(ptr+i));
					if(i==4)
					{
						printf("Stack is full\n");
					}


				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("The value at that index%d : ",i);
			printf("%d\n",*(ptr+i));
		}


		
	}


			
		}

			


