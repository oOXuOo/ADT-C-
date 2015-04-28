#include <stdlib.h>

struct stack
{
	char* base;
	char* top;
};

stack* stack_create(int length);
void stack_delete(struct stack* s);
char stack_get_pop(struct stack* s);
void stack_pop(struct stack* s);
void stack_push(struct stack* s,char e);
int stack_is_empty(struct stack* s);

struct stack* stack_create(int length)
{
	struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
	tmp->base =  tmp->top = (char*)malloc(length);
	return tmp;
}

void stack_delete(struct stack* s)
{
	free(s->base);
	free(s);
}

char stack_get_pop(struct stack* s)
{
	return *s->top;
}

void stack_pop(struct stack* s)
{
	s->top--;
}

void stack_push(struct stack* s,char e)
{
	s->top++;
	*s->top = e;
}

int stack_is_empty(struct stack* s)
{
	return s->top == s->base;
}