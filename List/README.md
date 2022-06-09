List
====================================================================

### Doubly linked list

1) typedef struct DlistNode
-. data(데이터 필드), llink(왼쪽 링크 필드), rlink(오른쪽 링크 필드)를 정의한 이중연결리스트 구조체

2) init
-. purpose :이중연결리스트를 초기화
-. input : head 노드

3) display
-. purpose : 이중연결리스트의 노드를 출력
-. input : head 노드

4) dinsert_node
-. purpose : 새로운 노드 삽입
-. input : before 노드, data값

5) dinsert_last_node
-. purpose : 이중연결리스트의 가장 마지막에 노드 삽입

### Merge and sort two linked list

1) typedef struct ListNode
-. data(데이터 필드), link(링크 필드)를 정의한 단순연결리스트 구조체

2) error
-. purpose : 메시지 출력
-. input : message

3) insert_node
-. purpose : 새로운 노드 삽입
-. input : head 노드(phead), 선행노드(p), 삽입할 노드(new_node)

4) display
-. purpose : 노드 출력
-. input : head 노드

5) concat
-. purpose : 단순연결리스트를 연결
-. input : 연결 대상 리스트의 head 노드 2개
-. output : 연결한 리스트의 head 노드

6) create_node
-. purpose : 노드를 동적으로 생성
-. input : 노드의 data값, link값
-. output : 새로운 노드

7) swap
-. purpose : 입력된 두 노드의 값을 swap
-. input : swap 대상 노드 2개

8) ascsort
-. purpose : 연결리스트의 값을 오름차순으로 정렬
-. input : 정렬할 연결리스트의 head 노드

### All functions in List ADT(add_first, add_last, delete_first, delete_last)

1) typedef
-. purpose : data(데이터 필드), link(링크 필드)를 정의 및 head 포인터, tail 포인터, 리스트 길이 정의

2) is_empty
-. purpose : 연결리스트가 비어있는지 여부 확인
-. input : head 노드
-. output : 비어있을 시 1, 그렇지 않을 시 0

3) get_length
-. purpose : 연결리스트의 길이 확인
-. input : head 노드
-. output : 리스트의 길이

4) error
-. purpose : 메시지 출력
-. input : message

5) get_node_at
-. purpose : 특정 위치 노드 반환
-. input : head 노드, 노드의 위치
-. output : 특정 위치의 노드

6) insert_node
-. purpose : 새로운 노드 삽입
-. input : head 노드(phead), 선행노드(p), 삽입할 노드(new_node)

7) add
-. purpose : 주어진 위치에 데이터 삽입
-. input : head 노드, 삽입 위치, 데이터

8) add_first, add_last
-. purpose : 리스트의 처음/마지막에 노드 삽입
-. input : head 노드, 데이터

9) remove_node
-. purpose : 특정 노드 삭제
-. input : head 노드, 선행 노드(p), 삭제할 노드

10) delete
-. purpose : 주어진 위치의 데이터 삭제
-. input : head 노드, 삭제 위치

11) delete_first, delete_last
-. purpose : 리스트의 가장 처음/마지막 노드 삭제
-. input : head 노드

12) get_entry
-. purpose : 주어진 위치에 해당하는 데이터 반환
-. input : head 노드, 위치
-. output : 입력 위치에 해당하는 데이터 반환

13) display
-. purpose : 리스트 출력
-. input : head 노드

14) is_in_list
-. purpose : 특정 데이터값 있는지 확인
-. input : head 노드, 찾을 데이터
-. output : 있는 경우 TRUE, 없는 경우 FALSE

15) init
-. purpose : 리스트 초기화
-. input : head 노드
