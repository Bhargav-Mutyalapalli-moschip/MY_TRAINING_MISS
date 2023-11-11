#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k=0;
	for(i=0;i<5;i++)
	{
		k=1;
		for(j=0;j<5;j++)
		{
			if(i>=j)
			{
				printf("%d",k);
				k++;
			}
		}
		printf("\n");
	}
}


