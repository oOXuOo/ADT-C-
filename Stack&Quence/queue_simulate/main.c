#include <stdio.h>
#include "stack.h"

struct queue
{
	struct stack* main_stack;
	struct stack* asst_stack;
};

void enqueue(struct queue* q,char e)
{
	stack_push(main_stack,e);
}

void dequeue(struct queue* q,char* rec)
{
	while(!stack_is_empty(q->main_stack))
		{
		char tmp;
		stack_pop(q->main_stack,&tmp);
		stack_push(q->asst_stack,tmp);
		}
	stack_pop(q->asst_stack,rec);
	while(!stack_is_empty(q->asst_stack))
		{
		char tmp;
		stack_pop(q->asst_stack,&tmp);
		stack_push(q->main_stack,tmp);
		}
}

bool queue_is_empty(struct queue* q)
{
	return stack_is_empty(q->main_stack);
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
