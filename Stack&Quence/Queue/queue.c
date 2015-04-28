#include "queue.h"
#include <stdlib.h>
struct queue* queue_create()
{
	struct queue* Q = (struct queue*)malloc(sizeof(struct queue));
	Q->front = Q->rear = 0;
	return Q;
}
void queue_delete(struct queue* Q)
{
	free(Q);
}
void enqueue(struct queue* Q,void* e)
{
	Q->rear = (Q->rear+1)%30;
	Q->data[Q->rear] = e;
}

void* dequeue(struct queue* Q)
{
	Q->front = (Q->front+1)%30;
	return Q->data[Q->front];
}

bool queue_is_empty(struct queue* Q)
{
	return Q->front==Q->rear;
}

bool queue_is_full(struct queue* Q)
{
	return Q->front==(Q->rear+1);
}

