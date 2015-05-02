#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid ==0 )
	{
		sleep(10);
		printf("son\n");
		//while(1);
	}
	else 
	{
	//	sleep(20);
		printf("father\n");
		//wait(NULL);
	//	while(1);
	}
	return 0;
}
