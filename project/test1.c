#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	
	sqlite3 *dbp;
	char * errmsg;
	if(sqlite3_open("word.db",&dbp) != SQLITE_OK)
	{
		puts(sqlite3_errmsg(dbp));	
	}

	if(sqlite3_exec(dbp,"create table word (word text primary key,\
		explain text)",NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	return 0;
}
