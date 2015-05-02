#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_w;
	char buf[128];
	fp_w = fopen("./2.c","w+");
	int count ;
	while(1)
	{
		count = fread(buf,1,sizeof(buf),stdin);
		fwrite(buf,1,count,fp_w);
		fflush(fp_w);
		if (count < sizeof(buf))
		{
			if (feof(stdin)!= 0)
			{
				puts("it is the end of the file");
				return 0;
			}
			else
			{
				puts("the file is error");
				return -1;
			}


		}
	}
	return 0;
}
