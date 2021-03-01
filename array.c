#define MAX_SIZE 100
float sum(float [], int);
float input[MAX_SIZE], answer;
void main(void)
{
  int i;
  for (i = 0; i < MAX_SIZE; i++)
    input[i] = i;
  answer = sum(input, MAX_SIZE);
  printf("The sum is: %f\n", answer);
}

float sum(float list[], int n)
{
  int i;
  float tempsum = 0;
  for (i = 0; i < n; i++)
    tempsum += list[i];
  return tempsum;
}

void print1(float *ptr, int rows)
{/* 포인터를 사용해서 1차원 배열을 출력 */
    int i;
    printf("Address Contents\n");
    for (i = 0; i < rows; i++)
      printf("%8u%5d\n", ptr+i, *(ptr+i));
    printf("\n");
}
