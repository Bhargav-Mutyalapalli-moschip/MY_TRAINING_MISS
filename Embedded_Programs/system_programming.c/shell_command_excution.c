#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	int k=0,ind=0,i;
	int len;
	char *point;
	char str[100];
	char *ptr[10];
	//while(1)
	{
		printf("Eneter the string\n");
		__fpurge(stdin);
		scanf("%[^\n]",str);
		__fpurge(stdin);
		len=strlen(str);
		for(i=0;i<=len;i++)
		{
			if(str[i]==' ' || i==len)
			{
				if(str[i+1]==' ')
				continue;
				str[i]='\0';
				ptr[ind]=str+k;
				k=i+1;
				ind++;
			}
		}
		for(i=0;i<ind;i++)
		 printf("%s\n",ptr[i]);
	//	fork();
		execvp(ptr[0],ptr);
	}

}









