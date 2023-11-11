#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct details
{
	char str[20];
	int age;
	void (*surya)(int);
	int (*suryaf)(char *src,...);
};
void read(int);
int main()
{
	struct details var;
	struct details *ptr;
	printf("Enter the name\n");
	scanf("%s",var.str);
	__fpurge(stdin);
	printf("Enter the age\n");
	scanf("%d",&var.age);
	ptr=&var;
	printf("The name is:%s\n",ptr->str);
	printf("The age is:%d\n",ptr->age);
	var.surya=read;
	var.surya(var.age);
	var.suryaf=printf;
	var.suryaf("The name is:%s\n",ptr->str);
	var.suryaf("The age is:%d\n",ptr->age);
	
}
void read(int num)
{
	printf("The received age is:%d\n",num);
}



