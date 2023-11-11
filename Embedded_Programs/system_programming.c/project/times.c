#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
	struct stat var;
	stat("000",&var);
	struct tm dt;
	dt = *(gmtime(&var.st_ctime));
	int a=dt.tm_sec;
	int b=dt.tm_min;
	int c=dt.tm_hour;
	int d=dt.tm_mday;
	int e=dt.tm_mon;
	int f=dt.tm_year;
	int g=dt.tm_wday;
	printf("The hour:%d--minute:%d----Sec:%d\n",c,b,a);
}

