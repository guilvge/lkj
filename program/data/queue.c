#include <stdio.h>
#include <stdlib.h>
typedef struct queue 
{
	int front;
	int rear;
	int data;
}q_t;
q_t * create()
{
	q_t * q = malloc(sizeof(q_t));
	q->front = 0;
	q-> rear = 0;
	return q;
}
int en_queue (q_t * q,int * data)
{
	
}
int main(int argc, const char *argv[])
{
	
	return 0;
}
