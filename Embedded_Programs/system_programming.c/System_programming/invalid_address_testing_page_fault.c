#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include <fcntl.h>

#define HUGE_NUMBER 258963
int main()
{
	//int i;
	int *ptr,num,i,j=0,k=0;
        scanf("%d",&num);
	ptr=(int *)malloc(num*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	free(ptr);
	num=num+num;
	for(i=0;i<num;i++)
	{
		__fpurge(stdin);
		if(i%2==0)
		{
			k++;
			printf("Enter the data in %d position\n",k);
		}
		else
		{
	userfaultfd();		j++;
			printf("Enter the priority value in %d position\n",j);
		}
		scanf("%d",&ptr[i]);
		}
	//userfaultfd();

	/*while (1) {
		char * data = malloc(HUGE_NUMBER)
			for (size_t i=0 ; i<HUGE_NUMBER ; i+=4096)
				data[i] = (char)rand(); // dirty in 4K intervals
	}*/

}

