#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	FILE *fp_w;
	char buf[128];
	fp_w = fopen("./2.c","w+");
	
	while(fgets(buf,sizeof(buf),stdin)!= NULL)
	{
		if (strcmp(buf,"quit\n")==0)
		{
			return 0;
		}
		fputs(buf,fp_w);
	}
#if 0
	if (feof(fp_r)!= 0)
	{
		puts("it is the end of the file");
	}
	else
	{
		puts("the file is error");
	}
#endif
	return 0;
}
