#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
int diff=0;
int count=0;
void search_string(char *main,char *search,int mleng,int sleng,int rleng,char *replace);
int main()
{
	int mleng,sleng,rleng,mleng1;
	char *mainstring;
	mainstring=(char *)malloc(100*sizeof(char));
	char searchstring[10];
	char replacestring[10];
	printf("Enter the sentence to perform search and replace\n");
	scanf("%[^\n]",mainstring);
	__fpurge(stdin);
	printf("Enter the search string\n");
	scanf("%s",searchstring);
	__fpurge(stdin);
	printf("Enter the replace string\n");
	scanf("%s",replacestring);
	__fpurge(stdin);
	sleng=strlen(searchstring);
	rleng=strlen(replacestring);
	mleng=strlen(mainstring);
	if(sleng>rleng)
	{
		diff=sleng-rleng;
	}
	else
	{
		diff=rleng-sleng;
	}
	printf("Diff:%d\n",diff);
	mainstring=(char *)realloc(mainstring,(diff+sizeof(char)));
	search_string(mainstring,searchstring,mleng,sleng,rleng,replacestring);
}
void search_string(char *main,char *search,int mleng,int sleng,int rleng,char *replace)
{
	int i,j,k,p,q,r,s,t;
	printf("entered mainloop\n");
	printf("mainlength:%d\nsearchstring:%d\n",mleng,sleng);
	int stat=0;
	for(i=0;i<=((mleng+diff)-sleng);i++)
	{
		k=i;
		stat=0;
		//printf("entered mainloop\n");
		for(j=0;j<sleng;j++,k++)
		{
			if(main[k]==search[j])
			stat++;
		}
		printf("k:%d\ni:%d\n",k,i);
	        printf("The stat:%d\n",stat);
	
		if(stat==sleng)
		{
			t=k;
			q=i;
			if(rleng>=sleng)
			{
				for(p=0;p<=diff-1;p++)
				{
					for(r=mleng+diff;r>=t;r--)
					{
						main[r]=main[r-1];
					}



				}
				for(s=0;s<rleng;s++,q++)
				{
					main[q]=replace[s];
				}


			}
			count++;
			i=i+sleng;

		}
		if(stat==sleng && rleng<sleng)
		{
			t=k;
			q=i-diff;
			if(rleng<sleng)
			{
				for(p=0;p<diff;p++)
				{
					for(r=k-diff;r<mleng-diff;r++)
					{
						main[r]=main[r+1];
					}



				}
				for(s=0;s<rleng;s++,q++)
				{
					main[q]=replace[s];
				}


			}
			count++;
			i=i+sleng;

		}


	}
	printf("The count:%d\n",count);
	printf("The differenece:%d\n",diff);
	printf("The output:%s\n",main);
}



