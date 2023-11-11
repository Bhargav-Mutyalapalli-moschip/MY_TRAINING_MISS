#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
struct book *memory_allocate();
void read_input(struct book *ptr);
void deallocate(struct book *ptr);
void swap(struct book *ptr1,struct book *ptr2);
void display(struct book *ptr);
void palindrome_string(struct book *ptr);
void reverse_string(struct book *ptr);
void string_length(struct book *ptr);
void string_comparsion(struct book *ptr1,struct book *ptr2);
struct book
{
	char name[32];
	int nop;
	float price ;
};
int main()
{
	struct book *str,*ptr;
	str=memory_allocate();
	ptr=memory_allocate();
	read_input(str);
	read_input(ptr);
	display(str);
	display(ptr);
	swap(str,ptr);
	display(str);
	display(ptr);
	palindrome_string(str);
	palindrome_string(ptr);
	reverse_string(str);
	reverse_string(ptr);
	string_length(ptr);
	string_length(str);
	string_comparsion(str,ptr);
	deallocate(str);
	deallocate(ptr);
	printf("The main file size:%ld\n",sizeof(struct book));




}
struct book *memory_allocate()
{
	struct book *ptr;
	ptr=(struct book *)malloc(1*sizeof(struct book));
	return ptr;
}
void read_input(struct book *ptr)
{
	__fpurge(stdin);
	printf("Enter the book name\n");
	scanf("%[^\n]",ptr->name);
	__fpurge(stdin);
	printf("Enter the number of pages\n");
	scanf("%d",&ptr->nop);
	__fpurge(stdin);
	printf("Enter the price\n");
	scanf("%f",&ptr->price);
}
void display(struct book *ptr)
{
	printf("The book variable address:%-5p---The book name:-%-5s----The book variable size:%-5ld\n",ptr->name,ptr->name,sizeof(ptr->name));
	printf("The number of pages address:%-5p----The count of no of pages:%-5d----The no of pages size:%-5ld\n",&ptr->nop,ptr->nop,sizeof(ptr->nop));
	printf("The book price address:%-5p---The book price:%-5f----The book price size:%-5ld\n",&ptr->price,ptr->price,sizeof(ptr->price));
}
void deallocate(struct book *ptr)
{
	free(ptr);
}
void swap(struct book *ptr1,struct book *ptr2)
{
	struct book temp;
	printf("Swapping of book names\n");
	strcpy(temp.name,ptr1->name);
	strcpy(ptr1->name,ptr2->name);
	strcpy(ptr2->name,temp.name);
	printf("Swapping of number of pages\n");
	temp.nop=ptr1->nop;
	ptr1->nop=ptr2->nop;
	ptr2->nop=temp.nop;
	printf("Swapping of price\n");
	temp.price=ptr1->price;
	ptr1->price=ptr2->price;
	ptr2->price=temp.price;
}
void palindrome_string(struct book *ptr)
{
	int i,len,count=0,var;
	len=strlen(ptr);
	var=len;
	printf("Length:%d\n",len);
	for(i=0,len=len-1;i<len;len--,i++)
	{
		if(ptr->name[i]==ptr->name[len])
		count++;
	}
	printf("Count:%d\n",count);
	if(count==var/2)
	{
		printf("It is palindrome string\n");
	}
	else
		printf("Not a palindrome string\n");
}
void reverse_string(struct book *ptr)
{
	int i,j;
	int len;
	char temp;
	len=strlen(ptr);
	for(i=0,len=len-1;i<len;i++,len--)
	{
		temp=ptr->name[i];
		ptr->name[i]=ptr->name[len];
		ptr->name[len]=temp;
		//printf("%c\n",ptr->name[i]);
	}
	printf("The reversed string%s\n",ptr->name);
}
void string_length(struct book *ptr)
{
	int i,count=0;
	for(i=0;ptr->name[i]!='\0';i++)
	{
		count++;
	}
	printf("The string length:%d\n",count);
}
void string_comparsion(struct book *ptr1,struct book *ptr2)
{
	int i,l,count=0;
	for(i=0;ptr1->name[i]!='\0' || ptr2->name[i]!='\0';i++)
	{
		if(ptr1->name[i]!=ptr2->name[i])
		count=1;
	}
	if(count==0)
	{
		printf("Same string\n");
	}
	else
		printf("not a samestring\n");
}




