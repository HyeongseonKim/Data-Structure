#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int** make2dArray(int rows, int cols);
void print2(int** ptr, int rows, int cols);

void main(void)
{
    int n, m;
    int** list;
    printf("Enter the number of numbers to generate M x N matrix: ");
    scanf_s(" %d %d", &m, &n);

    list = make2dArray(m, n);

    print2(list, m, n);
}


int** make2dArray(int rows, int cols)
{/* create a two dimensional rows x cols array */
    int** x, i;

    /* get memory for row pointers */
    CALLOC(x, rows, sizeof(*x));

    /* get memory for each row */
    for (i = 0; i < rows; i++)
        CALLOC(x[i], cols, sizeof(**x));
    return x;
}

void print2(int** ptr, int rows, int cols)
{/* 포인터를 사용해서 2차원 배열을 출력 */
    int i, j;
    printf("Address Contents\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            printf("%8d %5d\n", ptr[i] +j + j, *(ptr[i] + j));
}
