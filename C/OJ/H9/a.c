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
void matrixT(matrix *a) {
  for (int i = 0; i < a->n; i++) {
    for (int j = 0; j < a->m; j++)
      printf(j == 0 ? "%d" : " %d", a->data[j][i]);
    putchar('\n');
  }
}
int main() {
  int M;
  matrix a;
  scanf("%d", &M);
  while (M--) {
    scanf("%d %d", &a.m, &a.n);
    matrixin(&a);
    matrixT(&a);
    putchar('\n');
  }
  return 0;
}