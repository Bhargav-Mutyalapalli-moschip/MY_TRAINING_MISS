#include<stdio.h>
#include<string.h>
void string_rev(char str[],int i,int l);
void rev_word(char str[],int l);
int main()
{
	int i=0,j,l;
	char str[20];
	scanf("%[^\n]",str);
	l=strlen(str);
	string_rev(str,i,l);
	rev_word(str,l);
}
void string_rev(char str[],int i,int l)
{
	char temp;
	printf("The i:%d-----The l:%d\n",i,l);
	for(i,l=l-1;i<l;l--,i++)
	{
		temp=str[i];
		str[i]=str[l];
		str[l]=temp;
	}
	printf("The output:%s\n",str);
}
void rev_word(char str[],int l)
{
	int i,j,k=0;
	int count=0;
	for(i=0;i<=l;i++)
	{
		printf("The i:%d\n",i);
		if(str[i]==' ' ||  i==l)
		{

			printf("The string:%d\n",i);
			string_rev(str,k,count+k);
			k=i+1;
			count=0;
		}
		else
			count++;
	}
	str[l]='\0';
	printf("The main output:%s\n",str);
}



	
