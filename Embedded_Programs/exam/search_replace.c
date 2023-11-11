#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void search(char *str,char *ptr);
int main()
{
	char str_main[100];
	char str_search[20];
	printf("enter a main string:");
	scanf("%[^\n]",str_main);
	__fpurge(stdin);
	printf("enter a serach string:");
	scanf("%s",str_search);
	__fpurge(stdin);
	search(str_main,str_search);
}
void search(char *str,char *ptr)
{
	int i,j,k,count=0,maincount=0,a,b;
	int mainlen,searlen;
	mainlen=strlen(str);
	searlen=strlen(ptr);
	for(i=0;i<=(mainlen-searlen);i++)
	{
		count=0;
		j=i;
		for(k=0;k<searlen;k++,j++)
		{
			if(str[j]==ptr[k])
			count++;
		}
		if(searlen==count)
		{
			for(a=i,b=j;a<b;a++)
			{
				printf("%c",str[a]);
			}
			printf("\n");
			printf("Index1----:%d-------Index2-----:%d\n",i,j);
			i=i+searlen;
			maincount++;
		}
	}
	if(maincount > 0)
	{
		printf("------String is found %d times\n",maincount);
	}
	else	
		printf("------String is not found %d times\n",maincount);
}




