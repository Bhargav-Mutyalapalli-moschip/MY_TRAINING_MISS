#include<stdio.h>
#include<stdlib.h>
int main()
{
	char buff[1];
	int ret;
	FILE *fp;
	fp=fopen("sample.txt","r+");
	if(fp==NULL)
	{
		printf("Failed to open\n");
		exit(1);
	}
	while((fscanf(fp,"%[^\n]s",buff)!=EOF))
	printf("The string after reading from file:%s\n",buff);
	printf("The value ret is:%d\n",ret);
	fclose(fp);
}

