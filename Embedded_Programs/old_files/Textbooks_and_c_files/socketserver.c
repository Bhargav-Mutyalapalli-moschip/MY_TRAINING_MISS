#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int sockfd,newsockfd,client_size,ret;
	char buf[256];
	struct sockaddr_in serv,client;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_port=8080;
	serv.sin_addr.s_addr=INADDR_ANY;
	bind(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	listen(sockfd,5);
	client_size=sizeof(client);
	newsockfd=accept(sockfd,(struct sockaddr*)&client,&client_size);
	ret=read(newsockfd,buf,256);
	write(1,buf,ret);
	ret=write(newsockfd,"hello",strlen("hello"));
	close(newsockfd);



}
