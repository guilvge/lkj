#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#if 0
int callback (void * flag,int num,char * val[],char * name[])
{
	int i = 0;
	//	printf("%d\n",*(int *)flag);
	if (*(int *)flag == 0)
	{
		for (;i< num;i++)
		{
			printf("%s\t",name[i]);
		}
		*(int *)flag = 1;
		printf("flag");
		putchar(10);
	}
	for (i = 0;i< num;i++)
	{

		printf("%s\t",val[i]);
	}

	printf("%d",*(int *)flag);
	putchar(10);
	return 0;
}
#endif
void insert(sqlite3 *dbp,char *word,char * explain)
{
	char *buf = malloc(128);
	char * errmsg;

   	sprintf(buf,"insert into stu (word,explain) values ('%s','%s');",word,explain);
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
void create_table (sqlite3 * dbp,char * table_name)
{
	char * errmsg;
	char * buf = malloc(128);
	sprintf(buf,"create table %s (word text primary key,explain text);",table_name);
	if(sqlite3_exec(dbp,buf,NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	free(buf);
}
void create_db(const char * path,sqlite3 * dbp)
{
	if(sqlite3_open(path,&dbp) != SQLITE_OK)
	{
		puts(sqlite3_errmsg(dbp));	
	}
	
}
int main(int argc, const char *argv[])
{
	sqlite3 *dbp;
#if 0
	char * errmsg;
	int flag = 0;
	char buf[128];
	

	int id = 10004;
	char * name = "qidongdong";
	float score = 67;
			if(sqlite3_exec(dbp,"insert into stu (id,name,score) values (10001,'qiang',45);",NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	if(sqlite3_exec(dbp,"insert into stu (id,name,score) values (10002,'dong',90);",NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	if(sqlite3_exec(dbp,"insert into stu (id,name,score) values (10003,'li',80);",NULL,NULL,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
  	insert(dbp,id,name,score); 
#endif
	create_db("./word.db",dbp);
	create_table(dbp,"word");
	insert(dbp,"dongdong","son of a bitch");
#if 0

	if(sqlite3_exec(dbp,"select id,name,score from stu;",callback,&flag,&errmsg)!= SQLITE_OK)
	{
		puts(errmsg);
	}
	puts("/******************************************/");
#endif
	print_all(dbp);	
	return 0;
}
