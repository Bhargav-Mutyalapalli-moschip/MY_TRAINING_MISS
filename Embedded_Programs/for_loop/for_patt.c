#include<stdio.h>
int main()
{
	int i,j;
	for(i=3;i>0;i--)
	{
		for(j=0;j<i;j++){
		if(j<i)
		printf("*");
		else if(i>1)
			printf("*");
		else
			printf(" ");

	        }
		printf("\n");
	}
	
}
