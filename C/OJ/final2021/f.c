#include <stdio.h>
#include <stdlib.h>
int main() {
  int N, num[10][10] = {0}, p, q, r, s;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int l = 0; l < N; l++)
      scanf("%d", &num[i][l]);
  while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
    int sum = 0;
    for (int i = p; i <= r; i++) {
      for (int l = q; l <= s; l++) {
        sum += num[i][l];
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}