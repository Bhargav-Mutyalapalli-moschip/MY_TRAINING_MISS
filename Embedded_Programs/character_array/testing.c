#include<stdio.h>
int main()
{
	char str1[6]="pranav";
	char str2[6]="ram";
	int i,j,k;
	printf("%s-------------%s\n",str1,str2);
	char temp;
	for(i=0;str1[i]!='\0' && str2[i]!='\0';i++)
	{
		temp=str1[i];
		str1[i]=str2[i];
		str2[i]=temp;
		printf("The i value i:%d\n",i);
	}
	printf("%s------------%s\n",str1,str2);
	if(str1[i]!='\0')
	{
		for(j=i;str1[j]!='\0';j++)
		{
			printf("The j value:%d-------the i value:%d\n",j,i);
			str2[j]=str1[j];
			printf("%s------%s\n",str2,str1);
		}
		str2[j]='\0';
		str1[i]='\0';
	}
	printf("%s-------------%s\n",str1,str2);
	/*for(k=0;str1[k]!='\0';k++)
		printf("the way:%c\n",str1[k]);*/
}

