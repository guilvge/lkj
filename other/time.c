#include <stdio.h>
#include <time.h>
int main(int argc, const char *argv[])
{
	time_t t;
	struct tm * tm;
	while(1)
	{
		t = time(NULL);
		tm = localtime(&t);
		printf("%d-%02d-%02d  %02d:%02d:%02d\n",tm ->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
		sleep(1);
	}
	return 0;
}
