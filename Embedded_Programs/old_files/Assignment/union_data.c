#include<stdio.h>
int main(void)
{
	union tag
	{
		char name[15];
		int age;
	}rec;
	strcpy(rec.name,"Pranav");
	rec.age=22;
	strcpy(rec.name,"Pranav");
	printf("Name=%d",rec.age);
}
