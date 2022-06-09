// linked_stack.cpp : Defines the entry point for the console application.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {
	element item;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

typedef struct {
	DlistNode* top;
} LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item)
{
	DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else {
		temp->item = item;
		temp->rlink = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode* temp = s->top;
		element item = temp->item;
		s->top = s->top->rlink;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}




