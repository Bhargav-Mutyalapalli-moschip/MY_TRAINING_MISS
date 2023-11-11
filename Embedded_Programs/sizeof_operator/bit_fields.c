#include<stdio.h>
#pragma pack(1);
struct node
{
	unsigned x:5;
	unsigned y:4;
	unsigned f:7;
	int z;
};
int main()
{
	struct node var;
	var.x=31;
	var.y=12;
	var.f=125;
	var.z=2000;
	printf("The day:%d-----The month:%d-----The year:%d------th check:%hd\n",var.x,var.y,var.z,var.f);
	printf("size of%d\n",sizeof(var));
}
