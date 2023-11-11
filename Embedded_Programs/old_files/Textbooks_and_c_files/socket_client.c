#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int sockfd,ret;
	char buf[256]="HI";
	struct sockaddr_in serv;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_port=8080;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	ret=send(sockfd,"HI",strlen("hi"),0);
	ret=recv(sockfd,buf,256,0);



}
