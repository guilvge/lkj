#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	int fd;
	char buf_r[64];
	char buf_w[64];
	int n;
//	mkfifo("./fifo",0664);

	if(mkfifo("./fifo",0664) == -1)
	{
		if(errno == EEXIST)
		{
			fd = open("./fifo",O_RDWR);
		}
		else 
		{
			perror("open");
			exit(1);
		}
	}
	else 
	{
		fd = open("./fifo",O_RDWR);
	}
//	fd = open("./fifo",O_RDWR);
	while(1)
	{
		lseek(fd,0,SEEK_SET);
		fgets(buf_w,sizeof(buf_w),stdin);
		write(fd,buf_w,strlen(buf_w)+1);
		if (strcmp(buf_w,"quit\n") == 0)
		{
			break;
		}
		lseek(fd,64,SEEK_SET);
		n = read(fd,buf_r,sizeof(buf_r));
		buf_r[n] = '\0';
		printf("%s",buf_r);
	}
	close(fd);
	return 0;
}
