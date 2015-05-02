#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_r,*fp_w;
	char buf[128];
	fp_r = fopen("./1.c","r+");
	fp_w = fopen("./2.c","w+");
	
	while(fgets(buf,sizeof(buf),fp_r)!= NULL)
	{
		fputs(buf,fp_w);
	}
	if (feof(fp_r)!= 0)
	{
		puts("it is the end of the file");
	}
	else
	{
		puts("the file is error");
	}
	return 0;
}
