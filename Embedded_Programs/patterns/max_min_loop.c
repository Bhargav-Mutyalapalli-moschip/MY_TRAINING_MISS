#include<stdio.h>
int main()
{
	int i,j,n=2,k=1,d=n;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(j==1 && i==1)
			{
				d--;
				printf("%3d",d);
				k++;
			}
			else
				printf("%3d",d);
		}
		printf("\n");
	}
}

