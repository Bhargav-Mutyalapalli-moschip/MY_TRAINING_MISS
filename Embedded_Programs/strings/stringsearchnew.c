#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int count=0,stat=0,i,j,k;
	int mainlength,searchlength,replacelength;
	char* mainstring;
	mainstring=(char*)malloc(10*sizeof(char));
	scanf("%[^\n]",mainstring);
	mainlength=strlen(mainstring);
	char* searchstring;
	searchstring=(char*)malloc(50*sizeof(char));
	scanf("%s",searchstring);
	searchlength=strlen(searchstring);
	char*replacestring;
	replacestring=(char*)malloc(10*sizeof(char));
	scanf("%s",replacestring);
	replacelength=strlen(replacestring);
	printf("The mainstring lenth is=====%d-----------------%d---------%d\n",mainlength,searchlength,replacelength);
	printf("%p-----------%p-----------------%p\n",mainstring,searchstring,replacestring);
	for(i=0;i<=(mainlength-searchlength);  )
	{
		k=i;
		for(j=0;j<searchlength;j++,k++)
		{
			if(mainstring[k]==searchstring[j])
			{
				stat=0;
			}
			else
				stat=1;
		
		}
		printf("%d\n",i);

		if(stat==0)
		{

			count++;
			printf("%d\n",i);
			i=i+searchlength;
		}
		else
		i++;
	}
        printf("the repeated count%d\n",count);

		

	
	
}
