#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>

void main()
{
	int fd,ret;
	struct sockaddr_in serv;
	char buf[100] ="hi babu";

	fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(fd < 0)
	{
		printf("failed to open the file\n");
		exit(1);
	}
	bzero(&serv , sizeof(serv));

	serv.sin_family = AF_INET;
        serv.sin_port = htons(5000);
        serv.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(fd , (struct sockaddr*)&serv , sizeof(serv));

	write(fd , buf , strlen(buf));
	read(fd ,buf ,5);
	write(1,buf ,5);
}
