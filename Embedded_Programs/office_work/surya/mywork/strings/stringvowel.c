#include<stdio.h>
int main()
{
	int count=0;
	char str[100];
	scanf("%s",str);
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
			{
				count++;
				printf("The small vowel-------%c\n",str[i]);
			}
		}
		else if(str[i]>='A' && str[i]<='Z')
		{
		        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
			{
				count++;
				printf("The capital vowel----%c\n",str[i]);
		        }
		}
	        else
			continue;
	}
	printf("the vowels--------%d\n",count);
}





