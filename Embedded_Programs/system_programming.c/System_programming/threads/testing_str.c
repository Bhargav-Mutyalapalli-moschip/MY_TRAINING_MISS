#include<stdio.h>
#include<string.h>
int main()
{
	char *ptr;
	char str[100]="moschip is the hardware company";
	char repl[20]="hardware";
	ptr=strstr(str,repl);
	printf("The output:%s\n",ptr);
	
}

