#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
void search(char *str,char *ptr,char *nptr);
int main()
{
        char str_main[100];
        char str_search[20];
	char str_replace[40];
        printf("enter a main string:");
        scanf("%[^\n]",str_main);
        __fpurge(stdin);
        printf("enter a serach string:");
        scanf("%s",str_search);
        __fpurge(stdin);
        printf("enter a replace string:");
        scanf("%s",str_replace);
        __fpurge(stdin);
        search(str_main,str_search,str_replace);
}
void search(char *str,char *ptr,char *nptr)
{
        int i,j,k,count=0,maincount=0,a,b,cnt=0;
        int mainlen,searlen,replacelen;
        mainlen=strlen(str);
        searlen=strlen(ptr);
	replacelen=strlen(nptr);
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
			char *newString = (char *)malloc(i + count * (replacelen - searlen) + 1);
			int h=0;
			while (*str) {
				if (strstr(str, ptr) == str) {
					strcpy(&newString[h], nptr);
					h += replacelen;
					str += searlen;
				}
				else
					newString[h++] = *str++;
			}
			printf("The new :%s\n",newString);
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

