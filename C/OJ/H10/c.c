#include <stdio.h>

typedef struct {
  double data[55][55];
  int m, n;
} matrix;

void row_add(matrix *A, int from, int to, double times);
void matrix_in(matrix *A, int m, int n);
void matrix_out(matrix out);
void matrix_format(matrix *A);
void exchange(matrix *A, int m, int n);

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int M;
  scanf("%d", &M);
  while (M--) {
    int n;
    scanf("%d", &n);
    matrix a;
    matrix_in(&a, n, n);
    matrix_format(&a);
    for (int i = 1; i <= n; i++)
      printf("x%d=%.3lf\n", i, a.data[i][n + 1]);
    putchar('\n');
  }
  return 0;
}

void row_add(matrix *A, int from, int to, double times) {
  for (int i = 1; i <= A->n + 1; i++)
    A->data[to][i] += A->data[from][i] * times;
}
void matrix_in(matrix *A, int m, int n) {
  A->m = m;
  A->n = n;
  for (int i = 1; i <= m; i++)
    for (int l = 1; l <= n + 1; l++)
      scanf("%lf", &A->data[i][l]);
}
void matrix_format(matrix *A) {
  for (int i = 1; i <= A->m; i++) {
    if (!A->data[i][i]) {
      int temp = i;
      while (!A->data[++temp][i])
        ;
      row_add(A, temp, i, 1);
    }
    for (int l = i + 1; l <= A->n + 1; l++) {
      A->data[i][l] /= A->data[i][i];
    }
    A->data[i][i] = 1;
    for (int l = i + 1; l <= A->m; l++)
      row_add(A, i, l, -1 * A->data[l][i]);
  }
  for (int i = A->m; i; i--) {
    for (int l = i - 1; l; l--)
      row_add(A, i, l, -1 * A->data[l][i]);
  }
}
