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
	struct sockaddr_in client;
	int socketfd,newsocketfd,ret,bret,client_size;
	char buf[100];
	socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socketfd < 0)
	{
		printf("Failed to create and open the socket\n");
		exit(1);
	}
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORTER);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	ret=connect(socketfd,(struct sockaddr *)&client,sizeof(client));
	if(ret < 0)
	{
		printf("Failed to connect\n");
		exit(1);
	}
	while(1)
	{
		printf("Enter the message to send to server\n");
		__fpurge(stdin);
		scanf("%[^\n]",buf);
		__fpurge(stdin);
		ret=send(socketfd,buf,sizeof(buf),0);
		if(ret < 0)
		{
			printf("Failed to send\n");
			exit(1);
		}
		ret=recv(socketfd,buf,sizeof(buf),0);
		if(ret < 0)
		{
			printf("Failed to send\n");
			exit(1);
		}
		write(1,buf,strlen(buf));
		printf("\n");
	}




}
