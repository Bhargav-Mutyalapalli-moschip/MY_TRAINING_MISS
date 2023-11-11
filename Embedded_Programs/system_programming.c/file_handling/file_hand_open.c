#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp=fopen("sample1.txt","a");
	if(fp!=NULL)
	{
		printf("Opened successfully\n");
	}
}

