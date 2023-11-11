#include<stdio.h>
#include<stdlib.h>
int main()
{
	char buff[10]="Ram pranav";
	FILE *fp;
	fp=fopen("test.txt","w+");
	if(fp == NULL)
	{
		printf("Failed to open\n");
		exit(0);
	}
	fprintf(fp,"My name is pranav......\n");
	fprintf(fp,"%s",buff);

	
}

