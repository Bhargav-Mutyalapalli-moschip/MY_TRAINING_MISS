#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100];
	char str2[100];
	printf("Enter boy name:");
	scanf("%s",str1);
	__fpurge(stdin);
	printf("Enter girl name:");
	scanf("%s",str2);
	__fpurge(stdin);
	delete_match(str1,str2);
}
void delete_match(char *str1,char *str2)
{
	int leng1,leng2.i,j,count=0;
	leng1=strlen(str1);
	leng2=strlen(str2);
	for(i=0;str1[i]!='\0';i++)
	{
		for(j=0;str2[j]!='\0';j++)
		{
			if(str1[i]==str2[j])
			{







