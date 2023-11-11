#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5
#define ROW1 3
#define COL1 3
void read_input(void *ptr,int,int);
void lower(void *ptr);
void upper(void *ptr);
void display_output(void *ptr,int,int);
void addition(void *ptr,void *ptr1,void *ptr2);
void mul(void *ptr,void *ptr1,void *ptr2);
void transpose(void *ptr);
int main()
{
	void *ptr;
	void *ptr1;
	void *ptr2;
	ptr=(int(*)[])malloc(ROW*COL*sizeof(int));
	ptr1=(int(*)[])malloc(ROW1*COL1*sizeof(int));
	ptr2=(int(*)[])malloc(ROW*COL1*sizeof(int));
	int prog;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>Select the below optioin<<<<<<<<<\n");
		printf("0.Exit the program\n1.Read the inputs\n2.Display the output\n3.Addition of matrix\n4.Multiplication\n5.Upper\n6.Lower\n7.Transpose the matrix\n8.deallocate\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Successfully executed\n");
				exit(0);


			case 1:
				printf("Read operation\n");
				printf("First matrix\n");
				read_input(ptr,ROW,COL);
				printf("Second matrix\n");
				read_input(ptr1,ROW1,COL1);
				break;


			case 2:
				printf("Display operation\n");
				printf("First matrix\n");
				display_output(ptr,ROW,COL);
				printf("Second matrix\n");
				display_output(ptr1,ROW1,COL1);
				break;
			case 3:
				printf("addition\n");
				addition(ptr,ptr1,ptr2);
				display_output(ptr2,ROW,COL);
				break;

			case 4:
				printf("multiplication\n");
				mul(ptr,ptr1,ptr2);
				display_output(ptr2,ROW,COL1);
				break;

			case 5:
				printf("Upper triangle\n");
				upper(ptr);
				break;

			case 6:
				printf("Lower triangle\n");
				lower(ptr);
				break;

			case 7:
				printf("transpose\n");
				transpose(ptr);
				break;

			case 8:
				printf("deallocate the memory\n");
				free(ptr);
				free(ptr1);
				free(ptr2);
				break;

		}
		//free(ptr);
		//free(ptr1);
		//free(ptr2);
	}
}
void read_input(void *ptr,int row,int col)
{
	int i,j,k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		//	scanf("%d",&((int(*)[COL])ptr)[i][j]);
		//	scanf("%d",&ptr[i][j]);
			((int(*)[col])ptr)[i][j]=++k;
		}
	}
}
void display_output(void *ptr,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%-5d",((int(*)[col])ptr)[i][j]);
		}
		printf("\n\n");
	}
}
void addition(void *ptr,void *ptr1,void *ptr2)
{
	int i,j;
	if(ROW==ROW1 && COL==COL1)
	{

		for(i=0;i<ROW;i++)
		{
			for(j=0;j<COL;j++)
			{
				((int(*)[COL])ptr2)[i][j]=((int(*)[COL])ptr)[i][j]+((int(*)[COL])ptr1)[i][j];
			}
		}
	}
	else
	{
		printf("Addition can't be done in uneven matrix\n");
		exit(-1);
	}
}
void mul(void *ptr,void *ptr1,void *ptr2)
{
	int i,j,k;
	if(COL==ROW1)
	{
		for(i=0;i<ROW;i++)
		{
			for(j=0;j<COL1;j++)
			{
				((int(*)[COL])ptr2)[i][j]=0;
				for(k=0;k<COL;k++)
					((int(*)[COL1])ptr2)[i][j]+=((int(*)[COL])ptr)[i][k]*((int(*)[COL1])ptr1)[k][j];
			}
		}
	}
	else
	{
		printf("Multiplication can't be done in uneven matrix\n");
		exit(-1);
	}
}
void upper(void *ptr)
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(i<=j)
				printf("%d  ",((int(*)[COL])ptr)[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
}
void lower(void *ptr)
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(i>=j)
				printf("%d  ",((int(*)[COL])ptr)[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
}
void transpose(void *ptr)
{
	void *ptr4;
	ptr4=(int(*)[])malloc(ROW*COL*sizeof(int));
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			((int(*)[COL])ptr4)[j][i]=((int(*)[COL])ptr)[i][j];
		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		printf("%-2d  ",((int(*)[COL])ptr4)[i][j]);
		printf("\n");
	}
	free(ptr4);
}




































































































