/*P4.9 Program to understand the sizeof operator*/
#include<stdio.h>
int main(void)
{
	int var;
	printf("Size of int=%ld\n",sizeof(int));
	printf("Size of float=%ld\n",sizeof(float));
	printf("Size of var=%ld\n",sizeof(var));
	printf("Size of an integer constant=%ld\n",sizeof(45));  
	printf("Size of a=%ld\n",sizeof(int (*)[]));
	return 0;
}
