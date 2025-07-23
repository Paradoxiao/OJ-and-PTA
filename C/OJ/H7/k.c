#include <stdio.h>
int main() {
  freopen("out.txt", "w", stdout);
  int N, sum, n, nn, flag = 1;
  scanf("%d", &nn);
  while (nn--) {
    scanf("%d", &N);
    sum = 0;
    while (N--) {
      scanf("%d", &n);
      sum += n;
    }
    if (flag) {
      printf("%d\n", sum);
      flag = 0;
      continue;
    }
    printf("\n%d\n", sum);
  }
}
