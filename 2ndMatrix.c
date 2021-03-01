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

int** make2dArray(int rows, int cols)
{/* create a two dimensional rows x cols array */
  int **x, i;

  /* get memory for row pointers */
  MALLOC(x, rows * sizeof(*x));

  /* get memory for each row */
  for (i = 0; i < rows; i++)
    MALLOC(x[i], cols * sizeof(**x));
  return x;
}
