#include<unistd.h>
#include<stdio.h>
int main()
{
	int fds[2];
	pipe(fds);
	close(fds[0]);
	write(fds[1],fds,sizeof(*fds));
	return 0;
}

