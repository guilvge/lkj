#include <stdio.h>
#define MAX_QUEUE 10
typedef struct queue_s
{
	int front ;
	int rear ;
	int data[0]
}q_t;
q_t * create ()
{
	q_t * q =malloc(sizeof(q_t)+sizeof(int )* MAX_QUEUE);
	q -> front = 0;
	q -> rear = 0;
	return q;
}
int en_queue (q_t * q,int *data)
{
	if (q -> rear > MAX_QUEUE -1)
	{
		puts("it is full");
		return -1;
	}
	q->data[rear++] = *data;
}
int main(int argc, const char *argv[])
{
	
	return 0;
}
