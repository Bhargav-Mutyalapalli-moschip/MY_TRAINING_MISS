#include<stdio.h>
int main()
{
	int cnt,i,j,no=4;
	srand(time(NULL));
	for(i=0;i<no;i++)
	{
		for(j=0;j<4;j++)
		{
			cnt=rand()%255;
			printf("%d",cnt);
			if(j<3)
				printf(".");
		}
		printf("\n");
	}
}

