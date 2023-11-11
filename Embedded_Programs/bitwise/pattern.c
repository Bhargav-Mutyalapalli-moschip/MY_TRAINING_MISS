#include<stdio.h>
int main()
{
	int i,j,x,k=0;
	for(i=0;i<8;i++)
	{
		k=1;
		for(j=0;j<8;j++)
		{
			if(k>1)
			k=0;
			if(i>=j)
			printf("%d ",k++);
			else
				printf(" ");
		}
		printf("\n");
	}
}

