#include<stdio.h>
#define ROW 4
#define COL 4
void display_output(int ptr);
void read_input(int(*arr)[COL]);
int main()
{
	int i,j;
	int arr[ROW][COL];
	printf("Matrix perfect\n");
	read_input(arr);
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			display_output(arr[i][j]);
		}
	}
}
void read_input(int(*arr)[COL])
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
void display_output(int ptr)
{
	  int j,k=1,f=0,sum=0;
          while(k<ptr)
	  {
		  if(ptr%k==0)
		  {
			  sum=sum+k;
		  }
		  k++;
	  }
	  if(sum==ptr)
		  printf("The (%d) is Prefect number\n",sum);
}








