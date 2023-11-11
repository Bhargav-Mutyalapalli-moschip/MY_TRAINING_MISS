#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char create[100]="hello";
	int fd;
	mkdir("bank_database",0777);
	opendir("bank_database");
	mkdir("/home/engineer/Documents/pranav/pranav-20221227T045711Z-001/pranav/addtwo/mywork/System_programming/project/bank_database/create",0777);
	open("/home/engineer/Documents/pranav/pranav-20221227T045711Z-001/pranav/addtwo/mywork/System_programming/project/bank_database/create/file1",O_CREAT | O_RDWR,0777);
	open("/home/engineer/Documents/pranav/pranav-20221227T045711Z-001/pranav/addtwo/mywork/System_programming/project/bank_database/create/file2",O_CREAT | O_RDWR,0777);
}



