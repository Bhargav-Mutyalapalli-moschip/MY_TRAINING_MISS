#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 5
int main()
{
	char **ptr=(char **)malloc(ROW*sizeof(char*));
		printf("The address:%p\n",ptr);
	int i,j,n=0;
        for(i=0;i<ROW;i++)
	{
		scanf("%s",&ptr[i]);
		printf("done\n");
		printf("n:%d\n",n);
		n=strlen(ptr);
		printf("n:%d\n",n);
		ptr[i]=(char*)malloc(n*sizeof(char));
		if(ptr==NULL)
		{
			printf("Failed\n");
		}
		printf("The address:%p\n",ptr);
	}

	
}

