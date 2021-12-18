Array and Pointer
====================================================================
### sparse matrix.c

1. typedef
- typedef struct element : 항의 요소를 의미
- typedef struct SparseMatrix : element가 SparseMatrix의 data에 들어감

2. printSparseMatrix
- purpose : 전치행렬 형태로 출력
- Input : SparseMatrix
- output : SparseMatrix

3. printDenseMatrix
- purpose : 전치행렬을 입력받아 밀집행렬 형태로 출력
- Input : SparseMatrix
- output : DenseMatrix form of input SparseMatrix

4. transposeMatrix
- purpose : 전치행렬을 입력받아 그 행렬의 transpose 형태로 변환 후 return
- input : SparseMatrix
- output : transpose matrix of input SparseMatrix

### mem alloc 3D double.c

1. mem_alloc_3D_double
- purpose : double type의 배열에 대한 동적 할당 및 배열 원소 입력
- input : 배열 p[a][b][c]에서 a, b, c 값
- output : 3D 배열

2. addition_3D
- purpose : 두 3D배열의 합을 구함
- input : 합할 두 배열 및 배열 p[a][b][c]에서 a, b, c 값
- output : 결과 3D 배열

3. print_3D_double
- purpose : double type 배열 출력
- input : 3D 배열
- output : return 함수값은 존재하지 않고 값만 출력

4. deallocate_3D_double
- purpose : 동적 할당한 3D double type 배열 메모리 해제
- input : 3D 배열
- output : return 함수값은 존재하지 않고 메모리만 해제
