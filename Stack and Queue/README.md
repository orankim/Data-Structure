

### Circular doubly linked list.c

1) typedef struct DlistNode
-. data(데이터 필드), llink(왼쪽 링크 필드), rlink(오른쪽 링크 필드)를 정의한 이중연결리스트 구조체

2) typedef struct LinkedStackType
-. DlistNode top을 정의한 스택 구조체

3) init
-. purpose : 스택을 초기화
-. input :  스택 s

4) is_empty
-. purpose : 스택이 비어있는지 여부를 확인
-. input : 스택 s
-. output : TRUE, FALSE

5) push
-. purpose : 스택에 새 item 삽입
-. input : 스택 s, 삽입할 item

6) pop
-. purpose : 스택의 top에 있는 item 반환 및 top 위치 node 삭제
-. input : 스택 s
-. output : top위치에 있던 item

7) peek
-. purpose : 스택의 top에 있는 item 반환
-. input : 스택 s
-. output : top위치에 있던 item

### Simulation.c

1) typedef struct element
-. purpose : 고객 정보 저장(int id, arrival_time, service_time)

2) typedef struct QueueType
-. purpose : 1)에서 정의한 고객 정보를 queue 형태로 정의한 구조체

3) random
-. purpose : 0에서 1사이의 실수 형태의 난수 생성

4) is_empty
-. purpose : 큐가 비어있는지 여부를 확인
-. input : 큐 q
-. output : TRUE, FALSE

5) is_full
-. purpose : 큐가 꽉차있는지 여부를 확인
-. input : 큐 q
-. output : TRUE, FALSE

6) enqueue
-. purpose : 큐에 item 삽입
-. input : 큐 q, element형 item

7) dequeue
-. purpose : 큐에서 item 삭제
-. input : 큐 q
-. output : 삭제한 데이터 반환

8) insert_customer
-. purpose : 큐에 새로운 고객 정보 삽입
-. input : arrival_time

9) remove_customer
-. purpose : 큐에서 기다리고 있는 고객의 서비스 시간 반환
-. output : service_time

10) print_stat
-. purpose : 통계치 출력

