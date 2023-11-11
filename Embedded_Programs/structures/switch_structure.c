#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#define NUM 3
int count=0;
struct books *memory_allocate();
void read_input(struct books *ptr);
void display(struct books *ptr);
void swap(struct books *ptr);
void deallocate(struct books *ptr);
struct books
{
	char name[40];
	int nop;
	float price;
};
int main()
{
	int prog;
	struct books *book;
	while(1)
        {
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Select the inputs<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Memory Allocation\n2.Read the inputs\n3.Display the output\n4.Swap operation\n5.Memory Deallocation\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Successfully executed by user\n");
				exit(-1);
			case 1:
				printf("Memory is allocating\n");
	                        book=memory_allocate();
				count++;
				break;

			case 2:
				if(count>=1)
				{
					printf("Read operation\n");
					count=0;
	                                read_input(book);
				}
				else
					printf("Memory is not allocated please allocate the memory\n");
				break;

			case 3:
				printf("Count:%d\n",count);
				if(count>0 && count<=NUM)
				{
					printf("Displaying the outputs\n");
	                                display(book);
				}
				else
					printf("Give the inputs to display\n");
				break;

			case 4:
				if(count>0 && count<=NUM)
				{
					printf("Swap opeartion\n");
					swap(book);
	                                display(book);
				}
				else
					printf("there is inputs to perform the swap operation\n");
				break;

			case 5:
				if(count>0 && count<=NUM)
				{
					printf("Deallocating the memory\n");
					deallocate(book);
				}
				else
					printf("There is no memory on live to deallocate\n");
				break;
			}
	}
}
struct books *memory_allocate()
{
	struct books *ptr;
	ptr=(struct books *)malloc(NUM*sizeof(struct books));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	return ptr;
}
void read_input(struct books *ptr)
{
	int i;
	for(i=0;i<NUM;i++)
	{
		count++;
		__fpurge(stdin);
		printf("Enter the book name\n");
		scanf("%[^\n]",ptr[i].name);
		__fpurge(stdin);
		printf("Enter the book number of pages\n");
		scanf("%d",&ptr[i].nop);
		__fpurge(stdin);
		printf("Enter the book price\n");
		scanf("%f",&ptr[i].price);
		__fpurge(stdin);
	}
}
void display(struct books *ptr)
{
	int i;
	for(i=0;i<NUM;i++)
	{
		printf("The book name address:%p\t\tThe book name:%s\t\tThe book name total size:%ld\n",ptr[i].name,ptr[i].name,sizeof(ptr[i].name));
		printf("The book nop address:%p\t\tThe book number of pages:%d\t\tThe book nop total size:%ld\n",&ptr[i].nop,ptr[i].nop,sizeof(ptr[i].nop));
		printf("The book price address:%p\t\tThe book price:%f\t\tThe book price total size:%ld\n",&ptr[i].price,ptr[i].price,sizeof(ptr[i].price));
	}
}
void swap(struct books *ptr)
{

	int i,n;
	n=NUM-1;
	struct books temp;;
        for(i=0;i<n;i++,n--)
	{	
		strcpy(temp.name,ptr[i].name);
		strcpy(ptr[i].name,ptr[n].name);
		strcpy(ptr[n].name,temp.name);
		temp.nop=ptr[i].nop;
		ptr[i].nop=ptr[n].nop;
		ptr[n].nop=temp.nop;
		temp.price=ptr[i].price;
		ptr[i].price=ptr[n].price;
		ptr[n].price=temp.price;
	}
}
void deallocate(struct books *ptr)
{
	count=0;
	free(ptr);
}

