#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 9
typedef struct stack 
{
	int top ;
	int p[0];
}s_t;
s_t  * create()
{
	s_t * s = malloc(sizeof(s_t)+MAX_SIZE*sizeof(int));
	s->top = -1;
	return s;
}
int  push_stack (s_t * s,int * data)
{
	if (s->top >= MAX_SIZE)
	{
		puts("it is full ");
		return -1;
	}
	s->p[++s->top] = *data;

}
int  pop_stack (s_t * s,int * data)
{
	if (s->top == -1)
	{
		puts("it is empty");
		return -1;
	}
	*data = s->p[s->top--];

}
int main(int argc, const char *argv[])
{
	s_t * s = create(MAX_SIZE);
	int data;
	int i =0,j = 0;
	for ( ; i < 9; i ++)
	{
		push_stack(s,&i);
	}
	for (i = 0;i < 9;i ++)
	{
		printf("%d  ",s->p[i]);
	}
	putchar(10);
	for (i = s->top;i >= 0;i --)
	{
		pop_stack(s,&data);
		printf("the element pop is %d \n",data);
		for (j = s->top;j >= 0;j --)
		{
			printf("%d  ",s->p[j]);
		}
		putchar(10);
	}
	return 0;
}
