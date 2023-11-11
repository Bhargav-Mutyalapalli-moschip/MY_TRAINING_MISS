#include<stdio.h>
int main()
{
	int a;
	char str1[100];
	char temp;
	scanf("%[^\n]",str1);
	int i,mainlength,k=0,j,stat=0;
	mainlength=strlen(str1);
	for(i=0;str1[i]!='\0';i++)
	{
		str1[mainlength+1]='\0';
		str1[mainlength]=' ';
		if((str1[i]==' ')||(str1[i]=='\0'))
		{
			for(j=i-1,k;j>stat/2,k<stat/2;j--,k++)
			{
				temp=str1[j];
				str1[j]=str1[k];
				str1[k]=temp;
			}
			stat=0;
		}
		stat++;
		
	}
	printf("%s",str1);
}




		
