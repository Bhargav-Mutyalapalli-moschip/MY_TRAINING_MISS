#include<stdio.h>
#define ROW 4
#define COL 4
int read_input(int(*ptr)[COL]);
//void display_output(int(*ptr)[COL]);
void display_output(int(*ptr)[COL],int(*ptr1)[3],int count);
int main()
{
	int count=0;
        int ptr[ROW][COL];
	int(*ptr1)[]=(int(*)[])malloc(ROW*3*sizeof(int));
        printf("Spiral matrix\n");
        count=read_input(ptr);
	int(*ptr2)[]=(int(*)[])realloc(ptr1,count*3*sizeof(int));
        display_output(ptr,ptr2,count);
}
int read_input(int(*ptr)[COL])
{
        int i,j,count=0;
        for(i=0;i<ROW;i++)
        {
                for(j=0;j<COL;j++)
                {
                        scanf("%d",&ptr[i][j]);
			if(ptr[i][j]!=0)
			count++;
                }
        }
	return count;
}
void display_output(int(*ptr)[COL],int(*ptr1)[3],int count)
{
        int i,j=0,temp,k=0,d=0;
	printf("Row  col  data\n");
        for(i=0;i<ROW;i++)
        {
		for(j=0;j<COL;j++)
		{
			if(ptr[i][j]==0)
			continue;
			else
			{

			
					ptr1[k][0]=i;
					ptr1[k][1]=j;
					ptr1[k][2]=ptr[i][j];
					k++;
			}
		
		}
	}
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d     ",ptr1[i][j]);
		}
		printf("\n");
	}
}
				

				
