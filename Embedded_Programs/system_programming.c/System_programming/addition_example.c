#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=10,b=25,c=0;
	c=a+b;
	printf("The exec family:%d\n",c);
	scanf("%d",&c);
	execl("/home/engineer/Documents/pranav/pranav-20221227T045711Z-001/pranav/addtwo/mywork/System_programming/exec_family_calls
cat","cat","parent_id.c",NULL);
	
}

