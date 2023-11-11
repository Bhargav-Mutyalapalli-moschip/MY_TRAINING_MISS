#include<stdio.h>
char dd[100];
char cc[100];
int i,k;
int mystrlen(char *dd)
{
	//int i;
	printf("entered strlen\n");
	if(dd==NULL)
		return 0;
	for(i=0;dd[i]!='\0';i++)
	{k=i;
		return k;
}
}
char *mystrcpy(char *dist,char *src)
{
	printf("entered strcpy\n");
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dist[i]=src[i];
	}

	dist[i]='\0';
	printf("%s",dist);
	return ;


char* mystrrev(char *s1)
{	
	printf("entered mystrrev\n");
	int i=0,j,temp;
	j=mystrlen(s1);
	if(s1==NULL)
		return -1;
	else
	{
		for(i=0;s1[i]!='\0';i++)
		{
			str[i]=s1[i];
		}
		str[i]=s1[i];
		for(i=0,j=j-1;i<j;i++,j--)
		{
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
		}
	//	printf("%p----%s\n",str,str);

		return str;
}
char *mystrrev(char *cc)
{
	int l,i;
	char temp;
	printf("entered str rev\n");
	if(dd==NULL)
	{
		return NULL;
	}
	//printf("%s\n",dd);
	//l=mystrlen(dd);
	//printf("%d\n",l);
	for(i=0,k=k-1;i<k;i++,k--)
	{
		temp=cc[i];
		cc[i]=cc[k];
		cc[k]=temp;
	}
	printf("%s\n",cc);
	return cc;

}
int mystrcmp(char *cc,char *dd)
{
	int i;
	for(i=0;(cc[i]!='\0' || dd[i]!='\0');i++)
	{
		if(cc[i]!=dd[i])
		{
			return (cc[i]-dd[i]);
		}
	}
	return 0;
}
int main()
{
	int i,prog;
	while(1)
	{
		printf("Menu\n");
		printf("1.Palindrome number\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);
			case 1:
				printf("Enter the string to check palindrome\n");
				scanf("%s",dd);
				mystrcpy(cc,dd);
				mystrrev(cc);			
				i=mystrcmp(dd,cc);
				if(i==0)
					printf("palindrome number\n");
				else
					printf("not a palindrome number\n");

		}
	}
}















