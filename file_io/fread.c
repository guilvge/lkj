#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_r,*fp_w;
	char buf[128];
	fp_r = fopen("./1.c","r+");
	fp_w = fopen("./2.c","w+");
	int count ;
	while(1)
	{
		int count = fread(buf,1,sizeof(buf),fp_r);
		fwrite(buf,1,count,fp_w);
		if (count < sizeof(buf))
		{
			if (feof(fp_r)!= 0)
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
