#include <stdbool.h>

#define MAX 100

struct stack
{
	int top;
	char data[MAX];
};

void stack_pop(struct stack* s,char* rec)
{
	*rec = s->data[s->top];
	s->top--;
}

void stack_push(struct stack* s,char e)
{
	s->data[++s->top] = e;
}

bool stack_is_empty(struct stack* s)
{
	return s->top == 0;
}

