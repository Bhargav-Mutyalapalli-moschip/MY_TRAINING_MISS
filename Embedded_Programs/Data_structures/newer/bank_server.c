#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTER 9964 
int main()
{
	struct sockaddr_in server,client;
	int socketfd,newsocketfd,ret,bret,client_size,opt=1;
	char buf[100];
	socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socketfd < 0)
	{
		printf("Failed to create and open the socket\n");
		exit(1);
	}
	memset(&server,0,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORTER);
	server.sin_addr.s_addr=INADDR_ANY;
	setsockopt(ret, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt));
	ret=bind(socketfd,(struct sockaddr *)&server,sizeof(server));
	if(ret < 0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	printf("The socketfd:%d-----The ret of bind:%d\n",socketfd,ret);
	ret=listen(socketfd,5);
	if(ret < 0)
	{
		printf("Failed to listen\n");
		exit(1);
	}
	printf("The socketfd:%d-----The ret of listen:%d\n",socketfd,ret);
	client_size=sizeof(struct sockaddr);
	newsocketfd=accept(socketfd,(struct sockaddr *)&client,&client_size);
	if(newsocketfd < 0)
	{
		printf("Failed to accept\n");
		exit(1);
	}
	while(1)
	{
		ret=recv(newsocketfd,buf,sizeof(buf),0);
		if(ret < 0)
		{
			printf("Failed to send\n");
			exit(1);
		}
		write(1,buf,strlen(buf));
		printf("\n");
		printf("Enter the message to send to client\n");
		__fpurge(stdin);
		scanf("%[^\n]",buf);
		__fpurge(stdin);
		ret=send(newsocketfd,buf,sizeof(buf),0);
		if(ret < 0)
		{
			printf("Failed to send\n");
			exit(1);
		}
	}




}




