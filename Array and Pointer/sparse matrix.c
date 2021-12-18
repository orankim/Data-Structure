#include <stdio.h>
#define ROWS 6
#define COLS 6
#define MAX_TERMS 7

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; //row size(dense matrix)
	int cols; //column size(dense matrix)
	int terms; //the number of non zero elements(dense matrix)
} SparseMatrix;

void printSparseMatrix(SparseMatrix a)
{
	for (int i = 0;i < a.terms;i++) printf("%d ,%d ,%d \n", a.data[i].row, a.data[i].col, a.data[i].value);
	printf("\n");
}

void printDenseMatrix(SparseMatrix a)
{
	int c[ROWS][COLS];
	int row, col;

	for (int i = 0;i <ROWS;i++) {
		for (int j = 0;j < COLS;j++) c[i][j] = 0;
	} //Make ROWS*COLS matrix full of zeroes

	for (int i = 0;i < a.terms;i++) {
		row = a.data[i].row;
		col = a.data[i].col;
		c[row][col] = a.data[i].value;
	} //Put values of sparse matrix
	
	for (int i = 0;i < ROWS;i++) {
		for (int j = 0;j < COLS;j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	} //Print ROWS*COLS matrix


}

struct SparseMatrix transposeMatrix(SparseMatrix a)
{
	struct SparseMatrix b;
	int index;
	b.rows = a.rows; //copy a rows to b
	b.cols = a.cols; //copy a cols to b
	b.terms = a.terms; //copy a terms to b

	if (a.terms > 0) {
		index = 0;
		for (int i = 0;i < a.cols;i++) {
			for (int j = 0;j < a.terms;j++) {
				if (a.data[j].col == i) {
					b.data[index].row = a.data[j].col;
					b.data[index].col = a.data[j].row;
					b.data[index].value = a.data[j].value;
					index++;
				}
			}
		}
	}

	return b;
}

int main(void)
{
	SparseMatrix A = { {{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7}; //Put A as an input
	printf("Original Matrix :\n");
	printf("Sparse Matrix form : \n");
	printSparseMatrix(A); //print sparsematrix
	printf("\n");
	printf("Dense Matrix form : \n");
	printDenseMatrix(A); //print densematrix
	printf("\n");

	struct SparseMatrix B;
	B = transposeMatrix(A); //Perform the transpose operation
	printf("Transpose Matrix : \n");
	printf("Sparse Matrix form : \n");
	printSparseMatrix(B); //print sparsematrix
	printf("\n");
	printf("Dense Matrix form : \n");
	printDenseMatrix(B); //print densematrix
	printf("\n");

	return 0;
}