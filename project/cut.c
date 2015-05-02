#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	char buf[1024];
	char *buf2, * saveptr;
//	char delim[] = {' '};
	FILE * fp1,*fp2,*fp3;
	fp1 = fopen("./cidian.txt","r+");
	fp2 = fopen("./word.txt","w+");
	fp3 = fopen("./explain.txt","w+");
	while(fgets(buf,sizeof(buf),fp1)!=NULL)
	{
		buf2 = strtok_r(buf,"    ",&saveptr);
		fprintf(fp2,"%s\n",buf);
		fprintf(fp3,"%s\n",saveptr);
	}
	return 0;
}
