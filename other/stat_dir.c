#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	struct stat buf;
	DIR * dir = opendir(argv[1]);
	struct dirent * dirent;
	char buf_dir[100],buf_file[100];
 	chdir(argv[1]);
	while ((dirent = readdir(dir)) != NULL)
	{
		if (dirent->d_name[0]=='.')
			continue;
#if 0
		len = strlen(dirent->d_name);
		if (dirent->d_name[len-1] == '/')
		{
			
			strcat(argv[1],dirent->d_name);
		}
		else
		{
			dirent->d_name[len] == '/';
		}
#endif 
		stat(dirent->d_name,&buf);
		printf("%-20s\t%ld\n",dirent->d_name,buf.st_size);
	}
	return 0;
}
