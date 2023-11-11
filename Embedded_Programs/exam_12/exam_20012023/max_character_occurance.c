#include<stdio.h>
#include<string.h>
int chr_max(char*str,char*letter)
{
	int i,j,count1=0,count2=0;
	for(i=0;str[i]!='\0';i++)
	{
		count1=0;
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count1++;
			}
		}
		if(count1>count2)
		{
			count2=count1;
			*letter=str[i];
		}
	}
	return (++count2);
}
int main()
{
	char str[100],letter;
	int res;
	printf("enter the statement : ");
	scanf("%[^\n]s",str);
	res=chr_max(str,&letter);
	printf("letter : '%c' occured : %d \n",letter,res);
}

