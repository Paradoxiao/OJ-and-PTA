#include <stdio.h>
#include <stdlib.h>
int input(int num[]) {
  int N, n = 0;
  while (1) {
    scanf("%d", &N);
    if (N == 0)
      break;
    num[n++] = N;
  }
  return n;
}
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int merge(int n1, int num1[], int n2, int num2[], int num3[]) {
  int count = 0;
  for (int i = 0; i < n1; i++) {
    int notfound = 1;
    for (int j = 0; j < count; j++)
      if (num3[j] == num1[i])
        notfound = 0;
    if (notfound)
      num3[count++] = num1[i];
  }
  for (int i = 0; i < n2; i++) {
    int notfound = 1;
    for (int j = 0; j < count; j++)
      if (num3[j] == num2[i])
        notfound = 0;
    if (notfound)
      num3[count++] = num2[i];
  }
  qsort(num3, count, sizeof(int), cmp);
  return count;
}
void output(int num[], int n) {
  for (int i = 0; i < n; i++)
    printf(i ? " %d" : "%d", num[i]);
}
int main() {
  int A[100], B[100], C[200];
  int m, n, k;
  m = input(A);
  n = input(B);
  k = merge(m, A, n, B, C);
  output(C, k);
  return 0;
}