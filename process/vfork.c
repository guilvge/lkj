#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	pid_t pid;
	pid = vfork();
	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if (pid == 0)
	{
		puts("it is the son");
		exit(-1);
	}
	else 
	{
		usleep(10000);
		puts("it is father");
	}
	return 0;
}
