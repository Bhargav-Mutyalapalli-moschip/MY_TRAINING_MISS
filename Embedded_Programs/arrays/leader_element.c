#include<stdio.h>
#define NUM 10
int main()
{
	int ptr[NUM];
	int i,j,k=0;

	for(i=0;i<NUM;i++)
	{
		scanf("%d",&ptr[i]);
	}
	for(i=0;i<NUM;i++)
	{
		for(j=i+1;j<NUM;j++)
		{
			if(i==NUM-1)
			break;
			if(ptr[i]>ptr[j])
			{
				k=ptr[i];

			}
			else
			{
				k=0;
				break;
			}
		}
		
		if(i==NUM-1)
		{
			printf("%d   \n",ptr[i]);
			break;
		}
		else
		{
			if(k==0)
				continue;
                        printf("%d    \n",k);
		}

		
	}
}

