#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/socket.h>
int main()
{
	int num=1;
	char buff[100];
	struct sockaddr_in addr;
	int sock_des,ret;
	sock_des=socket(AF_LOCAL,SOCK_DGRAM,0);
	printf("The socket descriptor is:%d\n",sock_des);
	ret=setsockopt(sock_des,SOL_SOCKET,SO_REUSEADDR,&num,sizeof(num));
	if(ret < 0)
	{
		printf("Failed to perform set socket option\n");
		exit(1);
	}
	ret=bind(sock_des,var.sin_addr.s_addr,sizeof(var.sin_addr.s_addr));
	if(ret < 0)
	{
		printf("Failed to assign the address\n");
		exit(1);
	}
	ret=listen(sock_des,1);
	if(ret < 0)
	{
		printf("Failed to listen\n");
		exit(1);
	}
	ret=accept(sock_des,var.sa_data,sizeof(var.sa_data));
	ret=read(sock_des,buff,100);
	if(ret < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	write(1,buff,strlen(buff));




}

