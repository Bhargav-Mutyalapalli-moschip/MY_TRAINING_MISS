#include<stdio.h>
struct node
{
	char arr[100];
	int a;
	float b;
	char c;
};
int main()
{
	struct node var;
	printf("The size:%d\n",sizeof(var));
}

