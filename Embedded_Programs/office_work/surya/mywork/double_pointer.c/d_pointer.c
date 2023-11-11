#include<stdio.h>
#include<stdlib.h>
int single_pointers;
void freeptr(char **dptr);
void display(char **dptr);
void swap(char **dptr);
char **allocate();
int main()
{
	char **dptr;
	dptr=allocate();
	display(dptr);
	swap(dptr);
	freeptr(dptr);
}
char **allocate()
{
	int str_len,i;
	printf("enter the number of single pointer to create\n");
	scanf("%d",&single_pointers);
	char **sptr=(char**)malloc(single_pointers*sizeof(char*));
	for(i=0;i<single_pointers;i++)
	{
	        printf("enter the string size\n");
	        scanf("%d",&str_len);
		sptr[i]=(char*)malloc((str_len+1)*sizeof(char));
		if(sptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(1);
		}
		printf("Enter the string\n");
	        scanf("%s",sptr[i]);
		
	}
	return sptr;
}
void display(char **dptr)
{
	int i;
	printf("The pointers number:-----%d\n",single_pointers);
	for(i=0;i<single_pointers;i++)
	{
		printf("%s\n",dptr[i]);
	}
}
void freeptr(char **dptr)
{
	int i;
	for(i=0;i<single_pointers;i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}
void swap(char **dptr)
{
	int k,d,p;
	k=strlen(dptr[0]);
	d=strlen(dptr[1]);
	printf("%d-------%d\n",k,d);
	int i;
	char temp;
	for(i=0;dptr[i]!='0';dptr[i+1]!='\0';i++)
	{
		temp=dptr[i];
		dptr[i]=dptr[i+1];
		dptr[i+1]=temp;

	}
	if(

		
}



	
