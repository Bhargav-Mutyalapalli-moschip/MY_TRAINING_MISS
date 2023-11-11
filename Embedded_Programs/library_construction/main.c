#include<stdio.h>
#include<stdlib.h>
#include "pranav.h"
int main()
{
	int prog,num;
	printf("\n");
	printf("----------------------------------Select the below option--------------------\n");
	printf("\n");
	printf("1.Reverse number\n2.Count of digits\n");
	scanf("%d",&prog);
	switch(prog)
	{
		case 0:
			exit(0);
		case 1:
			printf("enter the value to reverse\n");
			scanf("%d",&num);
			reverse_number(num);
			break;
		case 2:
			printf("enter the value to count\n");
			scanf("%d",&num);
			count_digits(num);
			break;
	}
			
}
