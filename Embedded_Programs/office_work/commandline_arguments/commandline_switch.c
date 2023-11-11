#include<stdio.h>
int main()
{
	unsigned int num,k;
	int i;
	printf("Enter the value to convert into binary:\n");
	scanf("%d",&num);
	for(i=31;i>=0;i--)
	{
		if(num>=0)
		{
			if((num &(0x1<<i)) == 0)
			{
				printf("0");

			}
			else
				printf("1");
		}
		else{
		/*	k=~(num);
			k++;*/
			

			if((num &(0x1<<i))==0)
			{
			
				
				printf("0");
			}
		        else
				printf("1");
		}




	}
}
