#include<stdio.h>
int main()
{
	char *mainstring;
	mainstring=(char*)malloc(20*sizeof(char));
	mainstring[0]='p';
	mainstring[1]='r';
	mainstring[2]='a';
	mainstring[3]='n';
	mainstring[4]='a';
	mainstring[5]='v';
	mainstring[6]='v';

	printf("%s",mainstring);
	printf("The address:%p\n",mainstring);

}
void mystringsearch(char*main,char*search,int sleng,int mleng)
{
	int count=0,i,j,k=0,stat=0;
	for(i=0;i<=(mleng-sleng);)
	{
		k=i;
		stat=0;
		for(j=0;j<sleng;j++,k++)
		{
			if(main[k]==search[j])
			{
				stat++;
			}
		}
		printf("%d\n",i);
		if(stat==sleng)
		{
			count++;
			printf("entered%d\n",i);
			i=i+sleng;
		}
		else
			i++;
	}
	if(count>=1)
	{
		printf("The string is found\n %d\n",count);
	}
}
