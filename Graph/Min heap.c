#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 2000
typedef struct element {
	int key;
} element;

typedef struct {
	element* heap;
	int heap_size;
} HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	// The process of comparing with the parent node as it traverses the tree
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // Insert new node
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void Decrease_key_min_heap(HeapType* h, element item) {
	int i, temp;
	i = ++(h->heap_size);
	if (item.key >= h->heap[i].key) printf("New key is smaller than current key\n");
	h->heap[i].key = item.key;
	while ((i > 1) && (h->heap[i / 2].key > h->heap[i].key)) {
		temp = h->heap[i / 2].key;
		h->heap[i / 2].key = h->heap[i].key;
		h->heap[i].key = temp;
		i = i / 2;
	}
}

void Increase_key_min_heap(HeapType* h, element item) {
	int i,temp;
	i = ++(h->heap_size);
	if (item.key <= h->heap[i].key) printf("New key is not larger than current key\n");
	h->heap[i].key = item.key;
	while ((i > 1) && (h->heap[i / 2].key >= item.key)) {
		temp = h->heap[i / 2].key;
		h->heap[i / 2].key = h->heap[i].key;
		h->heap[i].key = temp;
		i = i / 2;
	}
}

void print_heap(HeapType* h) {
	for (int i = 0; i < h->heap_size; i++)	printf("%d\n", h->heap[i + 1].key);
	printf("\n");
}

void main() {
	int input_size = 10;
	HeapType* h1 = (HeapType*)malloc(sizeof(HeapType));
	h1->heap = (element*)malloc(sizeof(element) * (input_size + 1));
	element e1 = { 1 }, e2 = { 5 }, e3 = { 3 }, e4 = { 7 }, e5 = { 4 }, e6 = { 2 }, e7 = { 3 }, e8 = { 7 },e9 = { 8},e10 = { 9 };
	element e11 = { 6 }, e12 = { 10 };
	init(h1);
	insert_min_heap(h1, e1);
	insert_min_heap(h1, e2);
	insert_min_heap(h1, e3);
	insert_min_heap(h1, e4);
	insert_min_heap(h1, e5);
	insert_min_heap(h1, e6);
	insert_min_heap(h1, e7);
	insert_min_heap(h1, e8);
	insert_min_heap(h1, e9);
	insert_min_heap(h1, e10);
	printf("Original Heap: \n");
	print_heap(h1);
	printf("\n");
	printf("Decrease key: \n");
	Decrease_key_min_heap(h1,e11);
	print_heap(h1);
	printf("\n");
	//printf("Increase key: \n");
	//Increase_key_min_heap(h1, e11);
	//print_heap(h1);
}

