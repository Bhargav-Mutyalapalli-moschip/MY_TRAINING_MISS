#include<stdio.h>
#define ROW 5
#define COL 5
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
	int i=-1,j=0,k,temp;
	int elements=ROW*COL;
	temp=COL-1;
	int n=0;
	//printf("TEMp value%d\n",temp);
	while(elements>0)
	{
		i++;
		for(j=i;j<=temp;j++)
		{
			if(elements==0)
				break;
			printf("%d       ",ptr[i][j]);
			elements--;
			
		}
		j--;



		k=i+1;
		for(k;k<=temp;k++)
		{
			if(elements==0)
				break;
			printf("%d        ",ptr[k][j]);
			elements--;
		}
		j--;
		k--;
		for(j;j>=n;j--)
		{
			if(elements==0)
				break;
			printf("%d        ",ptr[k][j]);
			elements--;
		}
		j++;
		k--;
		for(k;k>n;k--)
		{
			if(elements==0)
				break;
			printf("%d        ",ptr[k][j]);
			elements--;
		}
		temp--;
		n++;
	//	printf("elements%d\n",elements);

	//	printf("i:%d\n j:%d\n",i,j);
		
	}
}
