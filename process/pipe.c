#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	int fd[2];
	pipe(fd);
	pid_t pid ;
	pid = fork();
	char buf[128];
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		close(fd[0]);
		while(1)
		{
			bzero(buf,sizeof(buf));
			read(0,buf,sizeof(buf));
			write(fd[1],buf,strlen(buf)+1);
		}
	}
	else 
	{
		
		close(fd[1]);
		while(1)
		{
#if 0
			strcpy(buf,"dong dong is bitch");
			puts(buf);
#endif
			read(fd[0],buf,sizeof(buf));
			write(1,buf,strlen(buf)+1);
			if (strcmp(buf,"quit\n") == 0)
			{
				break;
			}
		}
	}

	return 0;

}
