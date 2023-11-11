#include<stdio.h>
#define ROW 4
#define COL 4
void read_input(int(*ptr)[COL]);
void display_output(int(*ptr)[COL]);
int arr[ROW][3];
int main()
{
	int ptr[ROW][COL];
	printf("Spiral matrix\n");
	read_input(ptr);
	display_output(ptr);
}
void read_input(int(*ptr)[COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		
		for(j=0;j<COL;j++)
		{
			scanf("%d",&ptr[i][j]);
		}
	}
}
void display_output(int(*ptr)[COL])
{
	printf("Row     Col      Data\n");
	int i=0,j=0,k,temp,big=0,new=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			for(k=j+1;k<COL;k++)
			{
				if(ptr[i][j]>ptr[i][k])
				{
					temp=ptr[i][j];
					ptr[i][j]=ptr[i][k];
					ptr[i][k]=temp;
				}
				

			}

		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
				new=big;
				big=ptr[i][COL-1];
				if(new>big)
					big=new;
				else
					big=big;


			}
			printf("\n");
	}
	printf("The biggest number in matrix\n");
	printf("-----------(%d)\n",big);
}

