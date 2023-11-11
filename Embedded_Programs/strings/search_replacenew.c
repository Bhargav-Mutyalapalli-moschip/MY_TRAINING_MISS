#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* mystringcopy(char*dst,char*src);
void mystringsearch(char*main,char*search,int sleng,int mleng);
void myreplace_string(char*mains,char*search,char*replace,int mleng,int sleng,int rleng);
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
	printf("old sentence%s\n",copystring);
	mainstring=(char*)realloc(mainstring,(((replacelength-searchlength)+mainlength)*sizeof(char)));
	printf("%p\n",mainstring);
	myreplace_string(mainstring,searchstring,replacestring,mainlength,searchlength,replacelength);
	free(mainstring);

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
void myreplace_string(char*main,char*search,char*replace,int mleng,int sleng,int rleng)
{

	int s,fat=0;
	main[mleng]='$';
	for(s=mleng;s<(mleng+(rleng-sleng));s++)
	{
		main[s]='$';
	}
	main[s]='\0';
	

	printf("%s\n",main);
	int count=0,i,j,k=0,stat=0,m;
        for(i=0;i<=((mleng+(rleng-sleng))-sleng);)
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
			int q=i,a,f,d;
			count++;
			fat=i+sleng;
			printf("fat:%d\n",fat);
			f=mleng+(rleng-sleng);
			printf("overall:%d\n",f);
                        for(m=f-1;m>fat;m--)
			{
				main[m]=main[m-1];
				printf("loop entereg for shift:%c------%d\n",main[m],m);
			}
			for(m=f-1;m>fat;m--)
                        {
                                main[m]=main[m-1];
                                printf("loop entereg for shift:%c------%d\n",main[m],m);
                        }
			for(m=f-1;m>fat;m--)
                        {
                                main[m]=main[m-1];
                                printf("loop entereg for shift:%c------%d\n",main[m],m);
                        }


			printf("%s\n",main);
			for(a=0;a<rleng;a++)
			{
			
				main[q]=replace[a];
				q++;

			}

			printf("shifted:%s\n",main);
                        printf("entered%d\n",i);
                        i=i+sleng;
                }
                else
                        i++;
        }
        if(count>=1)
        {

	        main=(char*)realloc(main,(((rleng-sleng)+mleng)*sizeof(char)));
                printf("The string is found\n %d\n",count);
        }
}





























