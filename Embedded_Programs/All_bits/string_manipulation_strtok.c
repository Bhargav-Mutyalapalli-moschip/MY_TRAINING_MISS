#include<stdio.h>
int main()
{
	char str[100]="My name is pranav";
	//char p[2]=" ";
	char *token;
	token=strtok(str," ");
	printf("%s",token);
}
