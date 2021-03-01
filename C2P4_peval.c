#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 3
#define SWAP(a,b) a^=b;b^=a;a^=b;
#define SWAPING(x,y,t) ((t)=(x),(x)=(y), (y)=(t))
#define COMPARE(x,y) ((x) < (y) ? -1: (x) == (y) ? 0: 1)
#define MALLOC(p,s) \
  	if (!((p) = malloc(s))) {\
  		fprintf(stderr, "Insufficient memory");\
  		exit(EXIT_FAILURE); \
  	}
/* p는 포인터, n은 총 원소의 개수, s는 타입을 뜻한다.*/
#define CALLOC(p, n, s)\
    if (!((p) = calloc(n,s))) {\
      fprintf(stderr, "Insufficient memory");\
      exit(EXIT_FAILURE);\
    }
#define REALLOC(p, s)\
    if (!((p) = realloc(p,s))) {\
      fprintf(stderr, "Insufficient memory");\
      exit(EXIT_FAILURE);\
    }

void add(int** a, int** b, int** c, int rows, int cols);
int** make2dArray(int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);

void main(void)
{
    int i, j, n, m, k;
    int*** _3dmatrix  = (int***)malloc(sizeof(int**) * 3);
    printf("Enter the number of numbers  M x N matrix: ");
    scanf_s("%d %d", &m, &n);

    if (n < 1 && m < 1)
    {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 3; i++)
    {
        _3dmatrix[i] = make2dArray(m, n);
    }

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        { /*randomly generate numbers */
            _3dmatrix[0][i][j] = rand() % 100;
            _3dmatrix[1][i][j] = rand() % 100;
        }

    printf("\n");

    printMatrix(_3dmatrix[0], m, n);
    printf("\n");
    printMatrix(_3dmatrix[1], m, n);
    printf("\n");

    add(_3dmatrix[0], _3dmatrix[1],_3dmatrix[2], m, n);

    printMatrix(_3dmatrix[2], m, n);

}

int** make2dArray(int rows, int cols)
{/* create a two dimensional rows x cols array */
    int** x, i;

    /* get memory for row pointers */
    MALLOC(x, rows * sizeof(*x));

    /* get memory for each row */
    for (i = 0; i < rows; i++)
        MALLOC(x[i], cols * sizeof(**x));
    return x;
}


void add(int** a, int** b, int** c, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
