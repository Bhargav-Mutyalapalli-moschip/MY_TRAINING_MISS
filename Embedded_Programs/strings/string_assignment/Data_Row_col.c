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
	int i=0,j=0,k,temp;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(ptr[i][j]!=0)
			{
				arr[i][0]=i;
				arr[i][1]=j;
				arr[i][2]=ptr[i][j];
			}
		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d         ",arr[i][j]);
		}
		printf("\n");
	}

}

	
