#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inmatrix(int a[105][105], int m, int n) {
  for (int i = 0; i < m; i++)
    for (int l = 0; l < n; l++)
      scanf("%d", &a[i][l]);
}
void outmatrix(int a[105][105], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int l = 0; l < n; l++)
      printf(!l ? "%d" : " %d", a[i][l]);
    printf("\n");
  }
  printf("\n");
}
int mulmatrix(int a[105][105], int b[105][105], int m1, int n1, int m2, int n2,
              int c[105][105], int *m3, int *n3) {
  if (n1 != m2)
    return 0;
  for (int i = 0; i < m1; i++)
    for (int l = 0; l < n2; l++) {
      c[i][l] = 0;
      for (int k = 0; k < n1; k++)
        c[i][l] += a[i][k] * b[k][l];
    }
  *m3 = m1;
  *n3 = n2;
  return 1;
}
void copymatrix(int to[105][105], int from[105][105], int m, int n, int *m1,
                int *n1) {
  for (int i = 0; i < m; i++)
    for (int l = 0; l < n; l++)
      to[i][l] = from[i][l];
  *m1 = m;
  *n1 = n;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int matrix1[105][105], matrix2[105][105], result[105][105];
  int m1, n1, m2, n2, m, n;
  scanf("%d %d", &m1, &n1);
  inmatrix(matrix1, m1, n1);
  scanf("%d %d", &m2, &n2);
  inmatrix(matrix2, m2, n2);
  mulmatrix(matrix1, matrix2, m1, n1, m2, n2, result, &m, &n);
  outmatrix(result, m, n);
  scanf("%d %d", &m1, &n1);
  while (m1 || n1) {
    inmatrix(matrix1, m1, n1);
    if (mulmatrix(result, matrix1, m, n, m1, n1, matrix2, &m2, &n2)) {
      outmatrix(matrix2, m2, n2);
      copymatrix(result, matrix2, m2, n2, &m, &n);
    } else {
      puts("Not satisfied the definition of matrix multiplication!");
      copymatrix(result, matrix1, m1, n1, &m, &n);
    }
    scanf("%d %d", &m1, &n1);
  }
  return 0;
}