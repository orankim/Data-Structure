Priority
====================================================================

### Build max heap.c

1) typedef struct element
-. key를 정의한 구조체

2) typedef struct HeapType
-. heap(element pointer), heap_size를 정의한 구조체

3) random
-. Purpose : 난수를 발생시키는 함수
-. Input : integer n
-. Output : 난수(integer)

4) init
-. Purpose : 힙 초기화
-. Input : 힙

5) insert_max_heap
-. Purpose : max heap에 삽입
-. Input : 힙, item

6) delete_max_heap
-. Purpose : max heap에서 삭제
-. Input : 힙
-. Output : 삭제된 item

7) max_heapify
-. Purpose : 힙이 max heap의 특성을 갖도록 함
-. Input : 힙, 사이즈, 사이즈 중간값

8) build_max_heap
-. Purpose : max heap 생성
-. Input : 힙, 사이즈

9) heap_sort
-. Purpose : 힙 정렬
-. Input : 힙, element, 사이즈

10) check_sort_results
-. Purpose : 정렬이 잘 되었는지 확인
-. Input : element, 사이즈
-. Output : 참, 거짓

### Huffman.c
1) type struct Node
-. 왼쪽, 오른쪽, 빈도수, 문자를 정의한 구조체

2) new_node
-. Purpose : 새로운 노드 생성
-. Input : 빈도수, 문자, 노드 a, b
-. Output : 새로운 노드 n

3) insert_queue
-. Purpose : 우선순위 큐에 새로운 노드 사입
-. Input : 노드 n

4) remove_queue
-. Purpose : 우선순위 큐에 노드 삭제
-. Output : 노드 n

5) build_code
-. Purpose : 트리 생성 및 0과 1 매김

6) init
-. Purpose : Huffman 트리 생성
-. Input : const char*

7) huffman_encode
-. Purpose : Huffman 인코딩
-. Input : const char*, char*

8) huffman_decode
-. Purpose : Huffman 디코딩
-. Input : const char*, node
