#include<stdio.h>
struct tab
{
	int data;
	int ven;
	char arr[100];
	float var;
};
int main()
{
	struct tab *ptr=NULL;
	ptr++;
	printf("The size : %u\n",ptr);
}
