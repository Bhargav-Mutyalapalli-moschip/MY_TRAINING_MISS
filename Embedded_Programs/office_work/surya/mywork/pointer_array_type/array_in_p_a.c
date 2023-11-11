#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
#define ROW1 3
#define COL1 4
//void read_input(int(*ptr1)[],int row,int col);
//void read_input(int**tptr,int row,int col);
void read_input(int tptr[ROW][COL],int row,int col);
void matrix_lower(int(*ptr1)[COL],int row,int col);
void matrix_upper(int(*ptr1)[COL],int row,int col);
//void matrix_trans(int(*ptr1)[COL],int row,int col);
void matrix_trans(int(*ptr1)[COL],int(*ptr2)[ROW],int row,int col);
//void read_input(int ptr[][],int row,int col)
void matrix_add(int(*ptr1)[],int(*ptr2)[],int(*ptr3)[],int row,int col);
void matrix_mul(int(*ptr1)[COL],int(*ptr2)[COL],int(*ptr3)[COL],int row,int col);
void display_output(int(*ptr1)[],int row,int col);
int main()
{
	//int arr1[ROW*COL];
	void*ptr=(int(*)[])malloc(ROW*COL*sizeof(int));
	//void *arr1=arr;
	int arr2[ROW*COL];
	int add[ROW*COL];
	int trans[ROW*COL];
	int **dptr=(int *)malloc(3*sizeof(int*));
	if(dptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(0);
	}
	dptr[0]=arr;
	//dptr[1]=arr2;
	dptr[2]=add;
	printf("\n");
	printf(">>>>>Menu<<<<<");
	printf("\n");
	printf("------------------------Select the below option---------------\n");
	printf("\n");
	printf("0.Exit the program\n1.Matrix addition\n2.Matrix Multiplication\n3.Transpose matrix\n4.Upper triangle\n5.Lower traingle\n");
	printf("\n");
	int prog;
	scanf("%d",&prog);
	switch(prog)
	{
		case 0:
			printf("Successfully executed\n");
			exit(0);

		case 1:
			printf("Matrix operation\n");
			printf("Read the first matrix elements\n");
			read_input(dptr[0],ROW,COL);
			/*printf("Read the second matrix elements\n");
			read_input(dptr[0],ROW,COL);
			printf("Performing the addition operation\n");
			matrix_add(dptr[0],dptr[1],dptr[2],ROW,COL);
			printf("Displaying output\n");
			display_output(dptr[2],ROW,COL);*/
			break;
		/*case 2:
			printf("Matrix multiply operation\n");
			printf("Read the first matrix elements\n");
			read_input(arr1,ROW,COL);
			printf("Read the second matrix elements\n");
			read_input(arr2,ROW,COL);
			printf("Performing the multiply operation\n");
			matrix_mul(arr1,arr2,add,ROW,COL);
			printf("Displaying output\n");
			display_output(add,ROW,COL);
			break;

		case 3:
			printf("The matrix transpose\n");
			read_input(arr1,ROW,COL);
			matrix_trans(arr1,trans,ROW,COL);
			break;

		case 4:
			printf("The upper triangle\n");
			read_input(arr1,ROW,COL);
			matrix_upper(arr1,ROW,COL);
			break;

		case 5:

			printf("The lower triangle\n");
			read_input(arr1,ROW,COL);
			matrix_lower(arr1,ROW,COL);
			break;*/





	}

}
void read_input(int tptr[ROW][COL],int row,int col)
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<row;j++)
		{
			//for(k=0;k<col;k++)
			scanf("%d",&tptr[i][j]);
	
		}
	}
}
void matrix_add(int(*ptr1)[COL],int(*ptr2)[COL],int(*ptr3)[COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			ptr3[i][j]=ptr1[i][j]+ptr2[i][j];
			
		}
	}
}


void display_output(int(*ptr1)[COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d     ",ptr1[i][j]);
		}
		printf("\n");
	}
}
void matrix_mul(int(*ptr1)[COL],int(*ptr2)[COL],int(*ptr3)[COL],int row,int col)
{
	int i,j,k;
	if(row==col)
	{

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				ptr3[i][j]=0;
				for(k=0;k<col;k++)
			        ptr3[i][j]+=ptr1[i][k]*ptr2[k][j];



			}
		}		
	}
	else 
	{
		printf("Invalid rows and columns\n");
		exit(0);

	}
}
void matrix_trans(int(*ptr1)[COL],int(*ptr2)[ROW],int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			ptr2[i][j]=ptr1[j][i];

			
			
		}
		printf("\n");
		
	}
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d     ",ptr2[i][j]);
		}
		printf("\n");
	}

}
void matrix_upper(int(*ptr1)[COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i<=j)
			printf("%d ",ptr1[i][j]);
			else
				printf(" ");

			
			
		}
		printf("\n");
	}
}

void matrix_lower(int(*ptr1)[COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i>=j)
			printf("%d ",ptr1[i][j]);
			else
				printf(" ");

			
			
		}
		printf("\n");
	}
}







