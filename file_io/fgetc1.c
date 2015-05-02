#include <stdio.h>
int main(int argc, const char *argv[])
{
	FILE *fp_w;
	fp_w = fopen("./2.c","w+");
	int ch = fgetc(stdin);
	while(ch != 10)
	{
		fputc(ch,fp_w);
	//	fflush(NULL);
		ch = fgetc(stdin);
	}

	return 0;
}
