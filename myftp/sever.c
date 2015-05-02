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
int download(int newfd, send_data_t * buf)
{

	// test open file
	FILE * fp;
	int len;
	fp = fopen("./1.c","r+");
	//  1.打开成功
	//  2.打开失败
	if(fp!=NULL)
	{
		buf->cmd = DATA;
		if(send(newfd,&buf,sizeof(send_data_t),0) <= 0)
		{
			perror("send1");
			exit(-1);
		}
	}
	else 
	{
		buf->cmd = DATA_ERROR;
		if(send(newfd,&buf,sizeof(send_data_t),0) <= 0)
		{
			perror("send2");
			exit(-1);
		}

	}





	
	//    send 》》 ok buok
	//
	while(1){
		//read
		bzero(buf->buf,sizeof(buf->buf));
		if((len = fread(buf->buf,1,sizeof(buf->buf),fp))<=0)
		{
			printf("done\n");
			return 0;
		}
		else  if (len < sizeof(buf->buf))
		{
			if (feof(fp)!=0)
			{
				buf->cmd = DATA_END;
				buf->len = len;
				if(send(newfd,buf,sizeof(send_data_t),0) <= 0)
				{
					perror("send3");
					exit(-1);

				}
				break;
			}
			else 
			{
				buf->cmd = DATA_ERROR;
				if(send(newfd,buf,sizeof(send_data_t),0) <= 0)
				{
					perror("send4");
					exit(-1);

				}
				return -1;
			}
		}
		else 
		{
			buf->cmd = DATA;
			buf->len =len;
			if(send(newfd,buf,sizeof(send_data_t),0) <= 0)
			{
				perror("send5");
				exit(-1);

			}

		}
		fclose(fp);
	//	close(newfd);
			
		
		//send
	}
	
}

int getup()
{

}

int main(int argc, const char *argv[])
{
	int tcp_sock,newfd;
	send_data_t buf;
	struct sockaddr_in  addr;
	int addrlen = sizeof(addr);
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
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	if (bind(tcp_sock,(struct sockaddr *)&addr,sizeof(addr)) < 0)
	{
		perror("bind");
		exit(-1);
	}
	//listen
	if (listen(tcp_sock,BACKLOG)<0)
	{
		perror("listen");
		exit(-1);
	}
	while(1){
		//accept();
        newfd = accept(tcp_sock,(struct sockaddr *)&addr,&addrlen);
		if(newfd < 0)
		{
			perror("accept");
			exit(-1);
		}
		if(0 == fork()){
			if(0 == fork()){
				close(tcp_sock);//关闭子进程里用不到的监听套接字
				while(1){
					//.........
					
					//recv(); //接收客户指令
					if(recv(newfd,&buf,sizeof(buf),0) <= 0)
					{
						perror("recv");
						exit(-1);
					}
					switch(buf.cmd){
					case DOWNLOAD:
						download(newfd,&buf);
						break;
					case GETUP:
						getup();
						break;
					}
					//执行指令
					// 1.getup
					// 2.download
					// 3.list 
					// 4.quit
					
				}
			}
			exit(-1);

		}
		close(newfd); //关闭爷爷里用不到的 链接套接字
		//wait(NULL);
	}

	return 0;
}
