#include<stdio.h>
int main()
{
	int x[5]={1,2,3,4,5};
	int y[5]={10,20,30,40,50};
        int *ptr[2]={x,y};
	int i,j;
	for(i=0;i<2;i++)
	{
		printf("The values are----------------~~~~~~~~~~~~~~~~------------------\n");
		for(j=0;j<5;j++)
		{
			printf("The data present at the array:%d\n\n",ptr[i][j]);
			printf("The adress present at the array:%p\n\n",&ptr[i][j]);
			printf("The data present at the same array:%d\n\n",ptr[i][j]);
		}
	}
}

             
