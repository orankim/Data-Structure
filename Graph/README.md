Graph
====================================================================

### Min heap.c

1) typedef struct element
-. purpose : int key를 정의한 구조체

2) typedef struct HeapType
-. purpose : Heap을 정의한 구조체

3) init
-. purpose : Heap 초기화
-. input : Heap

4) insert_min_heap
-. purpose : Heap에 노드 추가
-. input : heap, element

5) delete_min_heap
-. purpose : Heap에서 노드 삭제
-. input : heap
-. output : 삭제된 element

6) Decrease_key_min_heap
-. purpose : Heap에서 감소하는 키 갱신
-. input : heap, element

7) Increase_key_min_heap
-. purpose : Heap에서 증가하는 키 갱신
-. input : heap, element

8) print_heap
-. purpose : Heap 출력


### Prim.cpp

1) typedef struct ListNode
-. purpose : 목적지(dest), 가중치(weight), 다음 노드(next) 정의

2) typedef struct List
-. purpose : head노드 정의

3) typedef struct Graph
-. purpose : 그래프 구조 정의

4) newListNode
-. purpose : 새로운 ListNode 정의
-. input : dest, weight

5) createGraph
-. purpose : 그래프 생성
-. input : int V

6) addEdge
-. purpose : edge추가
-. input : Graph, int src, int dest, int weight

7) typedef struct HeapType
-. purpose : Heap 정의

8) typedef struct MinHeap
-. purpose : minheap 정의

9) newHeapType
-. purpose : minheap 새로운 노드 정의
-. input : int v, int key

10) createMinHeap
-. purpose : minheap 생성
-. input : int capacity

11) swapHeap
-. purpose : minheap의 두 노드를 swap
-. input : HeapType** a, b

12) min_heapify
-. purpose : min heap을 heapify
-. input : MinHeap* minHeap, int idx

13) isEmpty
-. purpose : MinHeap이 비어있는지 확인
-. input : MinHeap* minHeap

14) extractMin
-. purpose : Heap에서 가장 작은 노드 추출
-. input : MinHeap* minHeap
-. output : Heap에서 가장 작은 노드

15) decrease_key
-. purpose : decrease key 갱신
-. input : MinHeap* minheap, int v, int key

16) isinMinHeap
-. purpose : v가 minheap에 있는지 여부 확인
-. input : MinHeap* minHeap, int v
-. output : 참, 거짓

17) print_prim
-. purpose : 프림 알고리즘 결과 출력
-. input : int arr[], int n, int arr2[]

18) PrimMST
-. purpose : 프림 알고리즘을 이용해 MST 생성
-. input : Graph* graph
