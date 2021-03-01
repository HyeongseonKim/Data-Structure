#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 2147483647
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

void main(void)
{
    int i, n, m, k;
    int* list, clist;
    printf("Enter the number of numbers to generate: ");
    scanf_s("%d ", &n);

    if (n < 1)
    {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }

    MALLOC(list, n * sizeof(int));
    CALLOC(clist, n, sizeof(int));

    printf("Enter the number of numbers to realloc: ");
    scanf_s("%d", &n);

    REALLOC(clist, n);
}
