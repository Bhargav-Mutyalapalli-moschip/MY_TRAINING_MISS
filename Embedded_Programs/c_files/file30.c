#include<stdio.h>

int main()
{

	
	

	int x=56;
	{
		printf("%d\n",x);
		{
			printf("%d\n",x);
			{
				x=57;
				printf("%d\n",x);
			}
		}
	}
	printf("%d\n",x);
	x=987;
	
	printf("%d\n",x);
}

	
