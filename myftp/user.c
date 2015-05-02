#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
typedef struct {
	char cmd;
	char len;
	char buf[64];
}send_data_t;

#define DATA 5
#define DATA_END 2 
#define DATA_ERROR -1
#define BACKLOG 10
#define GETUP 1
#define DOWNLOAD 4

int download(int tcp_sock,send_data_t * buf)
{
	//test open file
	FILE * fp;
#if 0
	recv(tcp_sock,buf,sizeof(send_data_t),0);
	if (buf.cmd != DATA)
	{
		printf("you don't have file \n");
		return -1;
	}
#endif
	fp = fopen("./2.c ","w+");
	if (fp)
	{
		buf->cmd = DOWNLOAD;	
		if(send(tcp_sock,buf,sizeof(send_data_t),0) <= 0)
		{
			perror("send");
			exit(-1);
		}
	}
	else 
	{
		perror("fopen");
		return -1;
	}
	//if ok
	//send cmd DOWNLOAD
	if(recv(tcp_sock,buf,sizeof(send_data_t),0) <= 0)
	{
		perror("recv");
		exit(-1);
	}
	if (buf->cmd == DATA_ERROR)
	{
		printf("server fail open file\n");
		return -1;
	}
	//接收 确认
	//

	while(1){
		//recv
		bzero(buf->buf,sizeof(buf->buf));
		if(recv(tcp_sock,&buf,sizeof(buf),0)<=0)
		{
			perror("recv");
			exit(-1);
		}
		if(buf->cmd == DATA_ERROR)
		{
			printf("file error\n");
			exit(-1);
		}
		else 
		{
			
			if(fwrite(buf->buf,1,buf->len,fp)<=0)
			{
				perror("fwrite");
				exit(-1);
			}
			if(buf->cmd ==DATA_END)
			{
				break;
			}
		}
	}


}

void print_user_list ()
{
	puts("All the choice");
	puts("1. getup");
	puts("4. download");
	printf("3 . quit\n");	
}

int main()
{
			
	int tcp_sock,newfd;
	struct sockaddr_in addr;
	tcp_sock = socket(AF_INET,SOCK_STREAM,0);
	if(tcp_sock<0)
	{
		perror("socket");
		exit(-1);
	}
	//socket
	//bind
	addr.sin_family = AF_INET;
	addr.sin_port = htons(50000);
	addr.sin_addr.s_addr = inet_addr("192.168.2.37");

	send_data_t buf;
	//socket
	//
	//connect
	connect(tcp_sock,(struct sockaddr *)&addr,sizeof(addr));
	while(1){
		
		
		print_user_list();
		//等待用户输入指令 fgets
				
	 	fgets(buf.buf,sizeof(buf.buf),stdin);
		printf("%s",buf.buf);
		buf.cmd = buf.buf[0] - '0';
		switch(buf.cmd){
		case DOWNLOAD:
			download(tcp_sock,&buf);
			break;
		}



	}

}
