#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	int fd,newfd,client_size,ret,opt=1;
	char buf[256];
	struct sockaddr_in serv ,client;


	fd = socket(AF_INET ,SOCK_STREAM , IPPROTO_TCP);
	if(fd < 0)
	{
		printf("failed to open the socket\n");
		exit(1);
	}
	printf("fd value is:%d\n",fd);

	bzero(&serv ,sizeof(serv));
//	memset(&serv ,0,sizeof(serv));
	setsockopt(fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt)); 
	serv.sin_family = AF_INET;
	serv.sin_port = htons(5000);
	serv.sin_addr.s_addr = INADDR_ANY;

	ret = bind(fd,(struct sockaddr*) &serv , sizeof(struct sockaddr) );
	if(ret < 0)
	{
		printf("%d\n",ret);
		printf("failed to bind the socket\n");
		exit(1);
	}
	ret = listen(fd , 5);
	if(ret < 0)
	{
		printf("failed to listen\n");
		exit(1);
	}
	client_size = sizeof(client);
	newfd = accept(fd , (struct sockaddr *)&client , &client_size);

	if(newfd < 0)
	{
		printf("failed to connect with the client\n");
		exit(1);
	}
	printf("client fd value is:%d\n",newfd);

	ret = read(newfd,buf ,256);
	write(1,buf,ret);
	ret = write(fd , "hello",5);
	close(newfd);
}
