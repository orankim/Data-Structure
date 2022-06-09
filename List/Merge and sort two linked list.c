#include <stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->link;
	}
	printf("\n");
}

ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL) p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* create_node(element data, ListNode* link) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("Memory allocation error");
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

void swap(ListNode* a, ListNode* b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void ascsort(ListNode* head) {
	ListNode* list1;
	ListNode* list2 = NULL;
	int swapped, i;
	if (head == NULL) return;
	do {
		swapped = 0;
		list1 = head;

		while (list1->link != list2) {
			if (list1->data > list1->link->data) {
				swap(list1, list1->link);
				swapped = 1;
			}
			list1 = list1->link;
		}
		list2 = list1;
	}while (swapped);
}

int main() {
	ListNode* a = NULL, * b = NULL, * c = NULL;

	insert_node(&a, NULL, create_node(25, NULL));
	insert_node(&a, NULL, create_node(20, NULL));
	insert_node(&a, NULL, create_node(15, NULL));
	insert_node(&a, NULL, create_node(10, NULL));
	insert_node(&a, NULL, create_node(5, NULL));
	insert_node(&a, NULL, create_node(2, NULL));
	insert_node(&a, NULL, create_node(1, NULL));
	printf("List a: \n");
	display(a);
	printf("\n");

	insert_node(&b, NULL, create_node(30, NULL));
	insert_node(&b, NULL, create_node(18, NULL));
	insert_node(&b, NULL, create_node(15, NULL));
	insert_node(&b, NULL, create_node(8, NULL));
	insert_node(&b, NULL, create_node(7, NULL));
	insert_node(&b, NULL, create_node(3, NULL));
	printf("List b: \n");
	display(b);
	printf("\n");

	c = concat(a, b);
	printf("List c: \n");
	display(c);
	printf("\n");

	printf("After ascending sort: \n");
	ascsort(c);
	display(c);

	return 0;
}
