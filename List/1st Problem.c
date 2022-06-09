#include <stdio.h>
#include <stdlib.h>

int SIZE = 0;
typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void display(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->rlink; p != phead;p = p->rlink) {
		printf("<---- | %p | %d | %p | ----> \n", p->llink, p->data, p->rlink);
	}
	printf("\n");
}

void dinsert_node(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
	SIZE++;
}

void dinsert_last_node(DlistNode* phead, element data) {
	DlistNode* p=phead;
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	int i=0;
	while ((i < SIZE) && p->rlink != NULL) {
		p = p->rlink;
		i++;
	}

	newnode->rlink = p->rlink;
	newnode->llink = p;
	p->rlink = newnode;
	newnode->data = data;
	SIZE++;
}

int main() {
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode* new_node;
	init(head);
	for (int i = 0; i < 5; i++) {
		dinsert_node(head, i);
	}
	display(head);
	printf("\n");
	dinsert_node(head, 10);
	display(head);
	printf("\n");
	dinsert_last_node(head, 20);
	display(head);
	printf("\n");
	
	return 0;
}