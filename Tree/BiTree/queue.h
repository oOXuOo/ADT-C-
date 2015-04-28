#include <stdio.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
	int front;
	int rear;
	void* data[30];
};

struct queue* queue_create();
void queue_delete(struct queue* Q);
void enqueue(struct queue* Q,void* e);
void* dequeue(struct queue* Q);
bool queue_is_empty(struct queue* Q);
bool queue_is_full(struct queue* Q);

#endif