#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        int fd,ret;
        char buf[100];
        fd=open("/dev/pranav",O_RDWR);
        if(fd < 0)
        {
                printf("Fail\n");
                exit(1);
        }
        printf("Successfully communicated\n");
	scanf("%[^\n]",buf);
        ret=write(fd,buf,strlen(buf));
        if(ret < 0)
        {
                printf("Failed to perform write operation\n");
                exit(1);
        }
        close(fd);



}

