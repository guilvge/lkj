#include <stdio.h>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define BACKLOG 10
int main(int argc, const char *argv[])
{
	int socketfd,newfd;
	struct sockaddr_in addr,dest_addr;
	
	int len ;
	socketfd = socket(AF_INET, SOCK_STREAM, 0); 
	dest_addr.sin_family = AF_INET;  
	dest_addr.sin_addr.s_addr = inet_addr("192.168.0.239");
	dest_addr.sin_port = htons(50001);
	bind(socketfd,(struct sockaddr *)&dest_addr,len);
	listen(socketfd,BACKLOG);
	while(1){
		len = sizeof(addr);
		newfd =	accept(socketfd,(struct sockaddr*)&addr,&len);
		if (!fork())
		{
			send(new_fd,"hello world\n",14,0);
		}
		close(newfd);
		while(waitpid(-1,NULL,0)>0);
			}

	return 0;
}
