#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int ret;
	char str[5];
	fp=fopen("sample.txt","r+");
	if(fp==NULL)
	{
		printf("Failed to open\n");
		exit(1);
	}
	
	ret=fscanf(fp,"%s",str);
	str[5]='\0';
	printf("The ret:%d\n",ret);
	printf("The out:%s\n",str);
}


