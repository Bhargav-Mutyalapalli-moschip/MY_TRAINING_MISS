#include<stdio.h>
#define ROW 3
#define COL 3
void read_input(int(*ptr)[COL]);
void display_output(int(*ptr)[COL]);
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
	int i=0,j=0,temp;
	int elements=ROW*COL;
	for(i=0;i<elements;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d   ",ptr[i][j]);
		}
	}
}

