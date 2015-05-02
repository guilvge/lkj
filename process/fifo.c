#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
int main(int argc, const char *argv[])
{
	FILE * fp;
	char buf[128];
	if (mkfifo("./fifo",0664) < 0)
	{
		
		if ( errno == EEXIST)
		{
			fp = fopen("./fifo","a+");

		}
		else 
		{
			perror("mkfifo");
		}
	}
	else 
	{
		fp = fopen("./fifo","a+");	
	}
	while(1)
	{
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		fwrite(buf,1,strlen(buf)+1,fp);	
	}
	return 0;
}
