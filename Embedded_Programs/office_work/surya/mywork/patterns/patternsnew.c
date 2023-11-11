#include<stdio.h>
int main()
{
	int i,j,k=5,f=1;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if((i==6/2)&&(i==j))
			printf("%d ",f);
			else if((i>=j)||(j>=i))
				printf("%d ",k);
			else
				printf(" ");
		}
		printf("\n");
	}
}
