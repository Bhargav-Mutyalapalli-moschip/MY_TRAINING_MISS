#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>
#include<sys/stat.h>
//#include<fs.h>
#include<stdio_ext.h>
int main(int argc,char *argv[])
{
	struct stat var;
	struct tm dt;

	if(argv[1]==NULL)
	{
		printf("condition: missing operand\nTry 'condition --help' for more information\n");
		exit(-1);
	}
	int fd;
	if((stat(argv[1],&var))!=0)
	{
		printf("stat: cannot statx '%s': No such file or directory\n",argv[1]);
		exit(-1);
	}
	printf("The file size is:%ld\n",var.st_size);
	printf("The file permission is:%d\n",var.st_dev);
	printf("The file kink count is:%ld\n",var.st_nlink);
	printf("The file user id is:%d\n",var.st_uid);
	printf("The file inode number is:%ld\n",var.st_ino);
	printf("The group id of the file's group:%d\n",var.st_gid);
	dt = *(gmtime(&var.st_ctime));
	printf("The file time of last access is:%d------------%d----%d\n",dt.tm_mday,dt.tm_mon+1,dt.tm_year+1900);
	dt = *(gmtime(&var.st_mtime));
	printf("The file time of last modification is:%d------------%d----%d\n",dt.tm_mday,dt.tm_mon+1,dt.tm_year+1900);
	dt = *(gmtime(&var.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon+1, dt.tm_year + 1900,
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&var.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon+1, dt.tm_year + 1900,
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
	printf("\nFile Permissions User\n");
	printf((var.st_mode & S_IRUSR)? "r":"-");
	printf((var.st_mode & S_IWUSR)? "w":"-");
	printf((var.st_mode & S_IXUSR)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Group\n");
	printf((var.st_mode & S_IRGRP)? "r":"-");
	printf((var.st_mode & S_IWGRP)? "w":"-");
	printf((var.st_mode & S_IXGRP)? "x":"-");
	printf("\n");
	printf("\nFile Permissions Other\n");
	printf((var.st_mode & S_IROTH)? "r":"-");
	printf((var.st_mode & S_IWOTH)? "w":"-");
	printf((var.st_mode & S_IXOTH)? "x":"-");
	printf("\n");


}







