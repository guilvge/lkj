#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
void insert(sqlite3 *dbp,char **word,char **explain)
{
	char *buf = malloc(128);
	char * errmsg;

   	sprintf(buf,"insert into word (word,explain) values ('%s','%s');",*word,*explain);
	//printf("%s\t%s\n",word,explain);
	if(sqlite3_exec(dbp,buf,NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	free(buf);
}
void print_all(sqlite3 * dbp)
{
	char * errmsg;
	int row,column,i,j;
	char ** result;

	if(sqlite3_get_table(dbp,"select word,explain from word;",&result,&row,&column,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	for(i = 0;i < row +1;i++)
	{
		for(j = (i * column);j < column*(i + 1);j++)
		{
			printf("%s\t",result[j]);
		}
		putchar(10);
	}
	sqlite3_free_table(result);

}
void create_table (sqlite3 * dbp,const char * table_name)
{
	char * errmsg;
	char * buf = malloc(128);
	sprintf(buf,"create table %s( word text primary key,explain text);",table_name);
	if(sqlite3_exec(dbp,buf,NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	free(buf);
}
void create_db(const char * path,sqlite3 ** dbp)
{
	if(sqlite3_open(path,dbp) != SQLITE_OK)
	{
		puts(sqlite3_errmsg(*dbp));	
	}
	
}
int main(int argc, const char *argv[])
{
	sqlite3 *dbp;
	FILE * fp1,*fp2;
	char * errmsg;
	char buf[1024],*saveptr,*word;
	char delim[] = {' '};
	char buf_cmd[128];
	fp1 = fopen ("./word1.txt","r+");
	fp2 = fopen ("./explain.txt","r+");
	create_db("./word.db",&dbp);
	create_table(dbp,"word");
	while(fgets(buf,sizeof(buf),fp1)!= NULL)
	{
		sprintf(buf_cmd,"insert into word (word) values ('%s');",buf);
		if(sqlite3_exec(dbp,buf_cmd,NULL,NULL,&errmsg)!= SQLITE_OK)
		{
			puts(errmsg);
		}
		bzero(buf,sizeof(buf));
	}
	while(fgets(buf,sizeof(buf),fp2)!= NULL)
	{
		sprintf(buf_cmd,"insert into word (explain) values ('%s');",buf);
		if(sqlite3_exec(dbp,buf_cmd,NULL,NULL,&errmsg)!= SQLITE_OK)
		{
			puts(errmsg);
		}
		bzero(buf,sizeof(buf));
	}


	return 0;
}
