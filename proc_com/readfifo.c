#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	int fd;
	int n;
	char buf_r[64];
	char buf_w[64];
//	mkfifo("./fifo",0664);

	if(mkfifo("./fifo",0664)  == -1)
	{
		if(errno == EEXIST)//有名管道已经被创建，这里直接打开有名管道
		{
			fd = open("./fifo",O_RDWR);
		}
		else 
		{
			perror("mkfifo");
			exit(1);
		}
	}
	else //当前进程创建的有名管道
	{
		fd = open("./fifo",O_RDWR);
	}
	//	fd = open("./fifo",O_RDONLY);
	while (1)
	{
		lseek(fd,0,SEEK_SET);
		n = read(fd,buf_r,sizeof(buf_r) - 1);
		buf_r[n] = '\0';
		printf("%s",buf_r);
		if (strcmp(buf_r,"quit\n") == 0)
		{
			break;
		}


#if 
		fgets(buf_w,sizeof(buf_w),0);
		lseek(fd,64,SEEK_SET);
		write(fd,buf_w,strlen(buf_w)+1);
#endif
	}
	return 0;
}
