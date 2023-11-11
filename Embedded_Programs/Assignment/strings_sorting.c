#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
int main()
{
	char *str[10];
	char temp[100];
	int i,count,j;
	char *ptr;
	char *ptr1;
	for(i=0;i<5;i++)
	{
		ptr=(char *)malloc(30*sizeof(char));
		scanf("%s",ptr);
		ptr1=(char *)realloc(ptr,strlen(ptr)+1);
		__fpurge(stdin);
		str[i]=ptr1;
	}
	printf("Printing the strings\n");
	for(i=0;i<5;i++)
	{
		printf("%s\n",str[i]);
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if((strcmp(str[i],str[j]))>0)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}


	}
	printf("After sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%s\n",str[i]);
	}
	

}
	




