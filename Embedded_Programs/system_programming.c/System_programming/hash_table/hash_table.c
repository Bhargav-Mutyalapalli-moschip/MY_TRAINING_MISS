#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define SIZE 20
struct node
{
	int keys;
	int id_no;
	char gender;
};
struct node *pointr[SIZE];
int key_creation(char *ptr);
void insert_hash(int id,char gend,int k);
void search(struct node **ptr1,int key);
int main()
{
	char str[20];
	int prog,ret,id;
	char gend;
	while(1)
	{
		printf("0.Exit the program\n1.Insert the element\n2.Search for elements\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:
				printf("Successfully excuted by user\n");
				exit(0);

			case 1:
				printf("Insert the elements\n");
				printf("Enter the name to find the details about that person\n");
				scanf("%[^\n]",str);
				__fpurge(stdin);
				ret=key_creation(str);
				printf("The original key:%d\n",ret);
				printf("Enter the id_no\n");
				scanf("%d",&id);
				__fpurge(stdin);
				printf("Enter the gender\n");
				scanf("%c",&gend);
				__fpurge(stdin);
				insert_hash(id,gend,ret);
				break;

			case 2:
				printf("Search \n");
				printf("Enter the name to find the details about that person\n");
				scanf("%[^\n]",str);
				__fpurge(stdin);
				ret=key_creation(str);
				printf("The original key:%d\n",ret);
				search(pointr,ret);
				break;



		}
	}
}
int key_creation(char *ptr)
{
	if(ptr==NULL)
	{
		printf("It is not a valid address\n");
		exit(1);
	}
	int key=0,i,k=1;
	for(i=0;ptr[i]!='\0';i++)
	{
		k++;
	}
	printf("The key is:%d\n",key);
	key=key%SIZE;
	return key;
}
void insert_hash(int id,char gend,int k)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(1);
	}
	ptr->id_no=id;
	ptr->gender=gend;
	ptr->keys=k;
	pointr[k]=ptr;
	free(ptr);
}
void search(struct node **ptr1,int key)
{
	struct node *ptr;
	if(ptr==NULL)
	{
		printf("received invalid\n");
		exit(1);
	}
	ptr=ptr1[key];
	printf("The key is:%d\n",ptr->keys);
	printf("The id_no is:%d\n",ptr->id_no);
	printf("The gender is:%c\n",ptr->gender);
}














