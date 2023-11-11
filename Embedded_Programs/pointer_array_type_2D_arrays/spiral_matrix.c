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
	if(i<=j)
	{

		//printf("The inner j value:%d\n",j);
		for(j;j<COL;j++)
		{
			printf("-----(%d)-----",ptr[i][j]);
		}
		j--;
		if(i==0)
		{
			for(i=1;i<COL;i++)
				printf("------%d-----",ptr[i][j]);
			i--;

		}
		if(j==COL-1)
		{
			j--;
			for(j;j>0;j--)
				printf("-------%d-----",ptr[i][j]);
		}
		//printf("i :%d ,j:%d\n",i,j);
		if(j==0)
		{

			for(i;j<i;i--)
			{
				printf("-----(%d)-----",ptr[i][j]);
			}
			i++;
		}
		//printf("i :%d ,j:%d\n",i,j);
		if(i==1)
		{

			for(j=j+1;j<=COL-3;j++)
			{
				printf("-----(%d)-----",ptr[i][j]);
			}
		}
		printf("i :%d ,j:%d\n",i,j);
		if(j==COL-j)
		{
			i++;
			j--;
			for(i;i<=j;i++)
				printf("--------%d-------",ptr[i][j]);
		}
		//printf("i :%d ,j:%d\n",i,j);
		if(i==COL-j-1 && j==COL-i-1)
		{

			i--;
			j--;
			for(j;j>0;j--){
				printf("-----%d-----",ptr[i][j]);
			printf("LOOP\n");
			}



		}



	}
}

