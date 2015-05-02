#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
	if (argc < 2 )
	{
		printf("the usage : %s <command>\n",argv[0]);
	}
	execl("/bin/bash","bash","-c",argv[1],NULL);
	return 0;
}
