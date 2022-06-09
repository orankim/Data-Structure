#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListNode {
	int dest;
	int weight;
	ListNode* next;
}ListNode;

typedef struct List {
	ListNode* head;
}List;

typedef struct Graph {
	int V;
	List* array;
}Graph;

ListNode* newListNode(int dest, int weight) {
	ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int V) {
	Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct List*)malloc(V * sizeof(struct List));
	for (int i = 0;i < V;i++) graph->array[i].head = NULL;
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
	struct ListNode* newNode = newListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

typedef struct HeapType{
	int v;
	int key;
}HeapType;

typedef struct MinHeap {
	int size;
	int capacity;
	int* pos;
	struct HeapType** array;
}MinHeap;

HeapType* newHeapType(int v, int key)
{
	struct HeapType* HeapType = (struct HeapType*)malloc(sizeof(struct HeapType));
	HeapType->v = v;
	HeapType->key = key;
	return HeapType;
}

MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int*)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct HeapType**)malloc(capacity * sizeof(struct HeapType*));
	return minHeap;
}

void swapHeap(struct HeapType** a, struct HeapType** b)
{
	struct HeapType* t = *a;
	*a = *b;
	*b = t;
}

void min_heapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
		smallest = right;

	if (smallest != idx) {
		HeapType* smallestNode = minHeap->array[smallest];
		HeapType* idxNode = minHeap->array[idx];

		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapHeap(&minHeap->array[smallest], &minHeap->array[idx]);

		min_heapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

HeapType* extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	struct HeapType* root = minHeap->array[0];

	struct HeapType* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	--minHeap->size;
	min_heapify(minHeap, 0);

	return root;
}

void decrease_key(struct MinHeap* minHeap, int v, int key)
{
	int i = minHeap->pos[v];

	minHeap->array[i]->key = key;

	while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapHeap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

bool isInMinHeap(struct MinHeap* minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void print_prim(int arr[], int n,int arr2[]) {
	for (int i = 1; i < n; ++i) printf("Vertex %d -> %d	edge: %d\n", arr[i], i,arr2[i]);
}

void PrimMST(struct Graph* graph)
{
	int V = graph->V;
	int* parent = (int*)malloc(sizeof(int) * V);
	int* key = (int*)malloc(sizeof(int) * V);
	int* edge= (int*)malloc(sizeof(int) * V);
	struct MinHeap* minHeap = createMinHeap(V);

	for (int v = 1; v < V; ++v) {
		parent[v] = -1;
		key[v] = INT_MAX;
		minHeap->array[v] = newHeapType(v, key[v]);
		minHeap->pos[v] = v;
	}
	key[0] = 0;
	minHeap->array[0] = newHeapType(0, key[0]);
	minHeap->pos[0] = 0;
	minHeap->size = V;
	while (!isEmpty(minHeap)) {
		struct HeapType* HeapType = extractMin(minHeap);
		int u = HeapType->v;

		struct ListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL) {
			int v = pCrawl->dest;
			if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) {
				key[v] = pCrawl->weight;
				parent[v] = u;
				decrease_key(minHeap, v, key[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	print_prim(parent, V,key);
}

int main()
{
	int V = 8;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1, 3);
	addEdge(graph, 2, 4, 2);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 2, 3, 15);
	addEdge(graph, 4, 7, 5);
	addEdge(graph, 4, 5, 9);
	addEdge(graph, 4, 6, 4);

	PrimMST(graph);

	return 0;
}