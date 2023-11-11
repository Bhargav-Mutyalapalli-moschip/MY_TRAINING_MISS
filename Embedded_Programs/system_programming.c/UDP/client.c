#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 9970
int main()
{
	char str[50];
	int bret,lret,ret,c_size;
	int sockfd,newsockfd;
	struct sockaddr_in client;
	sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd < 0)
	{
		printf("Failed to open and create the socket\n");
		exit(1);
	}
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	while(1)
	{
		printf("Send-->server:");
		memset(str,'\0',sizeof(str));
		scanf("%[^\n]",str);
		__fpurge(stdin);
		printf("\n");
		sendto(sockfd,str,strlen(str),0,(struct sockaddr *)&client,sizeof(client));
		recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *)&client,&c_size);
		write(1,str,strlen(str));
		printf("\n");
	}
	close(sockfd);
}
