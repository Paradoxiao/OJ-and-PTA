#include <stdio.h>
#define ElementType int
#define MAXN 100
void merge_pass(ElementType list[], ElementType sorted[], int N, int length);
void output(ElementType list[], int N) {
  int i;
  for (i = 0; i < N; i++)
    printf("%d ", list[i]);
  printf("\n");
}
void merge_sort(ElementType list[], int N) {
  ElementType extra[MAXN]; /* the extra space required */
  int length = 1;          /* current length of sublist being merged */
  while (length < N) {
    merge_pass(list, extra, N, length); /* merge list into extra */
    output(extra, N);
    length *= 2;
    merge_pass(extra, list, N, length); /* merge extra back to list */
    output(list, N);
    length *= 2;
  }
}
int main() {
  int N, i;
  ElementType A[MAXN];

  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%d", &A[i]);
  merge_sort(A, N);
  output(A, N);

  return 0;
}

/* Your function will be put here */
void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
  for (int l = 0; l < N; l += length * 2) {
    int *i = list + l, *j = list + length + l, *k = sorted + l;
    while (i < list + length + l && j < list + length * 2 + l && j < list + N)
      if (*i < *j)
        *(k++) = *(i++);
      else
        *(k++) = *(j++);
    while (i < list + length + l)
      *(k++) = *(i++);
    while (j < list + length * 2 + l && j < list + N)
      *(k++) = *(j++);
  }
}
