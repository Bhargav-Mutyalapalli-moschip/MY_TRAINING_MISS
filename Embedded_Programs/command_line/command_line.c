#include<stdio.h>
int main(int argc,char*argv[])
{
	argv[1][0]='-';
	if(argc<=2)
	{
		printf("it has too few arguments\n");
	}
	int i;
	for(i=0;i<argc;i++)
	{
		if(argv[1][0]=='-')
		{
			count++;
		}

