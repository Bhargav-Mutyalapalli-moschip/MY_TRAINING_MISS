#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int s_point;
//scanf("%d",s_point);
void display(void**dptr);
void **allocate();
void freeptr(char **dptr);
int main()
{
	void **ptr;
	ptr=allocate();
	printf("%p---%p\n",ptr,&ptr);
	printf("----------The allocation is-%d\n",s_point);
	display(ptr);
	freeptr(ptr);

}
void **allocate()
{
	int str_len,i;
	void **ptr;
	printf("Enter the value to create the number of pointers\n");
	scanf("%d",&s_point);
	printf("The inner def s pointer-----%d\n",s_point);
	ptr=(char**)malloc(s_point*sizeof(char*));
	if(ptr==NULL)
	{
		printf("failed to allocate the memory in heap segment\n");
		exit(1);
	}
	for(i=0;i<s_point;i++)
	{
		printf("Enter the string size of string\n");
		__fpurge(stdin);
		scanf("%d",&str_len);
		ptr[i]=(char*)malloc((str_len+1)*sizeof(char));
		if(ptr[i]==NULL)
		{
			printf("failed to allocate the memory in heap segmenet\n");
			exit(2);
		}
		printf("Enter the string to store\n");
		__fpurge(stdin);

		scanf("%s",((char**)ptr)[i]);
		printf("LOOP ENTERED\n");
	}
	return ptr;
}
void display(void **dptr)
{
	int i;
	printf("ENtering in display loop\n");
	for(i=0;i<s_point;i++)
	{
		printf("%s\n",((char **)dptr)[i]);
	}
	printf("Loop terminating\n");
}
void freeptr(char **dptr)
{
	int i;
	for(i=0;i<s_point;i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}



