#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	char str[20];
	printf("Main string:\n");
	scanf("%s",str);
	char word[200];
	printf("Comparing string:\n");
	scanf("%s",word);
	for(i=0;str[i]!='\0';i++)
	{
		for(j=0;word[j]!='\0';j++)
		{
			if(str[i]==word[j])
			{
				for(k=j;word[k]!='\0';k++)
				word[k]=word[k+1];
			i=i-1;
			}
		}
	}
	printf("The output:%s\n",word);
}



