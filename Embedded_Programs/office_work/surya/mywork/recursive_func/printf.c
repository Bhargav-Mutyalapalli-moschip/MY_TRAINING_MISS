#include<stdio.h>
int main()
{
	int(*fptr)(const char* src,...);
	fptr=printf;
	fptr("Welcome\n");
}
