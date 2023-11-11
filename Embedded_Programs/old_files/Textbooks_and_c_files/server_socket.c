#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
int sret;
#define PORT 9963
int main()
{
	int i,n=100;
	fd_set fr,fw,fe;
	struct sockaddr_in var;
	struct timeval tv;
	//Intialize the WSA variables
	//set of functions nothing but the environment (API's the socket programming on your laptop
	int ret,bret=0,lret;
	ret=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(ret < 0)
	{
		printf("Failed to open the socket\n");
		exit(1);
	}
	printf("Successfully socket is opened\n");
	printf("The socket id:%d\n",ret);
	//Intializing the environment for sockaddr structure
	var.sin_family=AF_INET;
	var.sin_port=htons(PORT);
	//var.sin_addr.s_addr=inet_addr("127.0.0.1");
	var.sin_addr.s_addr = INADDR_ANY;
	memset(&(var.sin_zero),0,8);
	bret=bind(ret, (struct sockaddr*)&var , sizeof(struct sockaddr));
	if(bret < 0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	printf("The bret:%d\n",bret);
	lret=listen(ret,5);
	if(lret < 0)
	{
		printf("Failed to listen\n");
		exit(1);
	}
	printf("The lret:%d\n",lret);
	/*for(i=0;i<64;i++)
	{
		FD_SET(n,&fr);
		n++;
	}
	for(i=0;i<64;i++)
	{
		printf("The out:%d\n",fr.fd_array[i]);
	}*/
	sret=ret;
	tv.tv_sec=20;
	tv.tv_usec=0;
	FD_ZERO(&fr);
	FD_ZERO(&fw);
	FD_ZERO(&fe);
	FD_SET(ret,&fr);
	FD_SET(ret,&fe);
	sret=select(sret+1,&fr,&fw,&fe,&tv);
	if(sret > 0)
	{
		//when someone connects or communicates with a message over a dedicated connection
		printf("when someone connects or communicates with a message over a dedicated connection\n");
	}
	else if(sret == 0)
	{
		//No connection or any communication request made or you can say that none of the socket descriptors are ready
		printf("No connection or any communication request made or you can say that none of the socket descriptors are ready\n");
	}
	else
	{
		printf("Select function failes\n");
	}



	 


}


