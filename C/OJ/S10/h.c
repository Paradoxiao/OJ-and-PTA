#include <stdio.h>
#define MAX_SIZE 150
int mul_matrix(int pr[][150], int m1[][150], int m2[][150], int m, int n,
               int q) {
  for (int i = 0; i < m; i++)
    for (int l = 0; l < q; l++) {
      pr[i][l] = 0;
      for (int k = 0; k < n; k++)
        pr[i][l] += m1[i][k] * m2[k][l];
    }
}
int put_matrix(int ma[][150], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf(j ? " %d" : "%d", ma[i][j]);
    }
    printf("\n");
  }
}
int get_matrix(int ma[][150], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &ma[i][j]);
    }
  }
}
int main() {
  int m, n, q;
  int product[MAX_SIZE][MAX_SIZE];
  int matrix1[MAX_SIZE][MAX_SIZE];
  int matrix2[MAX_SIZE][MAX_SIZE];

  scanf("%d%d%d", &m, &n, &q);
  get_matrix(matrix1, m, n);
  get_matrix(matrix2, n, q);
  mul_matrix(product, matrix1, matrix2, m, n, q);
  put_matrix(product, m, q);

  return 0;
}