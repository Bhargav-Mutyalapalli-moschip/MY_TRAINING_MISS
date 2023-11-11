#include<stdio.h>
void display(int,int,void *ptr);
int main()
{

	str=malloc(2*3*sizeof(int));
	display(0,1,str);
}
void display(int r,int c,void *ptr)
{
	printf("Hello\n");
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&((int(*)[3])ptr)[i][j]);
			printf("The out:%d",((int(*)[3])ptr)[i][j]);
		}
	}


}

