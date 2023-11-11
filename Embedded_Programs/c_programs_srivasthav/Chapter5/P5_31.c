/*P5.31 Program to find whether a number is even or odd*/
#include<stdio.h>
int main(void)
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	even:
		printf("Number is even\n"); 
		goto end;
	if(n%2==0)			
		goto even;
	else
		goto odd;
	odd:
		printf("Number is odd\n");
		goto end;
	end:
	printf("\n");
	return 0;
}
