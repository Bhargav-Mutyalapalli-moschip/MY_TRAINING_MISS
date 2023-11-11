#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define PORT 9970
int main()
{
	char str[50];
	int bret,lret,ret,c_size;
	int sockfd,newsockfd;
	struct sockaddr_in server,client;
	sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd < 0)
	{
		printf("Failed to open and create the socket\n");
		exit(1);
	}
	memset(&server,0,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	bret=bind(sockfd,(struct sockaddr *)&server,sizeof(server));
	if(bret < 0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	c_size=sizeof(client);
	while(1)
	{
		recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *)&client,&c_size);
		write(1,str,strlen(str));
		memset(str,'\0',sizeof(str));
		printf("\n");
		printf("Send-->client:");
		scanf("%[^\n]",str);
		__fpurge(stdin);
		printf("\n");
		sendto(sockfd,str,strlen(str),0,(struct sockaddr *)&client,sizeof(client));
	}
}





