#include <stdio.h>
int prev_sum(int b[], int a[], int n) {
  for (int i = 0; i <= n; i++) {
    b[i] = 0;
    for (int l = 0; l <= i; l++)
      b[i] += a[l];
  }
}
int main() {
  int n, i;
  int a[1000], sum[1000];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  prev_sum(sum, a, n);

  printf("%d", sum[0]);
  for (i = 1; i < n; i++)
    printf(" %d", sum[i]);
  printf("\n");
}
