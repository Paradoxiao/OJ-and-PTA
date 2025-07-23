#include <stdio.h>
typedef struct {
  int data[101][101];
  int m, n;
} matrix;
void matrixin(matrix *a) {
  for (int i = 0; i < a->m; i++)
    for (int j = 0; j < a->n; j++)
      scanf("%d", &a->data[i][j]);
}
int matrixout(matrix *a, matrix *b) {
  if (a->m != b->m || a->n != b->n) {
    return 1;
  }
  for (int i = 0; i < a->m; i++) {
    for (int j = 0; j < a->n; j++)
      printf(j == 0 ? "%d" : " %d", a->data[i][j] + b->data[i][j]);
    putchar('\n');
  }
  return 0;
}
int main() {
  int count = 0, m, n;
  matrix a, b;
  scanf("%d %d", &m, &n);
  while (m && n) {
    count++;
    if (count % 2) {
      a.m = m;
      a.n = n;
      matrixin(&a);
    } else {
      b.m = m;
      b.n = n;
      matrixin(&b);
    }
    if (!(count % 2)) {
      if (matrixout(&a, &b))
        puts("Not satisfied the definition of matrix addition!");
      putchar('\n');
    }
    scanf("%d %d", &m, &n);
  }
  return 0;
}