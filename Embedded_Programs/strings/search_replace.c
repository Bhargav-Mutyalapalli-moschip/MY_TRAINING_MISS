#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* mystringcopy(char*dst,char*src);
void mystringsearch(char*main,char*search,int sleng,int mleng);
int main()
{
	int mainlength,searchlength,replacelength;
	char *mainstring;
	mainstring=(char*)malloc(200*sizeof(char));
	scanf("%[^\n]",mainstring);
	printf("%p\n",mainstring);
	char searchstring[20];
	scanf("%s",searchstring);
	char replacestring[20];
	scanf("%s",replacestring);
	char *copystring;
	copystring=(char*)malloc(100*sizeof(char));
	mystringcopy(copystring,mainstring);
	printf("the main string==%s---------the copied string==%s\n",mainstring,copystring);
	mainlength=strlen(mainstring);
	searchlength=strlen(searchstring);
	replacelength=strlen(replacestring);
	mystringsearch(mainstring,searchstring,searchlength,mainlength);
	printf("%d------%d------%d\n",mainlength,searchlength,replacelength);
}
char* mystringcopy(char*dst,char*src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dst[i]=src[i];
	}
	dst[i]='\0';
	return dst;
}
void mystringsearch(char*main,char*search,int sleng,int mleng)
{
	int count=0,i,j,k=0,stat=0;
	for(i=0;i<=(mleng-sleng);)
	{
		k=i;
		stat=0;
		for(j=0;j<sleng;j++,k++)
		{
			if(main[k]==search[j])
			{
				stat++;
			}
		}
		printf("%d\n",i);
		if(stat==sleng)
		{
			count++;
			printf("entered%d\n",i);
			i=i+sleng;
		}
		else
			i++;
	}
	if(count>=1)
	{
		printf("The string is found\n %d\n",count);
	}
}



