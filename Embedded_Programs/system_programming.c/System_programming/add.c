#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=10,b=20;
	a=a+b;
	printf("The output:%d\n",a);
	execl("/home/engineer/Documents/pranav/pranav-20221227T045711Z-001/pranav/addtwo/mywork/System_programming/exec_family_calls/sub","sub",NULL);
}
