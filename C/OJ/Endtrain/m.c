#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);
  int **sum = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    sum[i] = malloc((i + 1) * sizeof(int));
    for (int l = 0; l <= i; l++)
      scanf("%d", &sum[i][l]);
  }
  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      sum[i][j] +=
          sum[i + 1][j] > sum[i + 1][j + 1] ? sum[i + 1][j] : sum[i + 1][j + 1];
  printf("%d", sum[0][0]);
  return 0;
}