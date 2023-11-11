#include<stdio.h>
int main()
{
	int var=34;
	int *sptr=&var;
	int **dptr=&sptr;

        printf("\t-----------------Single Pointer-----------\n");

	printf("%p\n",&var);          //Address of variable
	printf("%p\n",sptr);         //Address stored in sptr pointer variable
	printf("%p\n",*sptr);       //Address stored in derefernced pointer(if it is any type of data it will converts to hexa decimal format)
	printf("%p\n",&sptr);      //Address for single pointer variable

	printf("\t----------------Double pointer------------\n");
	
	printf("%p\n",&var);          //Address of variable
	printf("%p\n",sptr);         //Address stored in sptr pointer variable
	printf("%p\n",*sptr);       //Address stored in derefernced pointer(if it is any type of data it will converts to hexa decimal format)
	printf("%p\n",&sptr);      //Address for single pointer variable





}
