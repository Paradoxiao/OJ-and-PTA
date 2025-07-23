#include <stdio.h>
#include <string.h>
typedef struct {
  int data[30][31];
  int m, n;
} matrix;
int delta[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void row_add(matrix *A, int from, int to);
void matrix_format(matrix *A);

int main() {
  int N;
  scanf("%d", &N);
  for (int puzzle = 1; puzzle <= N; puzzle++) {
    int turn[5][6];
    for (int i = 0; i < 5; i++)
      for (int l = 0; l < 6; l++)
        scanf("%d", &turn[i][l]);
    matrix A;
    A.m = 30;
    A.n = 30;
    memset(A.data, 0, sizeof(A.data));
    for (int i = 0; i < 5; i++) {
      for (int l = 0; l < 6; l++) {
        A.data[6 * i + l][30] = turn[i][l];
        for (int k = 0; k < 5; k++) {
          int x = i + delta[k][0], y = l + delta[k][1];
          if (x >= 0 && x < 5 && y >= 0 && y < 6)
            A.data[6 * i + l][6 * x + y] = 1;
        }
      }
    }
    matrix_format(&A);
    printf("PUZZLE #%d\n", puzzle);
    for (int i = 0; i < 5; i++) {
      for (int l = 0; l < 6; l++)
        printf(l ? " %d" : "%d", A.data[i * 6 + l][30]);
      putchar('\n');
    }
  }
  return 0;
}

void row_add(matrix *A, int from, int to) {
  if (A->data[to][from])
    for (int i = 0; i < A->n + 1; i++)
      A->data[to][i] ^= A->data[from][i];
}
void matrix_format(matrix *A) {
  for (int i = 0; i < A->m; i++) {
    if (!A->data[i][i]) {
      int temp = i;
      while (!A->data[++temp][i])
        ;
      row_add(A, temp, i);
    }
    for (int l = i + 1; l < A->m; l++)
      row_add(A, i, l);
  }
  for (int i = A->m - 1; i >= 0; i--)
    for (int l = i - 1; l >= 0; l--)
      row_add(A, i, l);
}