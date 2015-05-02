#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_r,*fp_w;
	fp_r = fopen("./1.c","r+");
	fp_w = fopen("./2.c","w+");
	int ch = fgetc(fp_r);
	while(feof(fp_r)== 0)
	{
		fputc(ch,fp_w);
		ch = fgetc(fp_r);
	}

	return 0;
}
