#include<stdio.h>
#pragma pack(1)
struct employee 
{
	char name;
	float price;
	int id;
};
int main()
{
	struct employee e;
	printf("The total size:%d\n",sizeof(e));
}

