/* program to demonstrate how negative numbers are stored in memory */
#include<stdio.h>
int main()
{
	int x = -5;

	int i;
	for(i = 31; i >= 0; i--)
	{
		if(x & (0x1 << i))
			printf("1");
		else
			printf("0");


	}

}
