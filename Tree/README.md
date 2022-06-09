Tree
====================================================================

### Successor in the inorder traversal.c

1) typedef struct TreeNode
-. data(데이터 필드), left(왼쪽 자식 노드), right(오른쪽 자식 노드), parent(부모 노드)를 정의한 이중연결리스트 구조체

2) tree_successor
-. purpose : 입력된 노드의 successor 찾기
-. input : 트리 노드 p
-. output : p의 successor

### Predecessor in the inorder traversal.c

1) typedef struct TreeNode
-. data(데이터 필드), left(왼쪽 자식 노드), right(오른쪽 자식 노드), parent(부모 노드)를 정의한 이중연결리스트 구조체

2) tree_predecessor
-. purpose : 입력된 노드의 predecessor 찾기
-. input : 트리 노드 p
-. output : p의 predecessor

### Predecessor at the left subtree.c

1) typedef struct TreeNode
-. key(데이터 필드), left(왼쪽 자식 노드), right(오른쪽 자식 노드)를 정의한 이중연결리스트 구조체

2) insert_node
-. purpose : 새로운 노드 삽입
-. input : 루트 노드, 삽입할 key

3) delete_node
-. purpose : 노드 삭제
-. input : 루트 노드, 삭제할 key

4) inorder
-. purpose : 트리 순회
-. input : 루트 노드


