#include <stdio.h>
#include <stdlib.h>

double*** mem_alloc_3D_double(int a, int b, int c)
{
    double* array = (double*)malloc(a * b * c * sizeof(double));
    double** pp = (double**)malloc(a * b * sizeof(double*));
    double*** p = (double***)malloc(a * sizeof(double**));

    if (array == NULL || p == NULL || pp == NULL)
        return NULL;

    for (int i = 0; i < a * b; i++)
    {
        pp[i] = array;
        array += c;
    }

    for (int i = 0; i < a; i++)
    {
        p[i] = &pp[i * b];
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                p[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }
    return p;
    
}

double*** addition_3D(double*** A, double*** B, int a, int b, int c)
{
    double* array = (double*)malloc(a * b * c * sizeof(double));
    double** pp = (double**)malloc(a * b * sizeof(double*));
    double*** p = (double***)malloc(a * sizeof(double*));

    if (array == NULL || p == NULL || pp == NULL)
        return NULL;

    double* ptr2 = array;
    for (int i = 0; i < a * b; i++)
    {
        pp[i] = ptr2;
        ptr2 += c;
    }

    for (int i = 0; i < a; i++)
    {
        p[i] = &pp[i * b];
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                p[i][j][k] = A[i][j][k]+ B[i][j][k];
            }
        }
    }
    return p;
}

void print_3D_double(double*** p, int a, int b, int c)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                printf("%8.2f ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

}

void deallocate_3D_double(double*** p)
{
    free(**p);
    free(*p);
    free(p);
}

int main()
{
    double*** A = mem_alloc_3D_double(2, 3, 4);
    double*** B = mem_alloc_3D_double(2, 3, 4);
    double*** C = addition_3D(A, B, 2, 3, 4);

    if (A == NULL)
        return 0;

    printf("3D array A :\n");
    print_3D_double(A, 2, 3, 4);
    printf("\n");
    printf("3D array B :\n");
    print_3D_double(B, 2, 3, 4);
    printf("\n");
    printf("3D array A+B :\n");
    print_3D_double(C, 2, 3, 4);
    printf("\n");

    deallocate_3D_double(A);
    deallocate_3D_double(B);
    deallocate_3D_double(C);

    return 0;
}