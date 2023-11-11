#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int count=0,stat=0,i,j;
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
		for(j=0;j<searchlength;j++,i++)
		{
			if(mainstring[i]==searchstring[j])
			{
				if(replacelength==searchlength)
				{

					mainstring[i]=replacestring[j];
					stat=0;
				}
				else
					searchlength=replacelength;
				        mainstring[i]=replacestring[j];
					stat=0;
				
				
			}
			else
				stat=1;
		
		}

		if(stat==0)
		{


			count++;
			i=i+searchlength;
		}
		else
		i++;
	}

	printf("%s\n",mainstring);
        printf("the repeated count%d\n",count);

		

	
	
}
